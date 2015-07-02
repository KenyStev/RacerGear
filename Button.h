/**
* @author: Luis C. Isaula (lisaula)
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

#ifndef BUTTON_H
#define BUTTON_H
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

#include "Rosalila/system.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include<iostream>
using namespace std;
//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"

class Button
{
    public:
        RosalilaGraphics* painter;
    //    Receiver *receiver;
        Image* img_up;
        Image* img_dwn;
        SDL_Rect rect_img;
        bool clickLeft;
        int mouse_x;
        int mouse_y;
        int x;
        int y;
        float xMinima; // Estos atributos sirven para poner las coordenadas para pulsar el botón.
        float yMinima;
        float xMaxima;
        float yMaxima;
        bool quit;
        void update(int x, int y, bool click);
        void setMouse(int x, int y, bool click);
        bool sePulsaBoton(int x, int y, bool click);
        bool mouseEncima(int x, int y, bool click);
        void draw(int x, int y, bool click);
        bool clicked(int M_x, int M_y, bool click);
        virtual void funcionamiento()=0;
        Button(int x_position, int y_position, Image* up, Image* down, RosalilaGraphics* painter);
        Button();
        virtual ~Button();
    protected:
    private:
};

#endif // BUTTON_H
