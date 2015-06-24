#ifndef SELECTSCREEN_H
#define SELECTSCREEN_H
#include "Screen.h"
#include "Game.h"

class SelectScreen : public Screen
{
    public:
        Game *game;
        SelectScreen(Game*);
        void show ();
        void render (RosalilaGraphics*);
//        void resize (int width, int height);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();
        virtual ~SelectScreen();
    protected:
    private:
};

#endif // SELECTSCREEN_H