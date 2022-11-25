#include <stdio.h>

#include "Fecha.h"
#include "boolean.h"

// Cargar una fecha por teclado.
void CargarFecha(Fecha &f, Fecha minima){
    boolean valida = FALSE;

    while (valida == FALSE) {
        printf("Día:\r\n");
        printf(">> ");
        scanf("%d", &f.dia);

        printf("Mes:\r\n");
        printf(">> ");
        scanf("%d", &f.mes);

        printf("Año:\r\n");
        printf(">> ");
        scanf("%d", &f.anio);

        if (FechaEsValida(f) == TRUE) {
            if (FechaMayorIgual(f, minima) == TRUE) {
                valida = TRUE;
            } else {
                printf("\r\n");
                printf("[E]: La fecha debe ser mayor a ");
                MostrarFecha(minima);
                printf("\r\n");
                printf("\r\n");
            }
        } else {
            printf("\r\n");
            printf("[E]: La fecha ingresada no es válida\r\n");
            printf("\r\n");
        }
    }
}

void CargarFecha(Fecha &f, int anio, int mes, int dia) {
    f.anio = anio;
    f.mes = mes;
    f.dia = dia;
}

Fecha CargarFechaMinima() {
    Fecha min;
    CargarFecha(min, 1970, 1, 1);
    return min;
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

boolean FechaMasReciente(Fecha f1, Fecha f2){
    int f1Num = ObtenerAnioFecha(f1) * 10000 + ObtenerMesFecha(f1) * 100 + ObtenerDiaFecha(f1);
    int f2Num = ObtenerAnioFecha(f2) * 10000 + ObtenerMesFecha(f2) * 100 + ObtenerDiaFecha(f2);
    return f1Num > f2Num ? TRUE : FALSE;
}

boolean FechaMayorIgual(Fecha f1, Fecha f2) {
    int f1Num = ObtenerAnioFecha(f1) * 10000 + ObtenerMesFecha(f1) * 100 + ObtenerDiaFecha(f1);
    int f2Num = ObtenerAnioFecha(f2) * 10000 + ObtenerMesFecha(f2) * 100 + ObtenerDiaFecha(f2);
    return f1Num >= f2Num ? TRUE : FALSE;
}

//Precondicion: EL archivo debe venir abierto para escritura.
void GuardarFecha(Fecha F, FILE * f){
    fwrite (&F, sizeof(Fecha), 1, f);
}

//Precondicion: EL archivo debe venir abierto para lectura.
void LeerFecha(Fecha &F, FILE * f){
    fread(&F, sizeof(Fecha), 1, f);
}
