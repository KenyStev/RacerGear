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
