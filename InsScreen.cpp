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

#include "InsScreen.h"
#include "RaceGear.h"
InsScreen::InsScreen(Game * game)
{
    this->game = game;
}
void InsScreen::show(){
    fondo = game->rosalila_graphics->getTexture(assets_directory+"Instrucciones.png");
    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(130,40,bu,bd,game->rosalila_graphics,game);
}

void InsScreen::render(RosalilaGraphics * painter){
    game->rosalila_graphics->draw2DImage(fondo,fondo->getWidth(),fondo->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
    if(back_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
        game->setScreen(((RaceGear*)game)->MENU);
    back_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
}
void InsScreen::pause (){

}
void InsScreen::resume (){

}
void InsScreen::hide (){
    delete fondo;
    delete bd;
    delete bu;

}
void InsScreen::dispose (){

}

InsScreen::~InsScreen()
{
    delete fondo;
    delete bd;
    delete bu;
    delete back_button;
}
