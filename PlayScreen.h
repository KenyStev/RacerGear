#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include "Screen.h"
#include "Game.h"
#include "Pista.h"
#include "Car.h"
#include "Font.h"

#include <map>

//buttons
#include "Buttons.h"
//#include "ExitButton.h"
//#include "InstrButton.h"
//#include "RankButton.h"
#include "Scores.h"

class PlayScreen : public Screen
{
    public:
        BackButton* back_button;
        Image* background, *bu, *bd,*G_over;
        bool finish;
        string n="";
        int time, num_rt,notexitst=1;
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
