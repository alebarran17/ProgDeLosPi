#include "Fecha.h"
#include <stdio.h>

void CargarFecha(Fecha& f){
    printf("Ingrese un dia: ");
    scanf("%d", f.dia);
    f.dia = dia;

    printf("Ingrese un mes: ");
    scanf("%d", f.mes);
    f.mes = mes;

    printf("Ingrese un año: ");
    scanf("%d", f.anio);
    f.anio = anio;
}

// Mostrar en pantalla la fecha ingresada.
void MostrarFecha(Fecha f){
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}


int ObtenerDiaFecha(Fecha f){
    return f.dia;
}

int ObtenerMesFecha(Fecha f){
    return f.mes
}

int ObtenerAnioFecha(Fecha f){
    return f.anio
}

bool FechaPosterior(Fecha f1, Fecha f2){
    int f1Num = ObtenerAnioFecha(f1) * 10000 + ObtenerMesFecha(f1) * 100 + ObtenerDiaFecha(f1);
    int f2Num = ObtenerAnioFecha(f2) * 10000 + ObtenerMesFecha(f2) * 100 + ObtenerDiaFecha(f2);

    return f1Num > f2Num ? true : false;
}
