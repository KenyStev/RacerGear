#include "RaceGear.h"

RaceGear::RaceGear()
{
    PLAY = new PlayScreen(this);
    MENU = new MenuScreen(this);
}

RaceGear::~RaceGear()
{
    //dtor
}

void RaceGear::create()
{
    setScreen(PLAY);
}

//void RaceGear::setScreen(Screen*Screen)
//{
//    if (this->screen != NULL) this->screen->hide();
//        this->screen = screen;
//        if (this->screen != NULL) {
//            this->screen->show();
//    }
//}

//void RaceGear::setScreen(int index)
//{
//    switch(index)
//    {
//        case 0: setScreen(PLAY); break;
//        case 1: setScreen(MENU); break;
//    }
//}



