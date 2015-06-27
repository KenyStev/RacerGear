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

//#include "Pista.h"
//#include "ListImage.h"
//#include "Car.h"
//#include <math.h>
//#include "Button.h"
//#include "PlayButton.h"
//#include "InstrButton.h"
//#include "RankButton.h"
//#include "ExitButton.h"
//#include "BackButton.h"
//#include<list>
//#include "Scores.h"

#include "RaceGear.h"

//class MenuScreen{
//public:
//Image* fondo,*pu,*pd,*iu,*id,*ru,*rd,*eu,*ed;
//PlayButton *Pb;
//InstrButton *Ib;
//RankButton *Rb;
//ExitButton *Eb;
//Receiver* input;
//int mouse_x, mouse_y;
//bool click;
//RosalilaGraphics* painter;
//int centro_x,centro_y;
//
//    MenuScreen(RosalilaGraphics* painter, Receiver *receiver){
//        this->painter = painter;
//        input = receiver;
//        //Fondo init
//        fondo= painter->getTexture(assets_directory+"Menu.png");
//        //Play button init
//        pu = painter->getTexture(assets_directory+"PLAY_UP.png");
//        pd = painter->getTexture(assets_directory+"PLAY_DWN.png");
//        centro_x=painter->screen_width/2-(pu->getWidth()/2);
//        centro_y=painter->screen_height/2-(pu->getHeight()/2);
//        Pb = new PlayButton(centro_x,centro_y-100,pu,pd,painter,input);
//        //Instrctions Button init
//        iu = painter->getTexture(assets_directory+"INSTR_UP.png");
//        id = painter->getTexture(assets_directory+"INSTR_DWN.png");
//        centro_x=painter->screen_width/2-(iu->getWidth()/2);
//        centro_y=painter->screen_height/2-(iu->getHeight()/2);
//        Ib = new InstrButton(centro_x,centro_y,iu,id,painter);
//        //Ranking Button init
//        ru = painter->getTexture(assets_directory+"RANK_UP.png");
//        rd = painter->getTexture(assets_directory+"RANK_DWN.png");
//        centro_x=painter->screen_width/2-(ru->getWidth()/2);
//        centro_y=painter->screen_height/2-(ru->getHeight()/2);
//        Rb = new RankButton(centro_x,centro_y+100,ru,rd,painter);
//        //Exit Button init
//        eu = painter->getTexture(assets_directory+"EXIT_UP.png");
//        ed = painter->getTexture(assets_directory+"EXIT_DWN.png");
//        centro_x=painter->screen_width/2-(eu->getWidth()/2);
//        centro_y=painter->screen_height/2-(eu->getHeight()/2);
//        Eb = new ExitButton(centro_x,centro_y+200,eu,ed,painter);
//        mouse_x=0;
//        mouse_y=0;
//        click=false;
//
//    }
//
//    void act(){
//        painter->draw2DImage(fondo,fondo->getWidth(),fondo->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
//        mouse_x = input->getMouse_X();
//        mouse_y = input->getMouse_Y();
//        click = input->isLeftClickDown();
//         Pb->draw(mouse_x,mouse_y,click);
//         Ib->draw(mouse_x,mouse_y,click);
//         Rb->draw(mouse_x,mouse_y,click);
//         Eb->draw(mouse_x,mouse_y,click);
//
//    }
//    void update(){
//        mouse_x = input->getMouse_X();
//        mouse_y = input->getMouse_Y();
//        click = input->isLeftClickDown();
//        Pb->update(mouse_x,mouse_y,click);
//        Ib->update(mouse_x,mouse_y,click);
//        Rb->update(mouse_x,mouse_y,click);
//        Eb->update(mouse_x,mouse_y,click);
//    }
//
//};

int main(int argc, char *argv[])
{

    //Clean the previous log
    clearLog();

    //OpenGL initialization
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
/*probando Game.h
    //Input receiver initialization
    Receiver* receiver = new Receiver();

    //Graphics initialization
    RosalilaGraphics* rosalila_graphics = new RosalilaGraphics();
    rosalila_graphics->video(rosalila_graphics);

    //Sound initialization
    Sound*sound = new Sound();
    sound->addSound("sonido",assets_directory+"sound.ogg");
    MenuScreen* menu_screen = new MenuScreen(rosalila_graphics,receiver);*/

    //TiXml
//    TiXmlDocument doc("assets/cars.xml");
//    doc.LoadFile();
//    TiXmlNode *cars = doc.FirstChild("Cars");
//    TiXmlNode* car=cars->FirstChild("car");
//
//    for(TiXmlNode* car=cars->FirstChild("car");
//        car!=NULL;
//        car=car->NextSibling("car"))
//        {
//            cout<<atof(car->ToElement()->Attribute("velocity"))<<"       "<<atof(car->ToElement()->Attribute("aceleration"))<<endl;
//        }

//    TiXmlDocument doc((assets_directory+"pista_1.xml").c_str());
//    doc.LoadFile();
//    TiXmlNode *track = doc.FirstChild("Track");
//    TiXmlNode* step=track->FirstChild("step");
//
//    for(TiXmlNode* step=track->FirstChild("step");
//        step!=NULL;
//        step=step->NextSibling("step"))
//        {
//            cout<<step->ToElement()->Attribute("path")<<endl;
//        }
    //exit(11);

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
    //scr->createNewUserBinary("Juan");
//    scr->createNewUserBinary("Luis");
   scr->readFileBinary(race_game->rosalila_graphics);
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
