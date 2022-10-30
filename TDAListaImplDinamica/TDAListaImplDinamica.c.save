#include "../TDALista/TDALista.h"
#define TDA_LISTA_IMPL_DINAMICA

void crearLista(Lista* pl)
{
    *pl = NULL;
}

int insertarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(*pl && cmp(elem, (*pl)->elem) == 0)
        return DUPLICADO;

    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return SIN_MEM;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}

booleano eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl= &(*pl)->sig;

    if(!*pl || cmp(elem, (*pl)->elem) < 0)
        return FALSO;

    Nodo* nae = *pl;    //guarda la ubicacion del siguiente
    *pl = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return VERDADERO;
}

booleano crearIterador(Iterador *it, const Lista *pl)
{
    it->primero = *pl;
    it->act = NULL;

    if(!*pl)
        return FALSO;

    return VERDADERO;
}

booleano primeroDeLista(Iterador* it, void* elem, size_t tamElem)
{
    if(!it->primero)
        return FALSO;

    it->act = it->primero;

    memcpy(elem, it->act->elem, min(tamElem, it->act->tamElem));

    return VERDADERO;
}

booleano siguienteDeLista(Iterador* it, void* elem, size_t tamElem)
{
    if(!it->act)
        return FALSO;

    it->act = it->act->sig;

    if(!it->act)
        return FALSO;

    memcpy(elem, it->act->elem, min(tamElem, it->act->tamElem));

    return VERDADERO;
}

booleano haySiguienteDeLista(Iterador* it)
{
    if(!it->act)
        return FALSO;

    return it->act->sig != NULL;
}

booleano finLista(Iterador* it)
{
    return !it->act;
}

booleano eliminarDuplicadosDeListaDesord(Lista *pl, Cmp cmp)
{
    if(!*pl)
        return FALSO;

    Lista *ppl = pl;

    while(*pl)
    {
        ppl = &(*pl)->sig;

        while(*ppl)
        {
            if(cmp((*pl)->elem, (*ppl)->elem)!=0)
                ppl = &(*pl)->sig;
            else
            {
                Nodo* nae = *ppl;
                *ppl = nae->sig;
                destruirNodo(nae, nae->elem, nae->tamElem);
            }
        }

        pl = &(*pl)->sig;
    }

    return VERDADERO;
}

void recorrerLista(Lista *pl)
{
    while(*pl)
    {
        printf("El elemento actual de la lista es: %d\n", *(int*)(*pl)->elem);
        pl = &(*pl)->sig;
    }
}
