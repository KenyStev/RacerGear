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
        float x, y, scale, right, left, off_set_y;

        Step(RosalilaGraphics* painter, std::string path);
        virtual ~Step();

        float getX();
        float getY();
        float getScale();
        float getRight();
        float getLeft();

        void setX(float x);
        void setY(float y);
        void setScale(float scale);
        void setRight(float right);
        void setLeft(float left);

        void addX(float x);
        void addY(float y);
        void addScale(float scale);
        void addRight(float right);
        void addLeft(float left);

        void draw(RosalilaGraphics* painter);
    protected:
    private:
};

#endif // STEP_H
