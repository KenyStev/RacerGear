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

#ifndef BUTTONS_H
#define BUTTONS_H

#include "Button.h"
#include "Game.h"

class CarButton : public Button
{
    public:
        int num;
        CarButton(int num,int x_position, int y_position, Image* up, Image* down, RosalilaGraphics* painter);
        void funcionamiento();
        virtual ~CarButton();
    protected:
    private:
};

class TrackButton : public Button
{
    public:
        string name;
        int num_pista;
        TrackButton(int i,string name,int x_position, int y_position, Image* up, Image* down, RosalilaGraphics* painter);
        void funcionamiento();
        virtual ~TrackButton();
};

class PlayButton : public Button
{
    public:
        Game* game;
        void funcionamiento();
        PlayButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game);
        PlayButton();
        virtual ~PlayButton();
    protected:
    private:
};

class BackButton : public Button
{
    public:
        Game* game;
        void funcionamiento();
        BackButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter,Game*);
        BackButton();
        virtual ~BackButton();
    protected:
    private:
};


class ExitButton: public Button
{
    public:
        void funcionamiento();
        ExitButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter);
        ExitButton();
        virtual ~ExitButton();
    protected:
    private:
};

class InstrButton : public Button
{
    public:
        Game *game;
        void funcionamiento();
        InstrButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game);
        InstrButton();
        virtual ~InstrButton();
    protected:
    private:
};

class RankButton : public Button
{
    public:
        Game *game;
        void funcionamiento();
        RankButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game);
        RankButton();
        virtual ~RankButton();
    protected:
    private:
};

#endif // BUTTONS_H
