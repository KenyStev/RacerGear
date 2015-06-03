#ifndef LISTIMAGE_H
#define LISTIMAGE_H

#include <iostream>
#include "Nodo.h"

using namespace std;

class ListImage
{
    public:
        Nodo *root;
        float root_scale, off_set;

        ListImage(RosalilaGraphics *paint);
        virtual ~ListImage();
        void add(string path);
        void add(Nodo *nuevo);
        Nodo* pop();
        void draw(float off_set);

        void reset();
        void flush(float flu);
    protected:

    private:
        RosalilaGraphics *painter;
};

#endif // LISTIMAGE_H
