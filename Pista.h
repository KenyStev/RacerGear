#ifndef PISTA_H
#define PISTA_H
#include "ListImage.h"
#include<iostream>
#include"BackButton.h"
#include "Car.h"

#include <map>
#include <vector>
#include<ctime>
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
    Receiver* receiver;
    float off_set_y, off_set_x;
    ListImage* road;
    ListImage* miLista2;
    int laps;
    double time;
    bool getLose();
    int seg;
    string player_name;
    clock_t start,stop;

    Image* background;//, *bu, *bd;
    Car *car;
    vector<std::string> secuence;

    void logica();
    void draw();
    void init();
    void clear();
    void loadTrack(std::string);

        Pista();
        Pista(Car*,RosalilaGraphics*, Receiver*);
        Pista(Car*,RosalilaGraphics*, Receiver*,std::string);
        virtual ~Pista();
    protected:
    private:
    RosalilaGraphics* painter;
};

#endif // PISTA_H
