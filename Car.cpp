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

    a=0.01;
    v=0;
    v_max=30;
    off_set_x=0;
}

Car::~Car()
{
    //dtor
}

void Car::update(Receiver *r)
{
    if(r->isKeyDown(SDL_SCANCODE_UP))
    {
        if(v<v_max)
        {
            v+=a;
        }
    }else{
        if(v>0)
            v-=a;
        else
            v=0;
    }

    car = state["ahead"];
    turn=false;
    if(v>0){
        if(r->isKeyDown(SDL_SCANCODE_RIGHT) && off_set_x>-850)
        {
            turn=true;
            TURN=-10;
            off_set_x+=TURN;
            car = state["left"];
        }
        if(r->isKeyDown(SDL_SCANCODE_LEFT)  && off_set_x<850)
        {
            turn=true;
            TURN=10;
            off_set_x+=TURN;
            car = state["right"];
        }
        if(off_set_x>LEFT_MAX || off_set_x<RIGHT_MAX)
        {
            if(v>a)
                v-=a*2;
            else
                v=a;
        }
    }
    cout<<"-----> off_X-CAR: "<<off_set_x<<endl;
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
