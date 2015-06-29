#include "Pista.h"
#include "ListImage.h"

Pista::Pista(Car*c,RosalilaGraphics*rg, Receiver*r,std::string path) : Pista(c, rg, r)
{
    loadTrack(path);
}

Pista::Pista(Car *c, RosalilaGraphics *paint, Receiver* receiver)
{
    road =new ListImage(paint);
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

    display_time=new Font("font.ttf");
    display_time->setSize(50);
}
Pista::Pista(){

}
bool Pista::getLose(){
    return car->getLose();
}
void Pista::init(){
    for(int i=0; i<90; i++)
        miLista2->add("flags_2");
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
        seg = ((time)/1240);
        if(road->isMeta() && road->pops!=0)// && road->pops<=road->size*laps)
        {
            laps--;
            road->add(road->pop());
            cout<<"Laps: "<<laps<<endl;
//            if(laps==0)exit(11);
        }
}
void Pista:: draw(){

    painter->draw2DImage(background,background->getWidth(),background->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
    road->draw(car,off_set_x,off_set_y);
    miLista2->draw(off_set_x,off_set_y);
    display_time->drawText("Tiempo: "+ toString(seg)+" seg.",0,0);
    car->draw();
}
Pista::~Pista()
{
    delete road;
    delete miLista2;
    delete receiver;
    delete background;
    delete display_time;
}

void Pista::clear()
{
    road->clear();
    miLista2->clear();
}

void Pista::loadTrack(std::string path)
{
    TiXmlDocument doc((assets_directory+path).c_str());
    doc.LoadFile();
    TiXmlNode *track = doc.FirstChild("Track");
    laps = atoi(track->ToElement()->Attribute("laps"));

    for(TiXmlNode* repit=track->FirstChild("repit");
        repit!=NULL;
        repit=repit->NextSibling("repit"))
        {
            int rep = atoi(repit->ToElement()->Attribute("for"));
            for(int i=0;i<rep;i++)
            {
                for(TiXmlNode* step=repit->FirstChild("step");
                    step!=NULL;
                    step=step->NextSibling("step"))
                    {
                        string s = step->ToElement()->Attribute("path");
                        int d = atoi(step->ToElement()->Attribute("long"));
                        int hurt = atoi(step->ToElement()->Attribute("hurt"));
                        for(int i=0;i<d;i++)
                            road->add(hurt,s);
                    }
            }
        }
}
