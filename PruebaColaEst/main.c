#include "../TDA_COLA.h"
#include <stdio.h>
#include <string.h>

#define MAX_DESCR 20

typedef struct
{
    int codigo;
    char descr[MAX_DESCR];
    int cantidad;
    float precio;
}
Producto;

void generarProductos(Producto* prod)
{
    prod->codigo = 1234;
    strcpy(prod->descr, "Doritos");
    prod->cantidad = 100;
    prod->precio = 450.5;
}

int main()
{
    Producto pro;
    generarProductos(&pro);

    Cola cola;
    crearCola(&cola);

    Producto destino;

    encolar(&cola, &pro, sizeof(Producto));
    encolar(&cola, &pro, sizeof(Producto));

    desencolar(&cola, &destino, 40);

    encolar(&cola, &pro, sizeof(Producto));

    desencolar(&cola, &destino, 40);

    verFrenteDeCola(&cola, &destino, 40);

    printf("%s", destino.descr);
}
