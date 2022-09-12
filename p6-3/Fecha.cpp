#include "Fecha.h"
#include <stdio.h>

//cargar una fecha por teclado
void CargarFecha(Fecha &f){
                printf("\nIngrese un dia: ");
                scanf("%d", &f.dia);

                printf("\nIngrese un mes: ");
                scanf("%d", &f.mes);

                printf("\nIngrese un año: ");
                scanf("%d", &f.anio);
}

//Mostrar una fecha por pantalla
void MostrarFecha(Fecha f){
                printf("\n%d/%d/%d\n", f.dia, f.mes, f.anio);
}

//selectora devuelve el dia
int DarDia(Fecha f){
                return f.dia;
}

//selectora devuelve el mes
int DarMes(Fecha f){
                return f.mes;
}

//selectora devuelve el año
int DarAnio(Fecha f){
                return f.anio;
}

boolean fechaValida(Fecha f){
                switch (f.mes)
                {
                                case 1:
                                case 3:
                                case 5:
                                case 7:
                                case 8:
                                case 10:
                                case 12: if (f.dia >= 1 && f.dia <= 31)
                                                return TRUE;
                                else
                                                return FALSE;
                                break;
                                case 4:
                                case 6:
                                case 9:
                                case 11: if (f.dia >= 1 && f.dia <= 30)
                                                return TRUE;
                                else
                                                return FALSE;
                                break;
                                case 2: if (f.anio % 4 == 0)
                                if (f.dia >= 1 && f.dia <= 29)
                                                return TRUE;
                                else
                                                return FALSE;
                                else
                                if (f.dia >= 1 && f.dia <= 28)
                                                return TRUE;
                                else
                                                return FALSE;
                                break;
                                default:
                                                return FALSE;
 }
}

