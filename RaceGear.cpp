#include "RaceGear.h"

RaceGear::RaceGear()
{
    PLAY = new PlayScreen(this);
    MENU = new MenuScreen(this);
    SELECT = new SelectScreen(this);
    RANKING = new RankingScreen(this);
    INSTRUCTION = new InsScreen(this);
}

RaceGear::~RaceGear()
{
    delete PLAY;
    delete MENU;
    delete SELECT;
    delete RANKING;
    delete INSTRUCTION;
}

void RaceGear::create()
{
    selected_car = 0;
    selected_track = "pista_novato.xml";
    name_player="";
    seg=0;

    setScreen(MENU);
}
string RaceGear::getSelectedTrack(){
    return selected_track;
}



