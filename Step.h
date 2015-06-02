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
        float x, y, scale, off_set_x, off_set_y;
        RosalilaGraphics* painter;

        Step(RosalilaGraphics* painter, std::string path);
        virtual ~Step();

        float getX();
        float getY();
        float getScale();
        float getOff_X();
        float getOff_Y();

        void setX(float x);
        void setY(float y);
        void setScale(float scale);
        void setOff_X(float right);
        void setOff_Y(float left);

        void addX(float x);
        void addY(float y);
        void addScale(float scale);
        void addOff_X(float right);
        void addOff_Y(float left);

        void init();

        void draw(RosalilaGraphics* painter);
    protected:
    private:
};

#endif // STEP_H

void queryData(Step *s, float *w, float *h, float *x, float *y);
