#include "PlayButton.h"

PlayButton::PlayButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Receiver* receiver) :Button(x_position,y_position,up,down,painter)
{
    pista= new Pista(painter, receiver);
    pista->init();
    //ctor
}
PlayButton::PlayButton(){

}
void PlayButton::funcionamiento(){
//    if(play_into){
        pista->logica();
        pista->draw();
//    }
}
PlayButton::~PlayButton()
{
    delete pista;
    //dtor
}
