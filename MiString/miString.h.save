#ifndef MISTRING_H_INCLUDED
#define MISTRING_H_INCLUDED

#include "../Comun/comun.h"

typedef struct
{
    char* cursor;  //recorre la cadena
    char* inicioDeCadena; // o inicializar cadena
    booleano finDeSecuencia;//flag
} SecuenciaDePalabra;

typedef struct
{
    char* inicio;
    char* fin;
} Palabra;

int miStrlen(const char* cod);
booleano esMinuscula(char *c);
booleano esMayuscula(char *c);
void bloqMayus(char *c);

void normalizar(const char* cOrigen, char* cDestino);

void leerPalabra(SecuenciaDePalabra* secuenciaDePalabra, Palabra* palabra);
booleano esLetra(char* caracter);

void escribirPalabra(SecuenciaDePalabra* secuenciaDeEscritura, Palabra* palabra);
void escribirCaracter(SecuenciaDePalabra* secuenciaDeEscritura, char c);
void reposicionarSecuenciaDePalabra(SecuenciaDePalabra* secuenciaDeEscritura, int i);
void rebobinarSecuenciaDePalabra(SecuenciaDePalabra* secuenciaDeEscritura);
void formatearPrimeraMayorRestoMenor(Palabra* palabra);
void crearSecuenciaDePalabra(SecuenciaDePalabra* secuencia, const char* cadena);

#endif // MISTRING_H_INCLUDED
