#ifndef LISTIMAGE_H
#define LISTIMAGE_H

#include <iostream>
#include "Nodo.h"

using namespace std;

class ListImage
{
    public:
        Nodo *root;
        float scale, off_set,acu;

        ListImage(RosalilaGraphics *paint);
        virtual ~ListImage();
        void add(string path);
        Image* pop();
        void draw(float off_set);
    protected:

    private:
        RosalilaGraphics *painter;
};

#endif // LISTIMAGE_H
