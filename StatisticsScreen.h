#ifndef STATISTICSSCREEN_H
#define STATISTICSSCREEN_H
#include "Screen.h"
#include "Game.h"
#include "Buttons.h"
#include "Scores.h"
#include "Font.h"
#include<map>

class StatisticsScreen : public Screen
{
    public:
        Game *game;
        Font *font;
        int mi_posicion;
        string track,nombre_pista="";
        int car,time;
        map<int,Image*>cars;
        BackButton *reiniciar, *menu;
        Image* background,*mu,*md,*ru,*rd,*carro;
        Scores *ranking;
        StatisticsScreen(Game* game);
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
