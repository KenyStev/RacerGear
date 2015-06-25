#include "Ranking.h"
/*
    El archivo Ranking.txt esta definido asi:
        string nombre: 20
        int pista1; 4
        int pista2; 4
        int pista3; 4
        int pista4; 4
        int pista5; 4
        int pista6; 4
        double promedio: 8

        total bits: 52;
*/
Ranking::Ranking(string name, int time, int pista, RosalilaGraphics * painter)
{
    this->player_name = name;
    this->time = time;
    this->painter = painter;
    this->pista=pista;
    initFStream();
}
Ranking::Ranking()
{
    //ctor
}

void Ranking :: initFStream(){
    if(!out.is_open())
        out.open(rank_archivo,ios::in);
    if(!in.is_open())
        in.open(rank_archivo);
        out.seekp(0);
        in.seekg(0);
}

bool Ranking:: seekPlayer(string name){
    initFStream();
    char nombre[20];
    int x;
    double p;
    in.seekg(0,ios::end);
    int p_final = in.tellg();
    in.seekg(0);
    while(in.tellg()<p_final){
        in.read(nombre,20);
        if(strcmp(nombre,name.c_str())==0)
            return true;

        in.read((char*)&x,4);
        in.read((char*)&x,4);
        in.read((char*)&x,4);
        in.read((char*)&x,4);
        in.read((char*)&x,4);
        in.read((char*)&x,4);
        in.read((char*)&p,8);
    }
    in.close();
    out.close();
    return false;
}

void Ranking::saveRanking(int pista,int tiempo){
    initFStream();
    int real= pista-1;
    if(seekPlayer(this->player_name)){
        out.seekp(real*4,ios::cur);
        out.write((char*)&tiempo,4);
    }
    in.close();
    out.close();
}

void Ranking:: createNewUser(string name){
    initFStream();
    out.seekp(0,ios::end);
    if(!seekPlayer(name)){
        int x=0;
        double p =0;
        out.write(name.c_str(),20);
        out.write((char*)&x,4);
        out.write((char*)&x,4);
        out.write((char*)&x,4);
        out.write((char*)&x,4);
        out.write((char*)&x,4);
        out.write((char*)&x,4);
        out.write((char*)&p,8);
    }
    in.close();
    out.close();
}

void Ranking:: readRanking(){
    initFStream();
    char nombre[20];
    int p1,p2,p3,p4,p5,p6;
    double prom;
    in.seekg(0,ios::cur);
    int p_final = in.tellg();
    in.seekg(0);
    string tab="\t", str;
    while(in.tellg()<p_final){
        in.read(nombre,20);
        in.read((char*)&p1,4);
        in.read((char*)&p2,4);
        in.read((char*)&p3,4);
        in.read((char*)&p4,4);
        in.read((char*)&p5,4);
        in.read((char*)&p6,4);
        prom = average(p1,p2,p3,p4,p5,p6);
        str = nombre+tab+toString(p1)+tab+toString(p2)+tab+toString(p3)+tab+toString(p4)+tab+toString(p5)+tab+toString(p6);
        mi_ranking.insert(pair<string,int>(str,prom));
    }
    for(map<string,int>::iterator i=mi_ranking.begin();
        i!=mi_ranking.end();
        i++){
        //Nota: imprimira todos los jugadores, posible error de no espacio disponible si jugadores sobrepasa limite de la pantalla;
        string str = i->first+"\t"+toString(i->second);
        painter->drawText(str,10,0);
        }
        out.close();
        in.close();
}
/**
    calcula el promedio de el tiempo de las pistas;
*/
 double Ranking::average(int p,int p2,int p3,int p4,int p5,int p6){
    double suma = p+p2+p3+p4+p5+p6;
    double prom = suma/6;
    return prom;
 }

Ranking::~Ranking()
{
    delete painter;
    delete out;
    delete in;
    delete &mi_ranking;
    //dtor
}
