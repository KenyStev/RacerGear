#include "InstrButton.h"

InstrButton::InstrButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter) : Button(x_position,y_position,up,down,painter)
{
    //ctor
}
InstrButton::InstrButton(){

}
void InstrButton:: funcionamiento(){
    cout<<"Funcinamiento Instrucciones"<<endl;
}

InstrButton::~InstrButton()
{
    //dtor
}
