#ifndef LISTIMAGE_H
#define LISTIMAGE_H

#include <iostream>
#include "Step.h"
#include "Car.h"

using namespace std;

class ListImage
{
    public:
        int max_draw,size,pops;
        Step *root;
        double root_scale, off_set;
        ListImage();
        ListImage(RosalilaGraphics *paint);
        virtual ~ListImage();
        void add(string path);
        void add(int,string path);
        void add(Step *nuevo);
        Step* pop();
        void draw(double off_set_x, double off_set_y);
        void draw(Car*,double off_set_x, double off_set_y);//chancho
        void draw(Car*,Step*,Step*,int,double off_set_x, double off_set_y);
        void checkColosions(Car*,Step*);
        void loadSteps(std::string);
        bool isMeta();

        void clear();
    protected:

    private:
        RosalilaGraphics *painter;
        map<std::string,Image*> texturas;
};

#endif // LISTIMAGE_H
