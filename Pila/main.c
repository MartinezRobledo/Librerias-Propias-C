#include "macros.h"

int main()
{
    int i,n;

    Pila pila;
    crear_pila(&pila);

    for(i=0; i< 60; i++)
    {
        apilar(&pila, &i, sizeof(i));
    }
    ver_tope_pila(&pila,&n,sizeof(n));
    printf("%d",n);
    while(desapilar(&pila, &n, sizeof(n)))
    {
        printf("%d\n", n);
    }

    return 0;
}
