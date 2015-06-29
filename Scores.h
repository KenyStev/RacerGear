#ifndef SCORES_H
#define SCORES_H
#include<iostream>
#include<fstream>
#include"Usuario.h"
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;
class Scores
{
    public:
        string PATH_ARCHIVO;
        multimap<int,Usuario*>mi_mapa;
        bool createNewUserBinary(string name);
        bool readFileBinary();
        int seekUser(string name);
        void printMap();
        bool setPuntosToPista(string user, int puntos, int pista);
        void seekRLP(int pista);
        int getRLP(string name);
        Scores();
        virtual ~Scores();
    protected:
    private:
};

#endif // SCORES_H
