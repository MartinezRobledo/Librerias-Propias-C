#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERR_ARCH 1

typedef struct
{
    int d;
    int m;
    int a;
}
Fecha;

typedef struct
{
    int clave;
    Fecha fecVenc;
    Fecha fecComp;
    char desc[20];
    char proov[20];
    int cant;
    float precioC;
    float precioV;
}
Producto;

int main(int argc, char* argv[])
{
    FILE* f = fopen(argv[1], "wb");

    if(!f)
    {
        puts("error al escribir el archivo");
        return ERR_ARCH;
    }

    Producto prod[5] =
    {
        {0, {5, 12, 2029}, {8, 10, 2019}, "bronce", "nisax", 100, 750.5, 800},
        {1, {20, 4, 2028}, {12, 12, 2021}, "plata", "kerios", 80, 840.1, 880.5},
        {2, {14, 2, 2039}, {20, 1, 2020}, "oro", "ginyin", 75, 1200, 1350.8},
        {3, {9, 8, 2025}, {15, 9, 2022}, "platino", "pochi", 52, 1572, 1900},
        {1, {22, 11, 2022}, {7, 5, 2021}, "plata", "werlyb", 13, 3800, 7250}
    };

    fwrite(&prod, sizeof(Producto), 5, f);

    fclose(f);
    puts("El archivo se creo exitosamente");
    return TODO_OK;
}
