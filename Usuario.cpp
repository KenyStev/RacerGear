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

#include "Usuario.h"

Usuario::Usuario(string name)
{
    nombre = name;
    pista1=0;
    pista2=0;
    pista3=0;
    pista4=0;
    promedio=0;
    font= new Font("font.ttf");
    font->setSize(40);
    font->setColor(255,255,255);
}

Usuario::Usuario(string name, int p1,int p2,int p3,int p4,int pro){
    nombre = name;
    pista1=p1;
    pista2=p2;
    pista3=p3;
    pista4=p4;
    promedio=pro;
    font= new Font("font.ttf");
    font->setSize(40);
    font->setColor(255,255,255);
}
void Usuario::imprimir(){
    cout<<nombre<<endl;
    cout<<pista1<<endl;
    cout<<pista2<<endl;
    cout<<pista3<<endl;
    cout<<pista4<<endl;
    cout<<promedio<<endl;
}
Usuario::Usuario(){

}

int Usuario::average(){
    int suma=pista1+pista2+pista3+pista4;
    return suma/4;
}

void Usuario::setAverage(){
    this->promedio=average();
}
int Usuario::getAverage(){
    return promedio;
}
void Usuario::print(int c){
    string p=toString(pista1);
    string p2=toString(pista2);
    string p3=toString(pista3);
    string p4=toString(pista4);
    string p5=toString(promedio);
    int y = c*80+225;
    font->drawText(nombre,57,y);
    font->drawText(p,315,y);
    font->drawText(p2,545,y);
    font->drawText(p3,765,y);
    font->drawText(p4,985,y);
    font->drawText(p5,1200,y);
}
Usuario::~Usuario()
{
    delete &nombre;
    delete &pista1;
    delete &pista2;
    delete &pista3;
    delete &pista4;
    delete &promedio;
}
