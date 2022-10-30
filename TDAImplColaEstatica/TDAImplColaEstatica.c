#define TDA_COLA_IMPLEMENTACION_ESTATICA
#include "../TDA_COLA.h"

void encolarSegmentado(Cola* pc, const void* dato, size_t tamDato);
void verFrenteSegmentado(const Cola* pc, void* dato, size_t tamDato, size_t tanDatoEncolado);
void desencolarSegmentado(Cola* pc, void* dato, size_t tamDato, size_t tamDatoEncolado);

void crearCola(Cola* pc)
{
    pc->frente = pc->fondo = 0;
    pc->tamDisponible = TAM_COLA;
}

booleano encolar(Cola* pc, const void* elem, size_t tamElem)
{
    if(tamElem + sizeof(size_t) > pc->tamDisponible)
        return FALSO;

    encolarSegmentado(pc, &tamElem, sizeof(tamElem));
    encolarSegmentado(pc, elem, tamElem);

    //pc->tamDisponible -= tamElem + sizeof(size_t);

    return VERDADERO;
}

booleano desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->tamDisponible == TAM_COLA)
        return FALSO;

    size_t tamElemEncolado;

    desencolarSegmentado(pc, &tamElemEncolado, sizeof(tamElem), sizeof(size_t));

    desencolarSegmentado(pc, elem, tamElem, tamElemEncolado);

    return VERDADERO;
}

booleano verFrenteDeCola(Cola* pc, void*elem, size_t tamElem)
{
    if(pc->tamDisponible == TAM_COLA)
        return FALSO;

    size_t tamElemEncolado;
    unsigned frente = pc->frente;

    desencolarSegmentado(pc, &tamElemEncolado, sizeof(size_t), sizeof(size_t));
    verFrenteSegmentado(pc, elem, tamElem, tamElemEncolado);
    pc->frente = frente;
    pc->tamDisponible -= sizeof(size_t);

    return VERDADERO;
}

booleano colaVacia(Cola* pc)
{
    return pc->tamDisponible == TAM_COLA;
}

booleano colaLLena(Cola* pc, size_t tamElem)
{
    return tamElem + sizeof(size_t) > pc->tamDisponible;
}

void vaciarCola(Cola* pc)
{
    pc->frente = pc->fondo - 0;
    pc->tamDisponible = TAM_COLA;
}

void encolarSegmentado(Cola* pc, const void* dato, size_t tamDato)
{
    size_t tamDisponibleContiguo;
    size_t cantACopiar1, cantACopiar2;

    tamDisponibleContiguo = pc->fondo >= pc->frente ? TAM_COLA - pc->fondo : pc->frente - pc->fondo;

    cantACopiar1 = min(tamDato, tamDisponibleContiguo);
    cantACopiar2 = tamDato - cantACopiar1;

    memcpy(pc->vec + pc->fondo, dato, cantACopiar1);
    pc->fondo = (pc->fondo + cantACopiar1) % TAM_COLA;

    if(cantACopiar2 > 0)
    {
        memcpy(pc->vec + pc->fondo, dato + cantACopiar1, cantACopiar2);
        pc->fondo += cantACopiar2;
    }

    pc->tamDisponible -= tamDato;
}

void desencolarSegmentado(Cola* pc, void* dato, size_t tamDato, size_t tamDatoEncolado)
{
    size_t cantACopiar, cantACopiar1, cantACopiar2;
    size_t tamDatoContiguo;

    cantACopiar = min(tamDato, tamDatoEncolado);

    tamDatoContiguo = pc->frente > pc->fondo ? min(tamDatoEncolado, TAM_COLA - pc->frente) : tamDatoEncolado;

    cantACopiar1 = min(tamDatoContiguo, cantACopiar);
    cantACopiar2 = cantACopiar - cantACopiar1;

    memcpy(dato, pc->vec + pc->frente, cantACopiar1);
    pc->frente = (pc->frente + tamDatoContiguo) % TAM_COLA;

    if(cantACopiar2 > 0)
    {
        memcpy(dato + cantACopiar1, pc->vec, cantACopiar2);
        pc->frente += tamDatoEncolado - tamDatoContiguo;
    }

    pc->tamDisponible += tamDatoEncolado;
}

void verFrenteSegmentado(const Cola* pc, void* dato, size_t tamDato, size_t tamDatoEncolado)
{
    size_t cantACopiar, cantACopiar1, cantACopiar2;
    size_t tamDatoContiguo;
    //unsigned frente = pc->frente;

    cantACopiar = min(tamDato, tamDatoEncolado);

    tamDatoContiguo = pc->frente > pc->fondo ? min(tamDatoEncolado, TAM_COLA - pc->frente) : tamDatoEncolado;

    cantACopiar1 = min(tamDatoContiguo, cantACopiar);
    cantACopiar2 = cantACopiar - cantACopiar1;

    memcpy(dato, pc->vec + pc->frente, cantACopiar1);
    //frente = (pc->frente + tamDatoContiguo) % TAM_COLA;

    if(cantACopiar2 > 0)
        memcpy(dato + cantACopiar1, pc->vec, cantACopiar2);

}
