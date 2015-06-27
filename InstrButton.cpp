#include "InstrButton.h"
#include "RaceGear.h"

InstrButton::InstrButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game) : Button(x_position,y_position,up,down,painter)
{
    this->game = game;
}
InstrButton::InstrButton(){

}
void InstrButton:: funcionamiento(){
    game->setScreen(((RaceGear*)game)->INSTRUCTION);
}

InstrButton::~InstrButton()
{
    //dtor
}
