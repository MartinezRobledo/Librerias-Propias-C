#include "TDAImplColaEstatica.h"

int main()
{
    Cola cola;
    crearCola(&cola);

    char* frase = "Todo nace y muere en un instante";
    char destino[sizeof(*frase)];

    encolar(&cola, frase, sizeof(*frase));

    verFrenteDeCola(&cola, &destino, sizeof(*frase));

    printf("%s\n", destino);
}
