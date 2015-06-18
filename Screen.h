#ifndef SCREEN_H
#define SCREEN_H
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"

class Screen
{
    public:
        Screen();

        virtual void show ()=0;
        virtual void render (RosalilaGraphics*)=0;
//        void resize (int width, int height);
        virtual void pause ()=0;
        virtual void resume ()=0;
        virtual void hide ()=0;
        virtual void dispose ()=0;

        virtual ~Screen();
    protected:
    private:
};

#endif // SCREEN_H
