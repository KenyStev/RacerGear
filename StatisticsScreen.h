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

#ifndef STATISTICSSCREEN_H
#define STATISTICSSCREEN_H
#include "Screen.h"
#include "Game.h"
#include "Buttons.h"
#include "Scores.h"
#include "Font.h"
#include <vector>

class StatisticsScreen : public Screen
{
    public:
        Game *game;
        Font *font;
        int mi_posicion=0;
        string track,name;
        int car,time,stars, s;
        map<int,Image*>cars;
        map<int,string>rts;
        vector<Image*> estrellas;
        BackButton *menu;
        PlayButton *reiniciar;
        Image* background,*mu,*md,*ru,*rd;
        Image *carro;
        Scores *ranking;
        StatisticsScreen(Game* game);
        void paintStars(int cont);
        int calculateStars(int seg, int pista);
        void show ();
        void render (RosalilaGraphics* painter);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();
        virtual ~StatisticsScreen();
    protected:
    private:
};

#endif // STATISTICSSCREEN_H
