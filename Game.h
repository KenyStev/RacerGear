#ifndef GAME_H
#define GAME_H
#include "Screen.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaInputs/Receiver.h"

class Game
{
    public:
        Game();
        Screen *screen;
        RosalilaGraphics* rosalila_graphics;
        Receiver* receiver;

        virtual ~Game();

        virtual void create()=0;

        void dispose();
        void pause();
        void resume();
        void render();

        void setScreen(Screen *screen);
//        virtual void setScreen(int)=0;
        Screen* getScreen();
    protected:
    private:
};

#endif // GAME_H
