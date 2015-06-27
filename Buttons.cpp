#include "Buttons.h"

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
