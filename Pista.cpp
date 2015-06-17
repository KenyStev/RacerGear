#include "Pista.h"
#include "ListImage.h"

Pista::Pista(Car *c, RosalilaGraphics *paint, Receiver* receiver)
{
    miLista1 =new ListImage(paint);
    miLista2 =new ListImage(paint);

//    pasted =new ListImage(paint);
//    actual =new ListImage(paint);
//    nexts=new ListImage(paint);

    this->receiver = receiver;
    off_set_y=0;
    off_set_x=0;
    background = paint->getTexture(assets_directory+"background.png");
    this->painter = paint;
//    segmentos["rect"] = new ListImage(paint);
//
//    for(int i=0;i<8;i++)
//        segmentos["Meta"]->add(assets_directory+"Meta.png");
//
//    for(int i=0;i<8;i++)
//        segmentos["rect"]->add(assets_directory+"rect.png");
//    bu = paint->getTexture(assets_directory+"BACK_UP.png");
//    bd = paint->getTexture(assets_directory+"BACK_DWN.png");
//    back_button = new BackButton(100,100,bu,bd,painter);
    car = c;
}
Pista::Pista(){

}
void Pista::init(){

//map<std::string,Image*> texturas;
//texturas["Meta"] = new Step(painter,assets_directory+"Meta.png");
//texturas["rect"] = new Step(painter,assets_directory+"rect.png");
//texturas["flags"] = new Step(painter,assets_directory+"flags.png");

    miLista1->add(assets_directory+"Meta.png");
    miLista1->add(assets_directory+"puas_left.png");
    miLista1->add(assets_directory+"puas_left.png");
    miLista1->add(assets_directory+"puas_left.png");
    miLista1->add(assets_directory+"puas_left.png");
    miLista1->add(assets_directory+"puas_left.png");
    for(int i=0; i<100; i++)
        miLista1->add(assets_directory+"rect.png");

    for(int i=0; i<8; i++)
        miLista2->add(assets_directory+"flags.png");
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
    miLista1->draw(off_set_x,off_set_y);
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
