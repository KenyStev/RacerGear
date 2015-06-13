#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

#include "Rosalila/system.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
//#include <List>
#include <iostream>
using namespace std;

//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"

#ifdef LINUX
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif

#ifdef WINDOWS
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif

#ifdef OSX
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#endif

#include "ListImage.h"
#include "Car.h"
#include <math.h>

int main(int argc, char *argv[])
{
    //Clean the previous log
    clearLog();

    //OpenGL initialization
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

    //Input receiver initialization
    Receiver* receiver = new Receiver();

    //Graphics initialization
    RosalilaGraphics* rosalila_graphics = new RosalilaGraphics();
    rosalila_graphics->video(rosalila_graphics);

    //Sound initialization
    Sound*sound = new Sound();
    sound->addSound("sonido",assets_directory+"sound.ogg");

    ListImage *MyList = new ListImage(rosalila_graphics);
    ListImage *MyList2 = new ListImage(rosalila_graphics);
    MyList->add(assets_directory+"rect2.png");
    for(int i=1; i<90; i++)
        MyList->add(assets_directory+"rect.png");
    for(int i=0; i<8; i++)
        MyList2->add(assets_directory+"flags.png");

    Car *car = new Car(rosalila_graphics);
    for(int i=0; i<10; i++)
    {
        MyList->flush(5*110);
        MyList2->flush(5*112);
    }

    double off_set_y=0, off_set_x;
    while(true)
    {

        if(receiver->isKeyDown(SDL_SCANCODE_UP))
            off_set_y=20.5;
        else if(receiver->isKeyDown(SDL_SCANCODE_DOWN))
            off_set_y=-10.5;
        else
            off_set_y=0;

        if(receiver->isKeyDown(SDL_SCANCODE_RIGHT))
            off_set_x=-10.5;
        else if(receiver->isKeyDown(SDL_SCANCODE_LEFT))
            off_set_x=10.5;
        else
            off_set_x=0;

        MyList->draw(off_set_x, off_set_y);
        MyList2->draw(off_set_x, off_set_y);
        car->draw(rosalila_graphics);
        if(receiver->isKeyDown(SDLK_ESCAPE))
            break;

        receiver->updateInputs();
        rosalila_graphics->updateScreen();
    }

    return 0;
}
