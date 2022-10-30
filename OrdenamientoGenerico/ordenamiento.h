#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <memory.h>

typedef int (*Cmp)(const void*, const void*);

void ordenarGenBurbujeo(void* vector, int ce, size_t tamElem, Cmp cmp);
void ordenarGenSeleccion(void* vector, int ce, size_t tamElem, Cmp cmp);
void ordenarGenInsercion(void* vector, int ce, size_t tamElem, Cmp cmp);


#endif // ORDENAMIENTO_H_INCLUDED
