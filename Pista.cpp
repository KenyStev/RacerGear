#include "Pista.h"
#include "ListImage.h"

Pista::Pista(Car*c,RosalilaGraphics*rg, Receiver*r,std::string path) : Pista(c, rg, r)
{
    loadTrack(path);
}

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
    laps=1;
    time=0;
    start=NULL;
    stop=NULL;
    seg=0;
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

    for(int i=0; i<100; i++)
        miLista1->add("rect");

    for(int i=0; i<90; i++)
        miLista2->add("flags");
}

void Pista::logica(){
        start = clock();
        off_set_y=car->v;

        if(car->turn)
            off_set_x=car->TURN;
        else
            off_set_x=0;

        car->update(receiver);
        stop = clock();
        time +=(stop - start);
        seg = (time/2)/1000;
}
void Pista:: draw(){

    painter->draw2DImage(background,background->getWidth(),background->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
    miLista1->draw(car,off_set_x,off_set_y);
    miLista2->draw(off_set_x,off_set_y);
    car->draw(painter);
    painter->drawText("Tiempo: "+ toString(seg)+" seg.",0,0);
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

void Pista::loadTrack(std::string path)
{
    TiXmlDocument doc((assets_directory+path).c_str());
    doc.LoadFile();
    TiXmlNode *track = doc.FirstChild("Track");
    laps = atoi(track->ToElement()->Attribute("laps"));
    TiXmlNode* step=track->FirstChild("step");

    for(TiXmlNode* step=track->FirstChild("step");
        step!=NULL;
        step=step->NextSibling("step"))
        {
            string s = step->ToElement()->Attribute("path");
            int d = atoi(step->ToElement()->Attribute("long"));
            int hurt = atoi(step->ToElement()->Attribute("hurt"));
            for(int i=0;i<d;i++)
                miLista1->add(hurt,s);
        }
}
