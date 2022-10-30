#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PARAM_BIN 1
#define PARAM_TXT 2
#define PARAM_FORMATO 3
#define ERR_ARCH -1
#define TAM_LINEA 100
#define TAM_APYN 200
#define TODO_OK 10
#define ERR_LINEA_LARGA -2

typedef struct {
    int dia;
    int mes;
    int anio;
} T_Fecha;
typedef struct {
    int dni;
    char apyn[TAM_APYN];
    char sexo;
    T_Fecha fNac;
    float sueldo;
} T_Empleado;

int errorFatal(int ret);
int txtaBinDin(char* linea,T_Empleado*empleado);
int txtaBinStat(char* linea,T_Empleado*empleado);

int main(int argc, char*argv[]) {
    FILE* archBin=fopen(argv[PARAM_BIN],"wb");
    FILE* archTxt=fopen(argv[PARAM_TXT],"rt");

    if(!archBin||!archTxt) {
        puts("Error de apertura");
        return ERR_ARCH;
    }
    T_Empleado empleadoLectura;
    int ret;
    char linea[TAM_LINEA];
    fgets(linea,TAM_LINEA,archTxt);
    while(!feof(archTxt)||!errorFatal(ret)) {
        if(*argv[PARAM_FORMATO]=='v')
            ret=txtaBinDin(linea,&empleadoLectura);
        else
            ret=txtaBinStat(linea,&empleadoLectura);

        if(ret==TODO_OK)
            fwrite(&empleadoLectura,sizeof(T_Empleado),1,archBin);
        fgets(linea,TAM_LINEA,archTxt);
    }
    return 0;
}

int errorFatal(int ret) {
    if(ret<-10)
        return 1;
    else
        return 0;
}

int txtaBinDin(char* linea,T_Empleado* empleado) {
    char* car=strchr(linea,'\n');
    if(!car)
        return ERR_LINEA_LARGA;

    *car='\0';
    car=strrchr(linea,'|');
    //INSERTE VALIDACION
    sscanf(car+1,"%f",&empleado->sueldo);

    *car='\0';
    car=strrchr(linea,'|');
    //INSERTE VALIDACION
    sscanf(car+1,"%d/%d/%d",&empleado->fNac.dia,&empleado->fNac.mes,&empleado->fNac.anio);

    *car='\0';
    car=strrchr(linea,'|');
    //INSERTE VALIDACION
    empleado->sexo=*(car+1);

    *car='\0';
    car=strrchr(linea,'|');
    //INSERTE VALIDACION
    strncpy(empleado->apyn,car+1,TAM_APYN);
    empleado->apyn[TAM_APYN-1]='\0';

    *car='\0';
    sscanf(linea,"%d",&empleado->dni);
    //INSERTE VALIDACION
    return TODO_OK;

}
int txtaBinStat(char* linea,T_Empleado* empleado) {
    char* car=strchr(linea,'\n');
    if(!car)
        return ERR_LINEA_LARGA;

    *car='\0';
    car-=10;
    //INSERTE VALIDACION
    sscanf(car,"%f",&empleado->sueldo);

    *car='\0';
    car-=8;
    sscanf(car,"%2d%2d2%d",&empleado->fNac.dia,&empleado->fNac.mes,&empleado->fNac.anio);
    //INSERTE VALIDACION

    *car='\0';
    car--;
    empleado->sexo=*car;

    *car='\0';
    car-=TAM_APYN;
    //INSERTE VALIDACION
    strncpy(empleado->apyn,car,TAM_APYN);
    empleado->apyn[TAM_APYN-1]='\0';

    *car='\0';
    sscanf(linea,"%d",&empleado->dni);
    //INSERTE VALIDACION
    return TODO_OK;
}
