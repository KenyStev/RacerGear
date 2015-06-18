#ifndef RACEGEAR_H
#define RACEGEAR_H

#include "Game.h"
#include "PlayScreen.h"
#include "MenuScreen.h"

//#include "Data.h"

class RaceGear : public Game
{
    public:
        PlayScreen *PLAY;
        MenuScreen *MENU;
        RaceGear();

//        void setScreen(Screen *screen);
//        void setScreen(int);

        void create();
        virtual ~RaceGear();
    protected:
    private:
};

#endif // RACEGEAR_H
