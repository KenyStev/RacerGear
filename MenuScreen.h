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
