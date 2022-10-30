#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#define CAPACIDAD_VECTOR 5

#include "../Comun/comun.h"

typedef struct
{
    int vec[CAPACIDAD_VECTOR];
    int ce;
}
Vector;

void crearVector(Vector* vector);
void mostrarVector(Vector* vector);
booleano insertarEnVectorAlFinal(Vector* vector, int valor);
int insertarVectorEnOrdenConDuplicado(Vector* vector, int valor);
int buscarEnVectorOrdenado(const Vector* vector, int valor);
booleano eliminarDeVectorOrdenadoPorValor(Vector* vector, int valor);
booleano eliminarPrimeraAparicion(Vector* vector, int valor);
booleano eliminarDeVectorPorPosicion(Vector* vector, int posicion);
int insertarVectorPorPosicion(Vector* vector, int valor, int posicion);
void eliminarTodasLasApariciones(Vector* vector, int valor);

#endif // VECTOR_H_INCLUDED
