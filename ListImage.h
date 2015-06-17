#ifndef LISTIMAGE_H
#define LISTIMAGE_H

#include <iostream>
#include "Nodo.h"

using namespace std;

class ListImage
{
    public:
        int max_draw;
        Step *root;
        double root_scale, off_set;
        ListImage();
        ListImage(RosalilaGraphics *paint);
        virtual ~ListImage();
        void add(string path);
        void add(Step *nuevo);
        Step* pop();
        void draw(double off_set_x, double off_set_y);
        void draw(Step*,Step*,int,double off_set_x, double off_set_y);

        void clear();

        void reset();
        void flush(double flu);
    protected:

    private:
        RosalilaGraphics *painter;
};

#endif // LISTIMAGE_H
