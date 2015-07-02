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

#ifndef RACEGEAR_H
#define RACEGEAR_H

#include "Game.h"
#include "PlayScreen.h"
#include "MenuScreen.h"
#include "SelectScreen.h"
#include "RankingScreen.h"
#include "InsScreen.h"
#include "StatisticsScreen.h"

//#include "Data.h"

class RaceGear : public Game
{
    public:
        int selected_car;
        string selected_track;
        int time;

        //datos del jugador
        string name_player;
        int seg;
        int id_pista;

        PlayScreen *PLAY;
        MenuScreen *MENU;
        SelectScreen *SELECT;
        RankingScreen *RANKING;
        InsScreen *INSTRUCTION;
        StatisticsScreen *STATISTICS;
        RaceGear();
        void create();
        string getSelectedTrack();
        virtual ~RaceGear();
    protected:
    private:
};

#endif // RACEGEAR_H
