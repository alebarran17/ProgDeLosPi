#include "Fecha.h"
#include <stdio.h>

void CargarFecha(Fecha& f){
    printf("Ingrese un dia: ");
    scanf("%d", &f.dia);

    printf("Ingrese un mes: ");
    scanf("%d", &f.mes);

    printf("Ingrese un a�o: ");
    scanf("%d", &f.anio);
}

// Mostrar en pantalla la fecha ingresada.
void MostrarFecha(Fecha f){
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

int ObtenerDiaFecha(Fecha f){
    return f.dia;
}

int ObtenerMesFecha(Fecha f){
    return f.mes;
}

int ObtenerAnioFecha(Fecha f){
    return f.anio;
}

bool FechaPosterior(Fecha f1, Fecha f2){
    int f1Num = ObtenerAnioFecha(f1) * 10000 + ObtenerMesFecha(f1) * 100 + ObtenerDiaFecha(f1);
    int f2Num = ObtenerAnioFecha(f2) * 10000 + ObtenerMesFecha(f2) * 100 + ObtenerDiaFecha(f2);

    return f1Num > f2Num ? true : false;
}

bool ValidarFormato(Fecha f) {
    int max;
    if (f.mes == 1 || f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 8 || f.mes == 10 || f.mes == 12)
        max = 31;
    else if (f.mes == 4 || f.mes == 6 || f.mes == 9 || f.mes == 11)
        max = 30;
    else if (f.anio % 4 == 0)
        max = 29;
    else
        max = 28;

    if (f.dia <= 0 || f.dia > max) {
        return false;
    }

    if (f.mes <= 0 || f.mes > 12) {
        return false;
    }

    return true;
}
