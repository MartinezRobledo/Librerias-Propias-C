#include <stdio.h>
#include <stdlib.h>

#define TODO_OK 0
#define ERR_ARCH 1

typedef struct
{
    int d,
        m,
        a;
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
    FILE* empleadosA = fopen(argv[1], "rb");
    if(!empleadosA)
    {
        puts("Error abriendo archivo");
        return ERR_ARCH;
    }

    Producto prod;

    fread(&prod, sizeof(Producto), 1, empleadosA);

    printf("%d\n", prod.clave);

    while(!feof(empleadosA))
    {
        fread(&prod, sizeof(Producto), 1, empleadosA);
        printf("%d\n", prod.clave);
    }

    fclose(empleadosA);

    return TODO_OK;
}
