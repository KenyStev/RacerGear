#ifndef RACEGEAR_H
#define RACEGEAR_H

#include "Game.h"
#include "PlayScreen.h"
#include "MenuScreen.h"
#include "SelectScreen.h"
#include "RankingScreen.h"
#include "InsScreen.h"

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

        PlayScreen *PLAY;
        MenuScreen *MENU;
        SelectScreen *SELECT;
        RankingScreen *RANKING;
        InsScreen *INSTRUCTION;
        RaceGear();

//        void setScreen(Screen *screen);
//        void setScreen(int);
        void create();
        string getSelectedTrack();
        virtual ~RaceGear();
    protected:
    private:
};

#endif // RACEGEAR_H
