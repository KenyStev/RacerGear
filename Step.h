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
        //prueba step-nodo
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

//        void init();
//        void init(double scale, double x, double y);
        void init(Step *tmp);


        void draw(RosalilaGraphics* painter);
    protected:
    private:
};

#endif // STEP_H

void queryData(Step *s, double *w, double *h, double *x, double *y);
