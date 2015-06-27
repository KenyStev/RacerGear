#ifndef INSTRBUTTON_H
#define INSTRBUTTON_H
#include"Button.h"
#include"Game.h"

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

#endif // INSTRBUTTON_H
