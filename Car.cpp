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

    wheels.w = car->getWidth()*0.9;
    wheels.h = car->getHeight()*0.15;
    wheels.x = (car->getWidth())*0.5 - wheels.w*0.5;
    wheels.y = (y+car->getHeight()) - wheels.h;

    a=0.2;
    v=0;
    v_max=15;
    off_set_x=0;
    CHANGE_TURN=13;
    TURN=CHANGE_TURN;
    outOfRoad=false;
    hurt=0;
}

Car::~Car()
{
    //dtor
}

void Car::update(Receiver *r)
{
    if(r->isKeyDown(SDL_SCANCODE_DOWN) || r->isJoyDown(4,0))
    {
        if(v>0)
            v-=a*2;
        else
            v=0;
    }else
    if(r->isKeyDown(SDL_SCANCODE_UP) || r->isJoyDown(1,0))
    {
        if(hurt==0)
        {
            if(v<v_max)
            {
                v+=a;
            }
        }
        else
            v=hurt;
    }else{
        if(v>0)
            v-=a;
        else
            v=0;
    }

    car = state["ahead"];
    turn=false;
    hurt=0;
    if(v>0){
        if((r->isKeyDown(SDL_SCANCODE_RIGHT)  || r->isJoyDown(-6,0))&& off_set_x>-850)
        {
            turn=true;
            TURN=-CHANGE_TURN;
            off_set_x+=TURN;
            car = state["right"];
        }
        if((r->isKeyDown(SDL_SCANCODE_LEFT)  || r->isJoyDown(-4,0)) && off_set_x<850)
        {
            turn=true;
            TURN=CHANGE_TURN;
            off_set_x+=TURN;
            car = state["left"];
        }
        if(outOfRoad) //off_set_x>LEFT_MAX || off_set_x<RIGHT_MAX)
        {
            if(v>a)
                v-=a*2;
            else
                v=a;
            outOfRoad=false;
        }
    }
    cout<<"-----> off_X-CAR: "<<off_set_x<<endl;
}

void Car::draw(RosalilaGraphics *painter)
{
    wheels.x = (x+car->getWidth())*0.5 + wheels.w*0.465;
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
