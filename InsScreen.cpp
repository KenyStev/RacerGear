#include "InsScreen.h"
#include "RaceGear.h"
InsScreen::InsScreen(Game * game)
{
    this->game = game;
    //ctor
}
void InsScreen::show(){
    fondo = game->rosalila_graphics->getTexture(assets_directory+"Instrucciones.png");
    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(130,40,bu,bd,game->rosalila_graphics);
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

}
void InsScreen::dispose (){

}

InsScreen::~InsScreen()
{
    //dtor
}
