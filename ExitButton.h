#ifndef EXITBUTTON_H
#define EXITBUTTON_H
#include"Button.h"

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

#endif // EXITBUTTON_H
