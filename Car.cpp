#include "Car.h"

Car::Car(RosalilaGraphics *p)
{
    state["ahead"] = p->getTexture("assets/ahead.png");
    state["left"] = p->getTexture("assets/left.png");
    state["right"] = p->getTexture("assets/right.png");

    car = state["ahead"];

    x = p->screen_width*0.5 - car->getWidth()*0.5;
    y = p->screen_height - car->getHeight();
    scale=1;

    wheels.w = car->getWidth()*0.95;
    wheels.h = car->getHeight()*0.2;
    wheels.x = (car->getWidth())*0.5 - wheels.w*0.5;
    wheels.y = (y+car->getHeight()) - wheels.h;

    a=0.2;
    v=0;
    v_max=15;
    off_set_x=0;
    CHANGE_TURN=10;
    TURN=CHANGE_TURN;
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
        if(r->isKeyDown(SDL_SCANCODE_DOWN))
        {
            v-=a*2;
        }
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
            TURN=-CHANGE_TURN;
            off_set_x+=TURN;
            car = state["right"];
        }
        if(r->isKeyDown(SDL_SCANCODE_LEFT)  && off_set_x<850)
        {
            turn=true;
            TURN=CHANGE_TURN;
            off_set_x+=TURN;
            car = state["left"];
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
    wheels.x = (x+car->getWidth())*0.5 + wheels.w*0.412;
//    wheels.y = (y+car->getHeight()) - wheels.h;

    painter->draw2DImage(   car,
                            car->getWidth(),car->getHeight(),
                            x,y,
                            scale,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);

//    painter->drawRectangle(wheels.x,wheels.y,wheels.w,wheels.h,
//                            0,255,0,0,100,false);
}
