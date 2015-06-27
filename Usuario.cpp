#include "Usuario.h"

Usuario::Usuario(string name)
{
    nombre = name;
    pista1=0;
    pista2=0;
    pista3=0;
    pista4=0;
    promedio=0;
    //ctor
}

Usuario::Usuario(string name, int p1,int p2,int p3,int p4,int pro){
    nombre = name;
    pista1=p1;
    pista2=p2;
    pista3=p3;
    pista4=p4;
    promedio=pro;
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
void Usuario::print(RosalilaGraphics *painter,int c){
    string p=toString(pista1);
    string p2=toString(pista2);
    string p3=toString(pista3);
    string p4=toString(pista4);
    string p5=toString(promedio);
    painter->drawText(nombre,100,100*c);
}
Usuario::~Usuario()
{
    delete &nombre;
    delete &pista1;
    delete &pista2;
    delete &pista3;
    delete &pista4;
    delete &promedio;
    //dtor
}
