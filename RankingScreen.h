#ifndef RANKINGSCREEN_H
#define RANKINGSCREEN_H


#include "Screen.h"
#include "Game.h"
#include "Scores.h"
#include "BackButton.h"


class RankingScreen : public Screen
{
    public:
        BackButton* back_button;
        Image *background, *bu, *bd;
        Scores *ranking;
        Game *game;
        RankingScreen(Game* game);
        void show ();
        void render (RosalilaGraphics* painter);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();

        virtual ~RankingScreen();
    protected:
    private:
};

#endif // RANKINGSCREEN_H
