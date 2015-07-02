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
