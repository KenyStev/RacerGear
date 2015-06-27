#include "PlayButton.h"
#include "RaceGear.h"

PlayButton::PlayButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game) :Button(x_position,y_position,up,down,painter)
{
    this->game = game;
//    pista= new Pista(new Car(painter), painter, receiver);
//    pista->init();
    //ctor
}
PlayButton::PlayButton(){

}
void PlayButton::funcionamiento(){
    cout<<"FUNCIONAMIENTO PLAY"<<endl;
    //game->setScreen(((RaceGear*)game)->PLAY);//new PlayScreen(game));
}
PlayButton::~PlayButton()
{
//    delete pista;
    //dtor
}
