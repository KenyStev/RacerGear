#ifndef RACEGEAR_H
#define RACEGEAR_H

#include "Game.h"
#include "PlayScreen.h"
#include "MenuScreen.h"
#include "SelectScreen.h"

//#include "Data.h"

class RaceGear : public Game
{
    public:
        int selected_car;
        string selected_track;

        PlayScreen *PLAY;
        MenuScreen *MENU;
        SelectScreen *SELECT;

        RaceGear();

//        void setScreen(Screen *screen);
//        void setScreen(int);

        void create();
        virtual ~RaceGear();
    protected:
    private:
};

#endif // RACEGEAR_H
