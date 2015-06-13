#ifndef BACKBUTTON_H
#define BACKBUTTON_H
#include"Button.h"
class BackButton : public Button
{
    public:
        void funcionamiento();
        BackButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter);
        BackButton();
        virtual ~BackButton();
    protected:
    private:
};

#endif // BACKBUTTON_H
