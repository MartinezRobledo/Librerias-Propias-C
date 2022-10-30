#include "ordenamiento.h"

void* buscarMenor(void* inicio, void* fin, size_t tamElem, Cmp cmp);
void intercambiar(void* a, void* b, size_t tamElem);

void ordenarGenBurbujeo(void* vector, int ce, size_t tamElem, Cmp cmp);


void ordenarGenSeleccion(void* vector, int ce, size_t tamElem, Cmp cmp)
{
    void* i, *menor;
    void* ultimo = vector + (ce -1)* tamElem;
    for(i = vector; i < ultimo; i += tamElem)
    {
        menor = buscarMenor(i, ultimo, tamElem, cmp);

        if(menor != i)
            intercambiar(i, menor, tamElem);
    }
}

void* buscarMenor(void* inicio, void* fin, size_t tamElem, Cmp cmp)
{
    void* j, *menor;
    menor = inicio;

    for(j = inicio + tamElem; j <= fin; j += tamElem)
    {
        if(cmp(j,  menor) < 0)
            menor = j;
    }

    return menor;
}

void intercambiar(void* a, void* b, size_t tamElem)
{
    char aux[tamElem];
    //void* aux = malloc(tamElem); //reserva memoria dinamica
    memcpy(aux, a, tamElem);
    memcpy(a, b, tamElem);
    memcpy(b, aux, tamElem);
    //free(aux);                   //libera la memoria pedida
}

void ordenarGenInsercion(void* vector, int ce, size_t tamElem, Cmp cmp);
