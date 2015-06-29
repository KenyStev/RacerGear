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

#include "RaceGear.h"

int main(int argc, char *argv[])
{

    //Clean the previous log
    clearLog();

    //OpenGL initialization
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

    RaceGear *race_game = new RaceGear();
    race_game->create();
    Scores *scr = new Scores();
//    scr->initFStream();
//    if(scr->createNewUser("Luis"))
//        cout<<"--------------------------------------Creo nuevo user"<<endl;
//
//    //scr->setPuntosToPista("Luis",10,1);
//
//    if(!scr->readFile()){
//        cout<<"--------------------------------------Error Al Leer"<<endl;
//    }
////    if(scr->createNewUser("Mario"))
////        cout<<"--------------------------------------Creo nuevo user"<<endl;
////    //scr->setPuntosToPista("Luis",10,1);
////    //cout<<"--------------------Nuevo read";
////    cout<<'\n';
////    if(!scr->readFile()){
////        cout<<"--------------------------------------Error Al Leer"<<endl;
////    }
//    scr->closeFStream();

    //BINARIO
    //scr->initFStreamBinary();
    //scr->createNewUserBinary("Raton");
//    scr->createNewUserBinary("Thomas");
//      scr->readFileBinary();
//      scr->printMap();
//    cout<<scr->seekUser("Mario");
//    scr->setPuntosToPista("Juan",8,1);
//    scr->setPuntosToPista("Juan",10,2);
//    scr->setPuntosToPista("Juan",30,3);
//    scr->setPuntosToPista("Juan",15,4);

    //scr->readFileBinary();
    //scr->closeFStreamBinary();
    while(true)
    {

//        if(receiver->isKeyDown(SDLK_ESCAPE))
//            exit(0);
//        menu_screen->act();
//        menu_screen->update();
//        receiver->updateInputs();
//        rosalila_graphics->updateScreen();
        race_game->render();
    }

    return 0;
}
