#include "PlayScreen.h"
#include "RaceGear.h"

PlayScreen::PlayScreen(Game *game)
{
    this->game = game;
    player_car = new Car(game->rosalila_graphics);
    track = new Pista(player_car, game->rosalila_graphics, game->receiver);

    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
    back_button = new BackButton(100,100,bu,bd,game->rosalila_graphics);
    track->init();
}

PlayScreen::~PlayScreen()
{
    //dtor
}

void PlayScreen::show ()
{
//    this->game = game;
//    player_car = new Car(game->rosalila_graphics);
//    track = new Pista(player_car, game->rosalila_graphics, game->receiver);
//
//    bu = game->rosalila_graphics->getTexture(assets_directory+"BACK_UP.png");
//    bd = game->rosalila_graphics->getTexture(assets_directory+"BACK_DWN.png");
//    back_button = new BackButton(100,100,bu,bd,game->rosalila_graphics);
    track->init();
}

void PlayScreen::render (RosalilaGraphics*)
{
    track->logica();
    track->draw();

//    back_button->update(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
    if(back_button->clicked(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown()))
        game->setScreen(((RaceGear*)game)->MENU);
    back_button->draw(game->receiver->getMouse_X(),game->receiver->getMouse_Y(),game->receiver->isLeftClickDown());
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
    track->clear();
//    delete player_car;
//    delete track;
//    delete bu;
//    delete bd;
//    delete back_button;
}

void PlayScreen::dispose ()
{

}
