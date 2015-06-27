#include "Buttons.h"
#include "RaceGear.h"

CarButton::CarButton(int num,int x_position, int y_position, Image* up, Image* down, RosalilaGraphics* painter) : Button(x_position,y_position,up,down,painter)
{
    this->num=num;
}

CarButton::~CarButton()
{
    //dtor
}

void CarButton::funcionamiento()
{
    cout<<"Funciona"<<endl;
}

//TrackButton
TrackButton::TrackButton(string name,int x_position, int y_position, Image* up, Image* down, RosalilaGraphics* painter) : Button(x_position,y_position,up,down,painter)
{
    this->name=name;
}

TrackButton::~TrackButton()
{

}

void TrackButton::funcionamiento()
{

}

//PlayButton
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

//BackButton
BackButton::BackButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter): Button(x_position,y_position,up,down,painter)
{
    //ctor
}

void BackButton:: funcionamiento(){


}
BackButton::BackButton(){

}

BackButton::~BackButton()
{
    //dtor
}

//ExitButton
ExitButton::ExitButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter) : Button(x_position,y_position,up,down,painter)
{
    //ctor
}
ExitButton::ExitButton(){

}
void ExitButton::funcionamiento(){
    exit(0);
}


ExitButton::~ExitButton()
{
    //dtor
}

//InstrButton
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

//RankButton
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
