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

#include "RankingScreen.h"
#include "RaceGear.h"

RankingScreen::RankingScreen(Game *game)
{
    this->game = game;
    //ctor
}

void RankingScreen:: show (){
    background = game->rosalila_graphics->getTexture(assets_directory+"Ranking_background.png");
    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(50,50,bu,bd,game->rosalila_graphics,game);
    ranking = new Scores();
    ranking->readFileBinary();

}
void RankingScreen::render (RosalilaGraphics*p){

    game->rosalila_graphics->draw2DImage(background,
                            background->getWidth(),background->getHeight(),
                            0,0,1,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
    ranking->printMap();
    if(back_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
            game->setScreen(((RaceGear*)game)->MENU);
        back_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
}
void RankingScreen::pause ()
{

}

void RankingScreen::resume ()
{

}

void RankingScreen::hide ()
{
    //delete back_button;
    delete background;
    //delete bu;
    //delete bd;
    delete ranking;
}

void RankingScreen::dispose ()
{

}

RankingScreen::~RankingScreen()
{
    //dtor
}
