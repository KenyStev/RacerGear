#include "RankButton.h"

RankButton::RankButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter) : Button(x_position,y_position,up,down,painter)
{
    //ctor
}
RankButton::RankButton(){

}

void RankButton:: funcionamiento(){
    cout<<"Funcionamiento rank"<<endl;
}

RankButton::~RankButton()
{
    //dtor
}
