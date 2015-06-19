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
    car = c;
}
Pista::Pista(){

}
void Pista::init(){
    for(int i=0; i<1; i++)
        miLista1->add("rect");
    miLista1->add("Meta");
    miLista1->add("puas_left");
    miLista1->add("rect");
    miLista1->add("rect");
    miLista1->add("puas_left");
    miLista1->add("puas_right");
    miLista1->add("rect");
    miLista1->add("rect");
    miLista1->add("puas_right");
    miLista1->add("puas_left");
    miLista1->add("puas_center");
    miLista1->add("rect");
    miLista1->add("rect");
    miLista1->add("rect");
    miLista1->add("rect");
    miLista1->add("rect");
    miLista1->add("puas_center");

    for(int i=0; i<30; i++)
        miLista1->add("rect");

    for(int i=0; i<8; i++)
        miLista2->add("flags");
}

void Pista::logica(){
            off_set_y=car->v;

        if(car->turn)
            off_set_x=car->TURN;
        else
            off_set_x=0;

        car->update(receiver);
}
void Pista:: draw(){

    painter->draw2DImage(background,background->getWidth(),background->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
    miLista1->draw(car,off_set_x,off_set_y);
    miLista2->draw(off_set_x,off_set_y);
    car->draw(painter);
}
Pista::~Pista()
{
    delete miLista1;
    delete miLista2;
    delete receiver;
    delete background;
}

void Pista::clear()
{
    miLista1->clear();
    miLista2->clear();
}
