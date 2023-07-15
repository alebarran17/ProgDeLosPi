#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

#include "String.h"

typedef struct {
    int idAsignatura;
    String nombre;
    int horas;
} Asignatura;

/// Carga el nombre de la asignatura.
void CargarAsignaturaNombre(Asignatura& a, String nombre);

/// Carga las horas de la asignatura.
void CargarAsignaturaHoras(Asignatura& a, int horas);

/// Devuelve la ID de la asignatura.
int ObtenerIdAsignatura(Asignatura a);

/// Devuelve el nombre de la asignatura.
void ObtenerNombre(Asignatura a, String& s);

/// Devuelve la cantidad de horas de la asignatura.
int ObtenerHoras(Asignatura a);

/// Muestra la asignatura.
void MostrarAsignatura(Asignatura a);

#endif // ASIGNATURA_H_INCLUDED
