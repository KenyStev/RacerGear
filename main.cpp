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
    for(int i=0; i<30; i++)
        MyList->add(assets_directory+"rect.png");
    for(int i=0; i<8; i++)
        MyList2->add(assets_directory+"flags.png");

    for(int i=0; i<30; i++)
    {
        MyList->flush(100);
        MyList2->flush(100);
    }

    //Texture load
//    Image *image=rosalila_graphics->getTexture(assets_directory+"image.png");
//
//    float x=rosalila_graphics->screen_width*0.5;
//    float y=rosalila_graphics->screen_height;
//    float scale=1;
//    float rotation=0;
//    bool horizontal_flip=false;
//    int red_effect=255;
//    int green_effect=255;
//    int blue_effect=255;
//    int alpha_effect=255;
//    bool red_effect_activated=false;
//    bool green_effect_activated=false;
//    bool blue_effect_activated=false;
//    bool alpha_effect_activated=false;
//
//    bool first = true;
    float off_set=0;
    while(true)
    {

        if(receiver->isKeyDown(SDL_SCANCODE_UP))
            off_set=10.5;
        else if(receiver->isKeyDown(SDL_SCANCODE_DOWN))
            off_set=-10.5;
        else
            off_set=0;

        MyList->draw(off_set);
        MyList2->draw(off_set);
        if(receiver->isKeyDown(SDLK_ESCAPE))
            break;

        receiver->updateInputs();
        rosalila_graphics->updateScreen();
    }


    return 0;
}
