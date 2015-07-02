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

#ifndef INSSCREEN_H
#define INSSCREEN_H

#include "Game.h"
#include "Screen.h"
#include "Buttons.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"

class InsScreen: public Screen
{
    public:
        Game* game;
        Image * fondo, *bd,*bu;
        BackButton* back_button;
        InsScreen(Game* game);
        void show ();
        void render (RosalilaGraphics *painter);
//        void resize (int width, int height);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();
        virtual ~InsScreen();
    protected:
    private:
};

#endif // INSSCREEN_H
