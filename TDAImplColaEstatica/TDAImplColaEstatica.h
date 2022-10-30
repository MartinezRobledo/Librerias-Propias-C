#ifndef TDAIMPLCOLAESTATICA_H_INCLUDED
#define TDAIMPLCOLAESTATICA_H_INCLUDED

#include <stddef.h>

#define TAM_COLA    100

typedef struct
{
    char vec[TAM_COLA];
    unsigned frente;
    unsigned fondo;
    size_t tamDisponible;
}
Cola;



#endif // TDAIMPLCOLAESTATICA_H_INCLUDED
