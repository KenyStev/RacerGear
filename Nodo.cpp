#include "Nodo.h"

Nodo::Nodo(Step *texture)
{
    this->frame = texture;
    this->next = NULL;
}

Nodo::~Nodo()
{
    delete frame;
    delete next;
}
