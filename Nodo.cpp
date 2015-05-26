#include "Nodo.h"

Nodo::Nodo(Image *texture)
{
    this->frame = texture;
    this->next = NULL;
}

Nodo::~Nodo()
{
    delete frame;
    delete next;
}
