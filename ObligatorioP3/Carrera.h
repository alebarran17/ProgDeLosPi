#ifndef ACTASIGNATURAS_H_INCLUDED
#define ACTASIGNATURAS_H_INCLUDED

#include "Asignatura.h"

const int CANT_ASIGNATURAS = 30;
typedef struct {
    Asignatura arr[CANT_ASIGNATURAS];
    int tope;
} Carrera;

/// Operaciones primitivas.

/// Crea una secuencia vacía.
Carrera Crear();

/// Devuelve la cantidad de elementos de la secuencia.
int Largo(Carrera c);

/// Devuelve el elemento que ocupa la posición K de la secuencia.
/// Precondición: El largo de la secuencia es mayor o igual a K.
Asignatura KEsimo(Carrera c, int n);

/// Operaciones adicionales.

void InsBack(Carrera c);

void Listar(Carrera c);

#endif // ACTASIGNATURAS_H_INCLUDED
