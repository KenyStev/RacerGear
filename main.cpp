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
    for(int i=0; i<10; i++)
        MyList->add(assets_directory+"rect.png");
    for(int i=0; i<10; i++)
        MyList2->add(assets_directory+"flags.png");

    //Texture load
    Image *image=rosalila_graphics->getTexture(assets_directory+"image.png");
//    Image *image2=rosalila_graphics->getTexture(assets_directory+"rect.png");
//    Image *image3=rosalila_graphics->getTexture(assets_directory+"rect.png");
//    Image *image4=rosalila_graphics->getTexture(assets_directory+"rect.png");
//    Image *image5=rosalila_graphics->getTexture(assets_directory+"rect.png");

    float x=rosalila_graphics->screen_width*0.5;
    float y=rosalila_graphics->screen_height;
    float scale=1;
    float rotation=0;
    bool horizontal_flip=false;
    int red_effect=255;
    int green_effect=255;
    int blue_effect=255;
    int alpha_effect=255;
    bool red_effect_activated=false;
    bool green_effect_activated=false;
    bool blue_effect_activated=false;
    bool alpha_effect_activated=false;

    bool first = true;
    float off_set=0;
    while(true)
    {
    //Inicio Prueba Scale
        //img-1
        /*float x1, y1, scale1;
        if(first)
        {
            scale1 = 1;
            x1 = x - image1->getWidth()*0.5;
            y1 = y - image1->getHeight();
        }
        rosalila_graphics->draw2DImage
        (   image1,
            image1->getWidth(),image1->getHeight(),
            x1,y1,
            scale,
            rotation,
            horizontal_flip,
            0,0,
            Color(red_effect,green_effect,blue_effect,alpha_effect),
            0,0,
            false);
        //img-2
        float x2, y2, scale2;
        if(first)
        {
            scale2 = 0.66;
            x2 = x - image2->getWidth()*0.5*scale2;
            y2 = y1 - image2->getHeight()*scale2;
        }
        rosalila_graphics->draw2DImage
        (   image2,
            image2->getWidth(),image2->getHeight(),
            x2,y2,
            scale2,
            rotation,
            horizontal_flip,
            0,0,
            Color(red_effect,green_effect,blue_effect,alpha_effect),
            0,0,
            false);
        //img-3
        float x3, y3, scale3;
        if(first)
        {
            scale3 = 0.44;
            x3 = x - image3->getWidth()*0.5*scale3;
            y3 = y2 - image3->getHeight()*scale3;
        }
        rosalila_graphics->draw2DImage
        (   image3,
            image3->getWidth(),image3->getHeight(),
            x3,y3,
            scale3,
            rotation,
            horizontal_flip,
            0,0,
            Color(red_effect,green_effect,blue_effect,alpha_effect),
            0,0,
            false);
        //img-4
        float x4, y4, scale4;
        if(first)
        {
            scale4 = 0.29;
            x4 = x - image4->getWidth()*0.5*scale4;
            y4 = y3 - image4->getHeight()*scale4;
        }
        rosalila_graphics->draw2DImage
        (   image4,
            image4->getWidth(),image4->getHeight(),
            x4,y4,
            scale4,
            rotation,
            horizontal_flip,
            0,0,
            Color(red_effect,green_effect,blue_effect,alpha_effect),
            0,0,
            false);
        //img-5
        float x5, y5, scale5;
        if(first)
        {
            scale5 = 0.19;
            x5 = x - image5->getWidth()*0.5*scale5;
            y5 = y4 - image5->getHeight()*scale5;
        }
        rosalila_graphics->draw2DImage
        (   image5,
            image5->getWidth(),image5->getHeight(),
            x5,y5,
            scale5,
            rotation,
            horizontal_flip,
            0,0,
            Color(red_effect,green_effect,blue_effect,alpha_effect),
            0,0,
            false);
            first=false;
    //Fin Prueba Scale
*/

        if(receiver->isKeyDown(SDL_SCANCODE_UP))
            off_set+=1.0;
//        else
//            off_set-=1.0;

        MyList->draw(off_set);
        MyList2->draw(off_set);
        if(receiver->isKeyDown(SDLK_ESCAPE))
            break;

        if(receiver->isKeyDown(SDL_SCANCODE_UP))
            y-=0.5;
        if(receiver->isKeyDown(SDL_SCANCODE_DOWN))
            y+=0.5;
        if(receiver->isKeyDown(SDL_SCANCODE_LEFT))
            x-=0.5;
        if(receiver->isKeyDown(SDL_SCANCODE_RIGHT))
            x+=0.5;

        if(receiver->isKeyDown('r'))
            rotation+=0.5;

        if(receiver->isKeyDown('s'))
            scale+=0.01;

        if(receiver->isKeyDown('t'))
            rotation-=0.5;

        if(receiver->isKeyDown('d'))
            scale-=0.01;

        if(receiver->isKeyDown('h'))
            horizontal_flip=true;
        else
            horizontal_flip=false;


        if(receiver->isKeyPressed(SDLK_SPACE))
            sound->playSound("sonido");

        if(receiver->isKeyDown('1'))
        {
            red_effect+=10;
            if(red_effect>255)
                red_effect=0;
        }else
        {
            red_effect=255;
        }

        if(receiver->isKeyDown('2'))
        {
            green_effect+=10;
            if(green_effect>255)
                green_effect=0;
        }else
        {
            green_effect=255;
        }

        if(receiver->isKeyDown('3'))
        {
            blue_effect+=10;
            if(blue_effect>255)
                blue_effect=0;
        }else
        {
            blue_effect=255;
        }

        if(receiver->isKeyDown('4'))
        {
            alpha_effect+=10;
            if(alpha_effect>255)
                alpha_effect=0;
        }else
        {
            alpha_effect=255;
        }

        receiver->updateInputs();
        rosalila_graphics->updateScreen();
    }


    return 0;
}
