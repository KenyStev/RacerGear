#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "Game.h"
#include "PlayScreen.h"
#include "Screen.h"
//#include "Data.h"

#include "Buttons.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"
//#include "RankButton.h"
//#include "InstrButton.h"

class MenuScreen : public Screen
{
    public:
        Game *game;

        Image* fondo,*pu,*pd,*iu,*id,*ru,*rd,*eu,*ed;
        PlayButton *Pb;
        InstrButton *Ib;
        RankButton *Rb;
        ExitButton *Eb;

        int mouse_x, mouse_y;
        bool click;
        int centro_x,centro_y;

        MenuScreen(Game*);

        void show ();
        void render (RosalilaGraphics*);
//        void resize (int width, int height);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();

        void update();

        virtual ~MenuScreen();
    protected:
    private:
};

#endif // MENUSCREEN_H
