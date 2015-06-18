#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H
#include"Button.h"
#include"Pista.h"
class PlayButton : public Button
{
    public:
//        Pista * pista;
        void funcionamiento();
//        PlayButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter,Receiver* receiver);
        PlayButton(int x_position, int y_position, Image* up, Image* down,RosalilaGraphics* painter);
        PlayButton();
        virtual ~PlayButton();
    protected:
    private:
};

#endif // PLAYBUTTON_H
