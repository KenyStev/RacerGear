#include "Scores.h"
/*
    nombre 20
    pista1 4
    pista2 4
    pista3 4
    pista4 4
    promedio 4
*/
Scores::Scores()
{
    PATH_ARCHIVO = "ranking";
    //ctor
}

bool Scores::createNewUserBinary(string name)
{
    string archivo = "ranking";
    ofstream file(archivo.c_str(),ios::in);
        if(!file){
            file.open(archivo.c_str());
        }
    //user1 = new Usuario(name);
    file.seekp(0,ios::end);
    int x=0,x1=0,x2=0,x3=0,p=0;
    file.write(name.c_str(),20);
    file.write((char*)&x,4);
    file.write((char*)&x1,4);
    file.write((char*)&x2,4);
    file.write((char*)&x3,4);
    file.write((char*)&p,4);
    file.close();

}
bool Scores::readFileBinary(){
    string archivo ="ranking";
    ifstream file(archivo.c_str());
    file.seekg(0,ios::end);
    int fin = file.tellg();
    int cantidad = fin/40;
    file.seekg(0,ios::beg);
    mi_mapa.clear();
    for(int i =0;i<cantidad;i++){
        char* nombre= new char[20];
        string n;
        int x1,x2,x3,x4,p;
        file.read(nombre,20);
        file.read((char*)&x1,4);
        file.read((char*)&x2,4);
        file.read((char*)&x3,4);
        file.read((char*)&x4,4);
        file.read((char*)&p,4);
        n= nombre;
        Usuario *u = new Usuario(n,x1,x2,x3,x4,p);
        u->setAverage();
        //u->imprimir();
        mi_mapa.insert(pair<int,Usuario*>(u->getAverage(),u));
    }
    file.close();
    return true;
}

void Scores::printMap(){
    multimap<int,Usuario*>::iterator i = mi_mapa.begin();
    int cont=0;
    int cantidad=mi_mapa.size();
    while(cont<cantidad && cont<6){
        Usuario * user;
        user = i->second;
        user->print(cont);
        i++;
        cont++;
    }
    //font->drawText("Hola",0,0);
}

int Scores::seekUser(string name){
    ifstream file(PATH_ARCHIVO.c_str(),ios::in);
    file.seekg(0,ios::end);
    int fin = file.tellg();
    int cant = fin/40;
    file.seekg(0,ios::beg);

    for(int i=0;i<cant;i++){
        char* nombre= new char[20];
        string n;
        int x1,x2,x3,x4,p;
        file.read(nombre,20);
        n= nombre;
        if(n==name){
            return file.tellg();
        }
        file.read((char*)&x1,4);
        file.read((char*)&x2,4);
        file.read((char*)&x3,4);
        file.read((char*)&x4,4);
        file.read((char*)&p,4);

    }
    file.close();
    return -1;
}

void Scores::seekRLP(int no_pista){
    ifstream file(PATH_ARCHIVO.c_str());
    file.seekg(0,ios::end);
    int fin = file.tellg();
    int cantidad = fin/40;
    file.seekg(0,ios::beg);
    mi_mapa.clear();
    for(int i =0;i<cantidad;i++){
        char* nombre= new char[20];
        string n;
        int x1,x2,x3,x4,p;
        file.read(nombre,20);
        file.read((char*)&x1,4);
        file.read((char*)&x2,4);
        file.read((char*)&x3,4);
        file.read((char*)&x4,4);
        file.read((char*)&p,4);
        n= nombre;
        Usuario *u = new Usuario(n,x1,x2,x3,x4,p);
        if(no_pista==1){
            mi_mapa.insert(pair<int,Usuario*>(x1,u));
        }
        else if(no_pista==2){
            mi_mapa.insert(pair<int,Usuario*>(x2,u));
        }
        else if(no_pista==3){
            mi_mapa.insert(pair<int,Usuario*>(x3,u));
        }
        else if(no_pista==4){
            mi_mapa.insert(pair<int,Usuario*>(x4,u));
        }
    }
    file.close();
}

int Scores::getRLP(string name){
    int mi_posicion=1;
    multimap<int,Usuario*>::iterator i = mi_mapa.begin();
    while(i!=mi_mapa.end()){
        string user = i->second->nombre;
        if(user==name){
            return mi_posicion;
        }
        mi_posicion++;
        i++;
    }
}

bool Scores::setPuntosToPista(string name, int puntos, int pista){
    ofstream file(PATH_ARCHIVO.c_str(),ios::in);
    int pos = seekUser(name);
    if(pos>0){
        file.seekp(pos,ios::cur);
        int real = pista -1;
        file.seekp(real*4,ios::cur);
        file.write((char*)&puntos,4);
        file.close();
        return true;
    }
    file.close();
    return false;
}

Scores::~Scores()
{
    //dtor
}
