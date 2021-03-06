/**
* Copyright (C) Kevin J. Estevez (kenystev) and Luis C. Isaula (lisaula)
*
* GNU GENERAL PUBLIC LICENSE Version 2
* The licenses for most software are designed to take away your
* freedom to share and change it.  By contrast, the GNU General Public
* License is intended to guarantee your freedom to share and change free
* software--to make sure the software is free for all its users.  This
* General Public License applies to most of the Free Software
* Foundation's software and to any other program whose authors commit to
* using it.
*/

#include "PlayScreen.h"
#include "RaceGear.h"

PlayScreen::PlayScreen(Game *game)
{
    this->game = game;
    loadCars("cars.xml");
}

PlayScreen::~PlayScreen()
{
    delete track;
    delete back_button;
    delete background;
    delete bu;
    delete bd;
    delete track;
    delete player_car;
}

void PlayScreen::show ()
{
    time=0;
    scr=new Scores();
    finish=false;

    player_car = cars[((RaceGear*)game)->selected_car];
    player_car->initCar();

    track = new Pista(player_car, game->rosalila_graphics, game->receiver,((RaceGear*)game)->selected_track);

    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(20,18,bu,bd,game->rosalila_graphics,game);
    track->init();
    n =((RaceGear*)game)->name_player;
    if(scr->seekUser(n)<0){
        scr->createNewUserBinary(n);
    }
    num_rt = ((RaceGear*)game)->id_pista;
    display_laps = new Font("airstrikeacad.ttf");
    display_laps->setSize(30);
    display_laps->setColor(0,0,0);
}

void PlayScreen::render (RosalilaGraphics*p)
{
    track->draw();
    if(!track->getLose()){
        track->logica();
    }

    if(track->laps==0)
    {
        finish=true;
        ((RaceGear*)game)->seg=track->seg;

        if(game->rosalila_graphics->frame%100==0)
            game->setScreen(((RaceGear*)game)->STATISTICS);

    }
    back_button->update(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
//    if(back_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
//        game->setScreen(((RaceGear*)game)->MENU);
    back_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());

    display_laps->drawText("Laps: "+toString(track->laps),117,87);

}
//        void resize (int width, int height);
void PlayScreen::pause ()
{

}

void PlayScreen::resume ()
{

}

void PlayScreen::hide ()
{
    time = ((RaceGear*)game)->seg;
    if(finish){
        scr->setPuntosToPista(n,time,num_rt);
    }
//    //scr->setPuntosToPista(n,time,num_rt);
//    track->clear();
//    delete background;
//    delete scr;
//    delete track;
//    delete player_car;
//    delete cars[0];
//    delete cars[1];
//    delete cars[2];
//    delete cars[3];
//    delete &cars;
}

void PlayScreen::dispose ()
{
    delete player_car;
    delete track;
    delete bu;
    delete bd;
    delete back_button;
}

void PlayScreen::loadCars(string path)
{
    TiXmlDocument doc((assets_directory+path).c_str());
    doc.LoadFile();

    TiXmlNode *Cars = doc.FirstChild("Cars");
    int i=0;
    for(TiXmlNode *car = Cars->FirstChild("car");
        car!=NULL;
        car = car->NextSibling("car"),i++)
        {
            cars[i] = new Car(game->rosalila_graphics,car->ToElement()->Attribute("image"));
            cars[i]->maximum = atof(car->ToElement()->Attribute("velocity"));
            cars[i]->a = atof(car->ToElement()->Attribute("aceleration"));
            cars[i]->CHANGE_TURN = atof(car->ToElement()->Attribute("turn"));
        }
}
