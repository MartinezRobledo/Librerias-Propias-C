#include "Nodo.h"

Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return NULL;
    }

    memcpy(elemNodo, elem, tamElem);

    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->sig = NULL;

    return nue;
}

void destruirNodo(Nodo* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}
