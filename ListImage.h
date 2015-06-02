#ifndef LISTIMAGE_H
#define LISTIMAGE_H

#include <iostream>
#include "Nodo.h"

using namespace std;

class ListImage
{
    public:
        Nodo *root;
        float scale, off_set;

        ListImage(RosalilaGraphics *paint);
        virtual ~ListImage();
        void add(string path, float scale);
        void add(Nodo *nuevo);
        Step* pop();
        void draw(float off_set);
    protected:

    private:
        RosalilaGraphics *painter;
};

#endif // LISTIMAGE_H
