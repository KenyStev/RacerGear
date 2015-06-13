#ifndef PISTA_H
#define PISTA_H
#include "ListImage.h"
#include<iostream>
#include"BackButton.h"
using namespace std;

//SDL
#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"

class Pista
{
    public:
    BackButton* back_button;
    Receiver* receiver;
    float off_set_y, off_set_x;
    ListImage* miLista1;
    ListImage* miLista2;
    Image* background, *bu, *bd;
    void logica();
    void draw();
    void init();

        Pista();
        Pista(RosalilaGraphics *paint, Receiver* receiver);
        virtual ~Pista();
    protected:
    private:
    RosalilaGraphics* painter;
};

#endif // PISTA_H
