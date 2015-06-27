#ifndef RANKBUTTON_H
#define RANKBUTTON_H
#include"Button.h"
#include "Game.h"

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

#endif // RANKBUTTON_H
