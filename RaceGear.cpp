#include "RaceGear.h"

RaceGear::RaceGear()
{
    PLAY = new PlayScreen(this);
    MENU = new MenuScreen(this);
    SELECT = new SelectScreen(this);
}

RaceGear::~RaceGear()
{
    //dtor
}

void RaceGear::create()
{
    selected_car = 0;
    selected_track = "pista_novato.xml";
    setScreen(MENU);
}



