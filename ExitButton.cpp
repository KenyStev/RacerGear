#include "ExitButton.h"

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
