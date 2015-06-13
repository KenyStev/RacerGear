#ifndef INSTRBUTTON_H
#define INSTRBUTTON_H
#include"Button.h"

class InstrButton : public Button
{
    public:
        void funcionamiento();
        InstrButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter);
        InstrButton();
        virtual ~InstrButton();
    protected:
    private:
};

#endif // INSTRBUTTON_H
