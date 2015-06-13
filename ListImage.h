#ifndef LISTIMAGE_H
#define LISTIMAGE_H

#include <iostream>
#include "Nodo.h"

using namespace std;

class ListImage
{
    public:
        Nodo *root;
        double root_scale, off_set;
        int Size;
        ListImage();
        ListImage(RosalilaGraphics *paint);
        virtual ~ListImage();
        void add(string path);
        void add(Nodo *nuevo);
        Nodo* pop();
        void draw(double off_set_x, double off_set_y);

        void reset();
        void flush(double flu);
    protected:

    private:
        RosalilaGraphics *painter;
};

#endif // LISTIMAGE_H
