#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H
#include"Button.h"
#include"Pista.h"
#include "Game.h"
class PlayButton : public Button
{
    public:
        Game* game;
//        Pista * pista;
        void funcionamiento();
//        PlayButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter,Receiver* receiver);
        PlayButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter, Game* game);
        PlayButton();
        virtual ~PlayButton();
    protected:
    private:
};

#endif // PLAYBUTTON_H
