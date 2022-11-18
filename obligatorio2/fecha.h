#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include "boolean.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// Cargar una fecha por teclado.
void CargarFecha(Fecha &f);

// Mostrar una fecha por pantalla.
void MostrarFecha(Fecha f);

// Selectora devuelve el dia.
int ObtenerDiaFecha(Fecha f);

// Selectora devuelve el mes.
int ObtenerMesFecha(Fecha f);

// Selectora devuelve el a�o.
int ObtenerAnioFecha(Fecha f);

//Funci�n que determina si una fecha es v�lida.
boolean FechaEsValida(Fecha f);

#endif // FECHA_H_INCLUDED
