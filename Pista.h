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

#ifndef PISTA_H
#define PISTA_H
#include "ListImage.h"
#include<iostream>
#include"Buttons.h"
#include "Car.h"

#include <map>
#include <vector>
#include<ctime>
using namespace std;

//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"
#include <vector>
#include "Font.h"

class Pista
{
    public:
        Receiver* receiver;
        float off_set_y, off_set_x;
        ListImage* road;
        ListImage* flags;
        int laps,cont;
        bool go;
        vector<Image*> contD;
        double time;
        bool getLose();
        void countdown();
        int seg;
        string player_name;
        clock_t start,stop;

        Font *display_time;

        Image* background;//, *bu, *bd;
        Car *car;
        vector<std::string> secuence;

        void logica();
        void draw();
        void init();
        void clear();
        void loadTrack(std::string);

        Pista();
        Pista(Car*,RosalilaGraphics*, Receiver*);
        Pista(Car*,RosalilaGraphics*, Receiver*,std::string);
        virtual ~Pista();
    protected:
    private:
    RosalilaGraphics* painter;
};

#endif // PISTA_H
