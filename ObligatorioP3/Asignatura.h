#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

#include "String.h"

typedef struct {
    int idAsignatura;
    String nombre;
    int horas;
} Asignatura;

///Carga la asignatura por teclado
void CargarAsignatura(Asignatura& a);

///Devuelve la ID de la asignatura
int ObtenerIdAsignatura(Asignatura a);

///Devuelve el nombre de la asignatura
void ObtenerNombre(Asignatura a, String& s);

///Devuelve la cantidad de horas de la asignatura
int ObtenerHoras(Asignatura a);

///Muestra la asignatura
void MostrarAsignatura(Asignatura a);

#endif // ASIGNATURA_H_INCLUDED
