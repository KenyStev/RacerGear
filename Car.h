/**
* Copyright (C) Kevin J. Estevez (kenystev) and Luis C. Isaula (lisaula)
*
* GNU GENERAL PUBLIC LICENSE Version 2
* The licenses for most software are designed to take away your
* freedom to share and change it.  By contrast, the GNU General Public
* License is intended to guarantee your freedom to share and change free
* software--to make sure the software is free for all its users.  This
* General Public License applies to most of the Free Software
* Foundation's software and to any other program whose authors commit to
* using it.
*/

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
        int warning_actual,cambio=0;

        Image *car,*velocimeter,*marker, *G_over;
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
