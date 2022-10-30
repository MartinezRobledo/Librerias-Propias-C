#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

#define PARAM_PRODUCTOS     1
#define PARAM_MOVIMIENTOS   2
#define ERR_PUNTO           3
#define MAX_NOMBRE_ARCH     101
#define MAX_DESCR           101
#define ERR_ARCHIVO         -1

#include "../Comun/Comun.h"

typedef struct
{
    int codigo;
    char descr[MAX_DESCR];
    int cantidad;
    float precio;
}
Producto;

int cambiarExtension(const char* nombreOrig, char* nombreCambiado, const char* extension);
int actualizarProductos(const char* nomProds, const char* nomMovs);

#endif // MERGE_H_INCLUDED
