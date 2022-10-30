#ifndef TDACOLA_H_INCLUDED
#define TDACOLA_H_INCLUDED

#ifdef TDA_COLA_IMPLEMENTACION_ESTATICA
    #include "TDAImplColaEstatica.h"
#else
    #include "TDAImplColaDinamica.h"
#endif

#include <memory.h>


#define min(a, b) ((a)<(b) ? (a) : (b))


typedef enum
{
    FALSO, VERDADERO
}
booleano;

void crearCola(Cola* pc);
booleano encolar(Cola* pc, const void* elem, size_t tamElem);
booleano desencolar(Cola* pc, void* elem, size_t tamElem);
booleano verFrenteDeCola(Cola* pc, void*elem, size_t tamElem);
booleano colaVacia(Cola* pc);
booleano colaLLena(Cola* pc, size_t tamElem);
void vaciarCola(Cola* pc);

#endif // TDACOLA_H_INCLUDED
