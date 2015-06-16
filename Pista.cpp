#include "Pista.h"
#include "ListImage.h"

Pista::Pista(Car *c, RosalilaGraphics *paint, Receiver* receiver)
{
    miLista1 =new ListImage(paint);
    miLista2 =new ListImage(paint);
    this->receiver = receiver;
    off_set_y=0;
    off_set_x=0;
    background = paint->getTexture(assets_directory+"background.png");
    this->painter = paint;
//    bu = paint->getTexture(assets_directory+"BACK_UP.png");
//    bd = paint->getTexture(assets_directory+"BACK_DWN.png");
//    back_button = new BackButton(100,100,bu,bd,painter);
    car = c;
}
Pista::Pista(){

}
void Pista::init(){
//    miLista1->add(assets_directory+"Meta.png");
    for(int i=0; i<8; i++)
        miLista1->add(assets_directory+"rect.png");

    for(int i=0; i<8; i++)
        miLista2->add(assets_directory+"flags.png");

//    for(int i=0; i<30; i++)
//    {
//        miLista1->flush(100);
//        miLista2->flush(100);
//    }
}

void Pista::logica(){
//        if(receiver->isKeyDown(SDL_SCANCODE_UP))
//            off_set_y=20.5;
//        else if(receiver->isKeyDown(SDL_SCANCODE_DOWN))
//            off_set_y=-10.5;
//        else
            off_set_y=car->v;

        if(car->turn)//receiver->isKeyDown(SDL_SCANCODE_LEFT))
            off_set_x=car->TURN;
        else
            off_set_x=0;

//        back_button->update(receiver->getMouse_X(),receiver->getMouse_Y(),receiver->isLeftClickDown());
        car->update(receiver);
}
void Pista:: draw(){
     painter->draw2DImage(background,background->getWidth(),background->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
     miLista1->draw(off_set_x,off_set_y);
     miLista2->draw(off_set_x,off_set_y);
//     back_button->draw(receiver->getMouse_X(),receiver->getMouse_Y(),receiver->isLeftClickDown());
     car->draw(painter);
}
Pista::~Pista()
{
    delete miLista1;
    delete miLista2;
    delete receiver;
    delete background;
    //dtor
}
