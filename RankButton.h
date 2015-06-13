#ifndef RANKBUTTON_H
#define RANKBUTTON_H
#include"Button.h"

class RankButton : public Button
{
    public:
        void funcionamiento();
        RankButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter);
        RankButton();
        virtual ~RankButton();
    protected:
    private:
};

#endif // RANKBUTTON_H
