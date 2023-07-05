#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "stringDinamico.h"
#include "boolean.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// Cargar la informacion de la fecha por teclado.
void CargarFecha(Fecha &f, Fecha minima);

// Cargar la informacion de la fecha con los datos ingresados.
void CargarFecha(Fecha &f, int anio, int mes, int dia);

// Devolver la fecha minima aceptada por el programa.
Fecha CargarFechaMinima();

// Mostrar en pantalla la fecha ingresada.
void MostrarFecha(Fecha f);

// Obtener el dia de la fecha ingresada.
int ObtenerDiaFecha(Fecha f);

// Obtener el mes de la fecha ingresada.
int ObtenerMesFecha(Fecha f);

// Obtener el a�o de la fecha ingresada.
int ObtenerAnioFecha(Fecha f);

// Validar el formato de la fecha ingresada.
boolean FechaEsValida(Fecha f);

// Comparar dos fechas devolviendo TRUE si la
// primera es mayor estricto que la segunda.
// De lo contrario devuelve FALSE.
boolean FechaMasReciente(Fecha f1, Fecha f2);

// Comparar dos fechas devolviendo TRUE si la
// primera es mayor o igual que la segunda.
// De lo contrario devuelve FALSE.
boolean FechaMayorIgual(Fecha f1, Fecha f2);

// Guardar la informaci�n de la fecha en un archivo.
// Precondicion: EL archivo debe venir abierto para escritura.
void GuardarFecha(Fecha F, FILE* f);

// Cargar la informaci�n de la fecha desde un archivo.
// Precondicion: EL archivo debe venir abierto para lectura.
void LeerFecha(Fecha &F, FILE* f);

#endif // FECHA_H_INCLUDED
