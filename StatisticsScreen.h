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
        BackButton *reiniciar, *menu;
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
