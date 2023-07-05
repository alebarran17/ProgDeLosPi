#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

#include "String.h"

typedef struct {
    int idAsignatura;
    String nombre;
    int horas;
} Asignatura;

void CargarAsignatura(Asignatura& a);

void ObtenerNombre(Asignatura a, String& s);

void ObtenerHoras(Asignatura a);

void MostrarAsignatura(Asignatura c);

#endif // ASIGNATURA_H_INCLUDED
