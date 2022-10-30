#ifndef TDALISTA_H_INCLUDED
#define TDALISTA_H_INCLUDED

#include "../Comun/comun.h"
#include <stdlib.h>
#include <string.h>

#ifdef TDA_LISTA_IMPL_ESTATICA
    #include "../TDAListaImplEstatica/TDAListaImplEstatica.h"
#else
    #include "../TDAListaImplDinamica/TDAListaImplDinamica.h"
#endif // TDA_LISTA_IMPL_ESTATICA

void crearLista(Lista* lp);
int insertarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
booleano eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
booleano listaVacia(Lista* pl);
booleano listaLlena(Lista* pl, size_t tamElem);
void ordenarLista(Lista* pl, Cmp cmp);
booleano eliminarDuplicadosDeListaOrd(Lista* pl, Cmp cmp);
booleano eliminarDuplicadosDeListaDesord(Lista* pl, Cmp cmp);
void vaciarLista(Lista* pl);
void recorrerLista(Lista *pl);

//Iterador
booleano crearIterador(Iterador* it, const Lista* pl);
booleano primeroDeLista(Iterador* it, void *elem, size_t tamElem);
booleano siguienteDeLista(Iterador* it, void* elem, size_t tamElem);
booleano haySiguienteDeLista(Iterador* it);
booleano finLista(Iterador* it);

#endif // TDALISTA_H_INCLUDED
