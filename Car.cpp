#include "Car.h"

Car::Car(RosalilaGraphics *p, string image)
{
    painter = p;
    state["ahead"] = p->getTexture("assets/"+image+"_ahead.png");
    state["left"] = p->getTexture("assets/"+image+"_left.png");
    state["right"] = p->getTexture("assets/"+image+"_right.png");

    car = state["ahead"];

    velocimeter_state["first"] = p->getTexture(assets_directory+"Velocimeter_1.png");
    velocimeter_state["second"] = p->getTexture(assets_directory+"Velocimeter_2.png");
    velocimeter_state["third"] = p->getTexture(assets_directory+"Velocimeter_3.png");
    velocimeter_state["fourth"] = p->getTexture(assets_directory+"Velocimeter_4.png");
    velocimeter_state["fifth"] = p->getTexture(assets_directory+"Velocimeter_5.png");

    warning.push_back(p->getTexture(assets_directory+"Warnig_1.png"));
    warning.push_back(p->getTexture(assets_directory+"Warnig_2.png"));
    warning.push_back(p->getTexture(assets_directory+"Warnig_3.png"));
    warning.push_back(p->getTexture(assets_directory+"Warnig_4.png"));

    marker = p->getTexture(assets_directory+"Indicador.png");
    velocimeter = velocimeter_state["first"];

    x = p->screen_width*0.5 - car->getWidth()*0.5;
    y = p->screen_height - car->getHeight();
    scale=1;
    marker_x = 114;
    marker_y = 614;//(140+velocimeter->getHeight())-marker->getHeight();
    marker_y_max = 201;//((140+velocimeter->getHeight())-marker->getHeight())-413;

    wheels.w = car->getWidth()*0.9;
    wheels.h = car->getHeight()*0.15;
    wheels.x = (car->getWidth())*0.5 - wheels.w*0.5;
    wheels.y = (y+car->getHeight()) - wheels.h;

    marker_speed =0;
    a=0.2;
    v=0;
    maximum = 15;
    v_max=0;
    first = true, second = false,third = false,fourth = false,fifth = false, speed_up = false,danger= false, lose = false;
    warning_actual=0;
    off_set_x=0;
    CHANGE_TURN=13;
    TURN=CHANGE_TURN;
    outOfRoad=false;
    hurt=0;
    time=0;
}
Car::Car(){
    //nada
}

Car::~Car()
{
    delete painter;
    delete car;
    delete velocimeter;
    delete marker;
//    delete velocimeter_state;
//    delete state;
}

void Car::initCar()
{
    marker_speed =0;
//    a=0.2;
    v=0;
//    maximum = 15;
    v_max=0;
    first = true, second = false,third = false,fourth = false,fifth = false, speed_up = false,danger= false, lose = false;
    warning_actual=0;
    off_set_x=0;
//    CHANGE_TURN=13;
    TURN=CHANGE_TURN;
    outOfRoad=false;
    hurt=0;
    time=0;
    scale=1;
    marker_x = 114;
    marker_y = 614;//(140+velocimeter->getHeight())-marker->getHeight();
    marker_y_max = 201;//((140+velocimeter->getHeight())-marker->getHeight())-413;
}

void Car::warningAnimation(){
        painter->draw2DImage(warning[warning_actual],
                            warning[warning_actual]->getWidth(),warning[warning_actual]->getHeight(),
                            103,150,
                            scale,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
        if(painter->frame%6==0)
            warning_actual++;
        if(warning_actual>=warning.size()){
            warning_actual=0;
            time++;
        }
}
void Car::update(Receiver *r)
{
    if(r->isKeyDown(SDL_SCANCODE_DOWN) || r->isJoyDown(4,0))
    {
        speed_up = false;
        if(v>0)
            v-=a*2;
        else
            v=0;
    }else
    if(r->isKeyDown(SDL_SCANCODE_UP) || r->isJoyDown(1,0))
    {
        speed_up = true;
        if(hurt==0)
        {
            if(v<v_max)
            {
                v+=a;
            }
        }
        else
        {
            speed_up = false;
            v=hurt;
        }

    }else{
        speed_up = false;
        if(v>0)
            v-=a;
        else
            v=0;
    }

//    if(v>v_max){
//        v-=a*2;
//    }
    car = state["ahead"];
    if(r->isKeyDown(SDLK_1) || r->isKeyPressed(SDLK_a)){
        second=false,third=false,fourth =false,fifth =false;
        velocimeter = velocimeter_state["first"];
        v_max = maximum *0.20;
        marker_speed =6;
        if(!first){
            marker_y = 614;
            first = true;
        }
    }
    else if(r->isKeyDown(SDLK_2)){
        first = false,third=false,fourth =false,fifth =false;
        velocimeter= velocimeter_state["second"];
        v_max = maximum *0.40;
        marker_speed =5;
        if(!second){
        marker_y = 554;
        second=true;
        }
    }
    else if(r->isKeyDown(SDLK_3)){
        second=false,first=false,fourth =false,fifth =false;
        velocimeter= velocimeter_state["third"];
        v_max = maximum *0.60;
        marker_speed =4;
        if(!third){
            marker_y = 474;
            third = true;
        }
    }
    else if(r->isKeyDown(SDLK_4)){
        third = false,second=false,first=false,fifth =false;
        velocimeter= velocimeter_state["fourth"];
        v_max = maximum *0.80;
        marker_speed =3;
        if(!fourth){
            marker_y = 404;
            fourth = true;
        }
    }
    else if(r->isKeyDown(SDLK_5)){
        fourth = false,second=false,third=false,first =false;
        velocimeter= velocimeter_state["fifth"];
        v_max = maximum;
        marker_speed =3;
        if(!fifth){
            marker_y = 314;
            fifth = true;
        }
    }
    if(speed_up && !outOfRoad){
        if(marker_y>marker_y_max)
            marker_y-=marker_speed;
    }else{
        if(marker_y<614){
            marker_y+=marker_speed*2;
        }else
            marker_y=614;
    }
    if(danger){
        if(time>15){
            lose=true;
        }
    }else
        time=0;

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

bool Car:: getLose(){
    return lose;
}

void Car::draw()
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
        painter->draw2DImage(velocimeter,
                            velocimeter->getWidth(),velocimeter->getHeight(),
                            50,145,
                            scale,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
        painter->draw2DImage(marker,
                            marker->getWidth(),marker->getHeight(),
                            marker_x,marker_y,
                            scale,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
        if((first && marker_y<=364)||(second && marker_y<=310)
        || (third && marker_y>=544)||(fourth && marker_y>=364)
        || (fifth && marker_y>=330)){
            warningAnimation();
            danger = true;
            if(lose)
                painter->drawText("PERDISTE",painter->screen_width*0.5,painter->screen_height*0.5);
            }else
                danger = false;
//    painter->drawRectangle(wheels.x,wheels.y,wheels.w,wheels.h,
//                            0,255,0,0,100,false);
}
