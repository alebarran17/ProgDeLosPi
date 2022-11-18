#include "Fecha.h"
#include <stdio.h>

// Cargar una fecha por teclado.
void CargarFecha(Fecha &f){
    printf("Ingrese el dia: ");
    scanf("%d", &f.dia);

    printf("Ingrese el mes: ");
    scanf("%d", &f.mes);

    printf("Ingrese el año: ");
    scanf("%d", &f.anio);
}

// Mostrar una fecha por pantalla.
void MostrarFecha(Fecha f){
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

// Selectora devuelve el dia.
int ObtenerDiaFecha(Fecha f){
    return f.dia;
}

// Selectora devuelve el mes.
int ObtenerMesFecha(Fecha f) {
    return f.mes;
}

// Selectora devuelve el año.
int ObtenerAnioFecha(Fecha f){
    return f.anio;
}

boolean FechaEsValida(Fecha f){
    int max;
    if (f.mes == 1 || f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 8 || f.mes == 10 || f.mes == 12)
        max = 31;
    else if (f.mes == 4 || f.mes == 6 || f.mes == 9 || f.mes == 11)
        max = 30;
    else if (f.anio % 4 == 0)
        max = 29;
    else
        max = 28;

    return f.dia >= 1 && f.dia <= max ? TRUE : FALSE;
}

