#include "Car.h"

Car::Car(RosalilaGraphics *p)
{
    car = p->getTexture("assets/car.png");

    x = p->screen_width*0.5 - car->getWidth()*0.5;
    y = p->screen_height - car->getHeight();
    scale=1;
}

Car::~Car()
{
    //dtor
}

void Car::draw(RosalilaGraphics *painter)
{
    painter->draw2DImage(   car,
                            car->getWidth(),car->getHeight(),
                            x,y,
                            scale,
                            0,
                            true,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
}
