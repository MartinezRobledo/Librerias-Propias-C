#include "macros.h"

void crear_pila(Pila *pp)
{
    pp->tope=0;
}

int apilar(Pila *pp, void *elem, size_t tamelem)
{
    if(tamelem+sizeof(size_t) > TAM_PILA-pp->tope)
        return FALSO;

    memcpy(pp->v_pila+pp->tope, elem, tamelem);
    pp->tope += tamelem;
    *(size_t*)(pp->v_pila+pp->tope) = tamelem;
    pp->tope += sizeof(size_t);
    return VERDADERO;
}

int desapilar(Pila *pp, void *elem, size_t tamelem)
{
    if(pp->tope == 0)
        return FALSO;
    pp->tope -= sizeof(size_t);
    size_t tamelemap = *(size_t*)(pp->v_pila + pp->tope);
    pp->tope -= tamelemap;
    memcpy(elem, pp->v_pila + pp->tope, MIN(tamelem,tamelemap));
    return VERDADERO;
}

void vaciar_pila(Pila *pp)
{
    pp->tope=0;
}

int pila_llena(const Pila* pp, size_t tamelem)
{
    return (tamelem + sizeof(size_t) > TAM_PILA-pp->tope);
}

int pila_vacia(const Pila* pp)
{
    return pp->tope == 0;
}

int ver_tope_pila(const Pila* pp, void* elem, size_t tamelem)
{
    if(pp->tope == 0)
        return FALSO;
    size_t tope_cpy = pp->tope;
    tope_cpy -= sizeof(size_t);
    size_t tamelemap = *(size_t*)(pp->v_pila + tope_cpy);
    tope_cpy -= tamelemap;
    memcpy(elem, pp->v_pila + tope_cpy, MIN(tamelem,tamelemap));
    return VERDADERO;
}
