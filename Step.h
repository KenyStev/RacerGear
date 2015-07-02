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

#include <map>

#ifndef STEP_H
#define STEP_H

//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"

class Step : public Image
{
    public:
        Step* next;

        double x, y, scale, off_set_x, off_set_y;
        RosalilaGraphics* painter;

        SDL_Rect rect_left,rect_right,rect_center,
                        border_left,border_right;
        bool hit_left,hit_right,hit_center,borders;
        bool isMeta;
        double hurt;

        Step(RosalilaGraphics* painter, std::string path);
        Step(RosalilaGraphics*, Image*);
        virtual ~Step();

        double getX();
        double getY();
        double getScale();
        double getOff_X();
        double getOff_Y();

        void setX(double x);
        void setY(double y);
        void setScale(double scale);
        void setOff_X(double right);
        void setOff_Y(double left);

        void addX(double x);
        void addY(double y);
        void addScale(double scale);
        void addOff_X(double right);
        void addOff_Y(double left);

        void setHit_Left(bool);
        void setHit_Right(bool);
        void setHit_Center(bool);
        void setBorders();

        void init(Step *tmp);


        void draw(RosalilaGraphics* painter);
    protected:
    private:
};

#endif // STEP_H

void queryData(Step *s, double *w, double *h, double *x, double *y);
