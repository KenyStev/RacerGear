#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "Screen.h"
#include "Game.h"
#include "Pista.h"
#include "Car.h"

//buttons
#include "PlayButton.h"
#include "ExitButton.h"
#include "InstrButton.h"
#include "RankButton.h"

class PlayScreen : public Screen
{
    public:
        BackButton* back_button;
        Image* background, *bu, *bd;

        Pista *track;
        Car *player_car;
        Game *game;
        PlayScreen(Game*);

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
