#ifndef SELECTSCREEN_H
#define SELECTSCREEN_H
#include "Screen.h"
#include "Game.h"
#include "Buttons.h"
#include "Font.h"
#include <vector>

class SelectScreen : public Screen
{
    public:
        vector<CarButton*> buttons;
        vector<TrackButton*> tracks;
        PlayButton *play_button;
        string name;
        Font *display;

        void loadCars();
        void loadTracks();

        Game *game;
        SelectScreen(Game*);

        void catchName();

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
