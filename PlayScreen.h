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

#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "Screen.h"
#include "Game.h"
#include "Pista.h"
#include "Car.h"
#include "Font.h"

#include <map>
#include "Buttons.h"
#include "Scores.h"

class PlayScreen : public Screen
{
    public:
        BackButton* back_button;
        Image* background, *bu, *bd,*G_over;
        bool finish;
        string n="";
        int time, num_rt;
        Scores *scr;
        Pista *track;
        Car *player_car;
        map<int,Car*> cars;
        Font *display_laps;

        Game *game;
        PlayScreen(Game*);

        void loadCars(string);

        void show ();
        void render (RosalilaGraphics*);
//        void resize (int width, int height);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();

        virtual ~PlayScreen();
    protected:
    private:
};

#endif // PLAYSCREEN_H
