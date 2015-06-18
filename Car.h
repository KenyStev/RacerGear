#ifndef CAR_H
#define CAR_H

//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"

class Car
{
    public:
        bool turn = false;
        double x, y, scale;
        double a, v, v_max;
        double LEFT_MAX = 590, RIGHT_MAX = -590, TURN, CHANGE_TURN=5;
        double off_set_x;

        Image *car;
        map<string,Image*> state;

        Car(RosalilaGraphics *p);
        virtual ~Car();

        void update(Receiver *r);
        void draw(RosalilaGraphics *painter);
    protected:
    private:
};

#endif // CAR_H
