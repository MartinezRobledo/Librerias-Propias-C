#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <stddef.h>
#include <stdlib.h>
#include <memory.h>

#include "../Comun/comun.h"

typedef struct SNodo
{
    void* elem;
    size_t tamElem;
    struct SNodo* sig;
}
Nodo;

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);

#endif // NODO_H_INCLUDED
