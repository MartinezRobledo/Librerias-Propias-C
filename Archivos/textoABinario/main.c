#include <stdio.h>
#include <stdlib.h>
#define PARAM_BIN 1
#define PARAM_TXT 2
#define PARAM_FORMATO 3
#define ERR_ARCH -1

typedef struct {
    int dia;
    int mes;
    int anio;
} T_Fecha;
typedef struct {
    int dni;
    char apyn[200];
    char sexo;
    T_Fecha fNac;
    float sueldo;
} T_Empleado;

int main(int argc, char*argv[]) {
    FILE* archBin=fopen(argv[PARAM_BIN],"rb");
    FILE* archTxt=fopen(argv[PARAM_TXT],"wt");

    if(!archBin||!archTxt) {
        puts("Error de apertura");
        return ERR_ARCH;
    }
    char* formato;
    if(*argv[PARAM_FORMATO]=='v')
        formato="%d|%[^|]|%c|%d/%d/%d|%f\n";
    else
        formato="%8d%200s%c%2d%2d%4d%10f\n";
    T_Empleado empleadoLectura;
    while(fscanf(archTxt,formato,&empleadoLectura.dni,empleadoLectura.apyn,&empleadoLectura.sexo,&empleadoLectura.fNac.dia,&empleadoLectura.fNac.mes,&empleadoLectura.fNac.anio,&empleadoLectura.sueldo)!=feof)
            fwrite(&empleadoLectura,sizeof(T_Empleado),1,archBin);
    fclose(archBin);
    fclose(archTxt);
    return 0;
}
