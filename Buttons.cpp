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
TrackButton::TrackButton(int i,string name,int x_position, int y_position, Image* up, Image* down, RosalilaGraphics* painter) : Button(x_position,y_position,up,down,painter)
{
    this->name=name;
    this->num_pista=i;
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
}
PlayButton::PlayButton(){

}
void PlayButton::funcionamiento(){
    game->setScreen(((RaceGear*)game)->SELECT);
}
PlayButton::~PlayButton()
{
//    delete pista;
    //dtor
}

//BackButton
BackButton::BackButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game): Button(x_position,y_position,up,down,painter)
{
    this->game = game;
}

void BackButton:: funcionamiento(){
    game->setScreen(((RaceGear*)game)->MENU);
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
