#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#define VERDADERO 1
#define FALSO 0

#define MIN(x,y) ((x)<(y))?(x):(y)

#define TAM_PILA 5000

typedef struct
{
    char v_pila[TAM_PILA];
    size_t tope;
}Pila;

void crear_pila(Pila *pp);
int apilar(Pila *pp, void *elem, size_t tamelem);
int desapilar(Pila *pp, void *elem, size_t tamelem);
void vaciar_pila(Pila *pp);
int pila_llena(const Pila* pp, size_t tamelem);
int ver_tope_pila(const Pila* pp, void* elem, size_t tamelem);



#endif // MACROS_H_INCLUDED
