#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge.h"

int actualizarProductos(const char* nomProds, const char* nomMovs)
{
    FILE* archProds = fopen(nomProds, "rb");
    FILE* archMovs = fopen(nomMovs, "rb");

    if(archProds == NULL || archMovs == NULL)
    {
        printf("Error al abrir los archivos\n");
        return ERR_ARCHIVO;
    }

    char nombreTmp[MAX_NOMBRE_ARCH];
    cambiarExtension(nomProds, nombreTmp, "tmp");
    FILE* archProdsTmp = fopen(nombreTmp, "wb");

    if(archProdsTmp == NULL)
    {
        printf("Error al abrir el archivo temporal\n");
        return ERR_ARCHIVO;
    }

    Producto prod, prodNue, mov;
    int comp;

    fread(&prod, sizeof(Producto), 1, archProds);
    fread(&mov, sizeof(Producto), 1, archMovs);

    while(!feof(archProds) && !feof(archMovs))
    {
        comp = prod.codigo - mov.codigo;

        if(comp == 0) // Actualizar stock producto existente
        {
            prod.cantidad += mov.cantidad;
            fread(&mov, sizeof(Producto), 1, archMovs);
        }
        else if (comp < 0)  // No hubo movimiento
        {
            fwrite(&prod, sizeof(Producto), 1, archProdsTmp);
            fread(&prod, sizeof(Producto), 1, archProds);
        }
        else // Producto nuevo
        {
            prodNue = mov;
            fread(&mov, sizeof(Producto), 1, archMovs);

            while(!feof(archMovs) && prodNue.codigo==mov.codigo)
            {
                prodNue.cantidad += mov.cantidad;
                fread(&mov, sizeof(Producto), 1, archMovs);
            }

            fwrite(&prodNue, sizeof(Producto), 1, archProdsTmp);
        }
    }

    while(!feof(archProds)) // Productos sin movimientos
    {
        fwrite(&prod, sizeof(Producto), 1, archProdsTmp);
        fread(&prod, sizeof(Producto), 1, archProds);
    }

    while(!feof(archMovs)) // Productos nuevos
    {
        prodNue = mov;

        fread(&mov, sizeof(Producto), 1, archMovs);

        while(!feof(archMovs) && prodNue.codigo==mov.codigo)
        {
            prodNue.cantidad += mov.cantidad;
            fread(&mov, sizeof(Producto), 1, archProdsTmp);
        }
        fwrite(&prodNue, sizeof(Producto), 1, archProdsTmp);
    }

    fclose(archProds);
    fclose(archMovs);
    fclose(archProdsTmp);

    remove(nomProds);
    rename(nombreTmp, nomProds);

    return TODO_OK;
}

int cambiarExtension(const char* nombreOrig, char* nombreCambiado, const char* extension)
{
    strcpy(nombreCambiado, nombreOrig);
    char* punto = strrchr(nombreCambiado, '.');

    if(!punto)
        return ERR_PUNTO;

    strcpy(punto + 1, extension);

    return TODO_OK;
}
