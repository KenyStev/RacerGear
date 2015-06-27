#ifndef CAR_H
#define CAR_H

//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"
#include<vector>

class Car
{
    public:
        bool turn = false, outOfRoad, first, second,third,fourth,fifth, speed_up, danger, lose;
        RosalilaGraphics * painter;
        double x, y, scale, marker_x,marker_y,marker_y_max, marker_speed;
        double a, v, v_max,maximum,time;
        double LEFT_MAX = 590, RIGHT_MAX = -590, TURN, CHANGE_TURN=5;
        double off_set_x,hurt;

        vector<Image*> warning;
        bool getLose();
        void warningAnimation();
        int warning_actual;

        Image *car,*velocimeter,*marker;
        map<string,Image*> state;
        map<string,Image*> velocimeter_state;
        SDL_Rect wheels;//wheel_left

        Car(RosalilaGraphics *p,string);
        Car();
        virtual ~Car();
        void initCar();

        void update(Receiver *r);
        void draw();
    protected:
    private:
};

#endif // CAR_H
