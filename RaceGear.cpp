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

#include "RaceGear.h"

RaceGear::RaceGear()
{
    PLAY = new PlayScreen(this);
    MENU = new MenuScreen(this);
    SELECT = new SelectScreen(this);
    RANKING = new RankingScreen(this);
    INSTRUCTION = new InsScreen(this);
    STATISTICS = new StatisticsScreen(this);
}

RaceGear::~RaceGear()
{
    delete PLAY;
    delete MENU;
    delete SELECT;
    delete RANKING;
    delete INSTRUCTION;
    delete STATISTICS;
}

void RaceGear::create()
{
    selected_car = 0;
    selected_track = "pista_novato.xml";
    name_player="";
    seg=0;
    id_pista=1;

    setScreen(MENU);
}
string RaceGear::getSelectedTrack(){
    return selected_track;
}



