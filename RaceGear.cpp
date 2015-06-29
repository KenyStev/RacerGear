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
    //dtor
}
void RaceGear::setTime(int time){
    this->time=time;
}

void RaceGear::create()
{
    selected_car = 0;
    time =0;
    selected_track = "pista_novato.xml";
    setScreen(MENU);
}
string RaceGear::getSelectedTrack(){
    return selected_track;
}



