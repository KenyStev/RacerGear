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
        string name_rt="";
        PlayButton *play_button;
        Image *background, *car_chosed;
        map<int,Image*>cars;
        map<int,string>rts;
        string name;
        Font *display,*nuevo;

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
