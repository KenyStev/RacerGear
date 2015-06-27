#ifndef SCORES_H
#define SCORES_H
#include<iostream>
#include<fstream>
#include"Usuario.h"
#include <stdlib.h>
#include <string.h>
#include <map>
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
using namespace std;
class Scores
{
    public:
        string PATH_ARCHIVO;
        multimap<int,Usuario*>mi_mapa;
        bool createNewUserBinary(string name);
        bool readFileBinary(RosalilaGraphics *painter);
        int seekUser(string name);
        bool setPuntosToPista(string user, int puntos, int pista);
        Scores();
        virtual ~Scores();
    protected:
    private:
};

#endif // SCORES_H
