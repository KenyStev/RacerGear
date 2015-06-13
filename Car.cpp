#include "Car.h"

Car::Car(RosalilaGraphics *p)
{
//    car = p->getTexture("assets/car.png");

    state["ahead"] = p->getTexture("assets/ahead.png");
    state["left"] = p->getTexture("assets/left.png");
    state["right"] = p->getTexture("assets/right.png");

    car = state["ahead"];

    x = p->screen_width*0.5 - car->getWidth()*0.5;
    y = p->screen_height - car->getHeight();
    scale=1;
}

Car::~Car()
{
    //dtor
}

void Car::update(Receiver *r)
{
    car = state["ahead"];
    if(r->isKeyDown(SDL_SCANCODE_RIGHT))
        car = state["left"];
    if(r->isKeyDown(SDL_SCANCODE_LEFT))
        car = state["right"];
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
