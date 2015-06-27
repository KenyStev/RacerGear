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
    back_button = new BackButton(100,100,bu,bd,game->rosalila_graphics);
    ranking = new Scores();
    ranking->readFileBinary();
    ranking->printMap();
    game->rosalila_graphics->drawText("MAMA",500,0);

//    ranking = new Ranking(game->rosalila_graphics);

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

}

void RankingScreen::dispose ()
{

}

RankingScreen::~RankingScreen()
{
    //dtor
}
