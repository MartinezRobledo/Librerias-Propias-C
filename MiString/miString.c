#include "miString.h"
#include <stdio.h>

int miStrlen(const char* cadena)
{
    char* i = (char*)cadena;
    while(*i)
    {
        i++;
    }
    return i-cadena;
}

void escribirPalabra(SecuenciaDePalabra *secuenciaDeEscritura, Palabra *palabra)
{
    while(palabra->inicio != palabra->fin)
    {
        *secuenciaDeEscritura->cursor = *palabra->inicio;
        palabra->inicio++;
        secuenciaDeEscritura->cursor++;
    }
    *secuenciaDeEscritura->cursor = *palabra->inicio;
}

void escribirCaracter(SecuenciaDePalabra* secuenciaDeEscritura, char c)
{
    secuenciaDeEscritura->cursor ++;
    *secuenciaDeEscritura->cursor = c;
    secuenciaDeEscritura->cursor ++;
}

void reposicionarSecuenciaDePalabra(SecuenciaDePalabra* secuenciaDeEscritura, int i)
{
    secuenciaDeEscritura->cursor += i;
}

void rebobinarSecuenciaDePalabra(SecuenciaDePalabra* secuenciaDeEscritura)
{
    secuenciaDeEscritura->cursor -= miStrlen(secuenciaDeEscritura->inicioDeCadena);
}

void normalizar(const char* cOrigen, char* cDestino)
{
    Palabra palabra;
    SecuenciaDePalabra secuenciaDeLectura, secuenciaDeEscritura;

    crearSecuenciaDePalabra(&secuenciaDeLectura, cOrigen);
    crearSecuenciaDePalabra(&secuenciaDeEscritura, cDestino);

    while(!secuenciaDeLectura.finDeSecuencia)
    {
        leerPalabra(&secuenciaDeLectura, &palabra);
        escribirPalabra(&secuenciaDeEscritura, &palabra);
        escribirCaracter(&secuenciaDeEscritura, ' ');
    }

    reposicionarSecuenciaDePalabra(&secuenciaDeEscritura, -2);
    escribirCaracter(&secuenciaDeEscritura, '\0');
    reposicionarSecuenciaDePalabra(&secuenciaDeEscritura, -1);
    rebobinarSecuenciaDePalabra(&secuenciaDeEscritura);

    leerPalabra(&secuenciaDeEscritura, &palabra);

    while(!secuenciaDeEscritura.finDeSecuencia)
    {
        formatearPrimeraMayorRestoMenor(&palabra);
        leerPalabra(&secuenciaDeEscritura, &palabra);
    }
}

void leerPalabra(SecuenciaDePalabra* secuenciaDeLectura, Palabra* palabra)
{
    while(*secuenciaDeLectura->cursor!='\0'&&!esLetra(secuenciaDeLectura->cursor))
        secuenciaDeLectura->cursor++;

    if(*secuenciaDeLectura->cursor=='\0')
    {
        secuenciaDeLectura->finDeSecuencia = VERDADERO;
        palabra->inicio = " ";
        palabra->fin = " ";
        return;
    }

    palabra->inicio = secuenciaDeLectura->cursor;

    while(*secuenciaDeLectura->cursor!='\0'&&esLetra(secuenciaDeLectura->cursor))
        secuenciaDeLectura->cursor ++;
    palabra->fin = secuenciaDeLectura->cursor-1;
}

booleano esLetra(char* caracter)
{
    if(esMinuscula(caracter))
        return VERDADERO;
    if(esMayuscula(caracter))
        return VERDADERO;
    return FALSO;
}

void crearSecuenciaDePalabra(SecuenciaDePalabra* secuencia, const char *cadena)
{
    secuencia->cursor = (char*)cadena;
    secuencia->finDeSecuencia = FALSO;
    secuencia->inicioDeCadena = (char*)cadena;
}

void formatearPrimeraMayorRestoMenor(Palabra* palabra)
{
    if(esMinuscula(palabra->inicio))
        bloqMayus(palabra->inicio);

    palabra->inicio ++;

    while(palabra->inicio!=palabra->fin&&*palabra->inicio)
    {
       if(esMayuscula(palabra->inicio))
            bloqMayus(palabra->inicio);
       palabra->inicio++;
    }
    if(esMayuscula(palabra->inicio))
        bloqMayus(palabra->inicio);
}

booleano esMinuscula(char *c)
{
    char* minusculas = "abcdefghijklmnopqrstuvwxyz";

    while(*c!=*minusculas&&*minusculas)
        minusculas ++;
    if(*c==*minusculas)
        return VERDADERO;
    return FALSO;
}

booleano esMayuscula(char *c)
{
    char* mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while(*c!=*mayusculas&&*mayusculas)
        mayusculas ++;
    if(*c==*mayusculas)
        return VERDADERO;
    return FALSO;
}

void bloqMayus(char *c)
{
    const char* minusculas = "abcdefghijklmnopqrstuvwxyz";
    const char* mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i=0;
    while(*c!=*minusculas&&*minusculas)
        {
            minusculas ++;
            i++;
        }
    if(*c==*minusculas)
    {
        *c = mayusculas[i];
        return;
    }
    minusculas-=i;
    i=0;
    while(*c!=*mayusculas&&*mayusculas)
        {
            mayusculas ++;
            i++;
        }
    if(*c==*mayusculas)
    {
        *c = minusculas[i];
        return;
    }
}
