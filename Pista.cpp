/**
* Copyright (C) Kevin J. Estevez (kenystev) and Luis C. Isaula (lisaula)
*
* GNU GENERAL PUBLIC LICENSE Version 2
* The licenses for most software are designed to take away your
* freedom to share and change it.  By contrast, the GNU General Public
* License is intended to guarantee your freedom to share and change free
* software--to make sure the software is free for all its users.  This
* General Public License applies to most of the Free Software
* Foundation's software and to any other program whose authors commit to
* using it.
*/

#include "Pista.h"
#include "ListImage.h"

Pista::Pista(Car*c,RosalilaGraphics*rg, Receiver*r,std::string path) : Pista(c, rg, r)
{
    loadTrack(path);
}

Pista::Pista(Car *c, RosalilaGraphics *paint, Receiver* receiver)
{
    road =new ListImage(paint);
    flags =new ListImage(paint);

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
    cont=-1;
    go=false;
    display_time=new Font("airstrikeacad.ttf");
    display_time->setSize(20);
    display_time->setColor(0,0,0);
    contD.push_back(paint->getTexture(assets_directory+"Contador1.png"));
    contD.push_back(paint->getTexture(assets_directory+"Contador2.png"));
    contD.push_back(paint->getTexture(assets_directory+"Contador3.png"));
    contD.push_back(paint->getTexture(assets_directory+"Contador4.png"));
}
Pista::Pista(){

}
void Pista::countdown(){
    if(cont>=0 && cont<=3){
    painter->draw2DImage(contD[cont],
                            contD[cont]->getWidth(),contD[cont]->getHeight(),
                            215,67,
                            1,
                            0,false,
                            0,0,
                            Color(255,255,255,255),
                            0,0,
                            false);
    }
    if(cont<=3){
        if(painter->frame%50==0)
            cont++;
    }
}
bool Pista::getLose(){
    return car->getLose();
}
void Pista::init(){
    cont=-1;
    go=false;
    for(int i=0; i<90; i++)
        flags->add("flags_2");
}

void Pista::logica(){
        if(go){
            start = clock();
            off_set_y=car->v;

            if(car->turn)
                off_set_x=car->TURN;
            else
                off_set_x=0;

            car->update(receiver);

            stop = clock();
            time +=(stop - start);
            seg = ((time)/300);
            if(road->isMeta() && road->pops!=0)
            {
                laps--;
                road->add(road->pop());
            }
            if(laps==0){
                if(off_set_y>0)
                    off_set_y-=1;
                else{
                    off_set_y=0;
                }
            }
            if(getLose()){
                    off_set_y=0;
                    off_set_x=0;
            }
        }
        if(cont==4){
            if(painter->frame%50==0){
                go=true;
            }
        }

}
void Pista:: draw(){

    painter->draw2DImage(background,background->getWidth(),background->getHeight(),0,0,1,0,false,0,0,Color(255,255,255,255),0,0,false);
    road->draw(car,off_set_x,off_set_y);
    flags->draw(off_set_x,off_set_y);
    display_time->drawText("Time: "+ toString(seg)+" seg.",115,120);
    car->draw();
    if(!go){
        countdown();
    }
}
Pista::~Pista()
{
    delete road;
    delete flags;
    delete receiver;
    delete background;
    delete display_time;
}

void Pista::clear()
{
    road->clear();
    flags->clear();
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
