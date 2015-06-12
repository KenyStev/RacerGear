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
        double x, y, scale;
        double a, v;
        Image *car;

        Car(RosalilaGraphics *p);
        virtual ~Car();

        void draw(RosalilaGraphics *painter);
    protected:
    private:
};

#endif // CAR_H
