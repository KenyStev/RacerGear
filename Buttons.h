#ifndef BUTTONS_H
#define BUTTONS_H

#include "Button.h"

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
        TrackButton(string name,int x_position, int y_position, Image* up, Image* down, RosalilaGraphics* painter);
        void funcionamiento();
        virtual ~TrackButton();
};

#endif // BUTTONS_H
