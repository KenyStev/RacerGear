#include "RankButton.h"
#include "RaceGear.h"

RankButton::RankButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game) : Button(x_position,y_position,up,down,painter)
{
    this->game = game;
    //ctor
}
RankButton::RankButton(){

}

void RankButton:: funcionamiento(){
    game->setScreen(((RaceGear*)game)->RANKING);
}

RankButton::~RankButton()
{
    //dtor
}
