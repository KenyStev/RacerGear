#ifndef INSSCREEN_H
#define INSSCREEN_H

#include "Game.h"
#include "Screen.h"
#include "BackButton.h"
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
