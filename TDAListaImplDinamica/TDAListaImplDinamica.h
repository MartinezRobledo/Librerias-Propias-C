#ifndef TDALISTAIMPLDINAMICA_H_INCLUDED
#define TDALISTAIMPLDINAMICA_H_INCLUDED

#include "../Nodo/Nodo.h"
#include <stdio.h>

typedef Nodo* Lista;

typedef struct
{
    Nodo* primero;
    Nodo* act;
}
Iterador;

#endif // TDALISTAIMPLDINAMICA_H_INCLUDED
