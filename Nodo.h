#ifndef NODO_H
#define NODO_H

#include "SDL2/SDL.h"
#include "Rosalila/RosalilaUtility/RosalilaUtility.h"
#include "Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "Rosalila/RosalilaSound/RosalilaSound.h"

#include "Step.h"

class Nodo
{
    public:
        Image* frame;
        Nodo* next;

        Nodo(Image *texture);
        virtual ~Nodo();
    protected:
    private:
};

#endif // NODO_H
