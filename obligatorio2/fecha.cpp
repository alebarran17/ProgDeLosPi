#include "Fecha.h"
#include <stdio.h>

// Cargar una fecha por teclado.
void CargarFecha(Fecha &f){
    printf("Día de creación:\r\n");
    printf(">> ");
    scanf("%d", &f.dia);

    printf("Mes de creación:\r\n");
    printf(">> ");
    scanf("%d", &f.mes);

    printf("Año de creación:\r\n");
    printf(">> ");
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


boolean FechaMasReciente(Fecha f1, Fecha f2){
    boolean reciente = FALSE;
    if(f1.anio > f2.anio){
        reciente = TRUE;
    }else
        if(f1.anio == f2.anio){
            if(f1.mes > f2.mes)
                reciente = TRUE;
            else
                if(f1.mes == f2.mes){
                    if(f1.dia > f2.dia)
                        reciente = TRUE;
            }
        }
    return reciente;
}

//Precondicion: EL archivo debe venir abierto para escritura.
void GuardarFecha(Fecha F, FILE * f){
    fwrite (&F, sizeof(Fecha), 1, f);
}

//Precondicion: EL archivo debe venir abierto para lectura.
void LeerFecha(Fecha &F, FILE * f){
    fread(&F, sizeof(Fecha), 1, f);
}
