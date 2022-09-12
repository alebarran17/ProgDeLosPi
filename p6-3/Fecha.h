#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"
typedef struct{
                int dia;
                int mes;
                int anio;
}Fecha;

//cargar una fecha por teclado
void CargarFecha(Fecha &f);

//Mostrar una fecha por pantalla
void MostrarFecha(Fecha f);

//selectora devuelve el dia
int DarDia(Fecha f);

//selectora devuelve el mes
int DarMes(Fecha f);

//selectora devuelve el año
int DarAnio(Fecha f);

//Funcion que determina si una fecha es valida
boolean fechaValida(Fecha f);

#endif // FECHA_H_INCLUDED
