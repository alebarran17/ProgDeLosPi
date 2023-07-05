#ifndef ACTASIGNATURAS_H_INCLUDED
#define ACTASIGNATURAS_H_INCLUDED

#include "Asignatura.h"

const int CANT_ASIGNATURAS = 30;
typedef struct {
    Asignatura arr[CANT_ASIGNATURAS];
    int tope;
} Carrera;

/// Operaciones primitivas.

/// Crea una secuencia vac�a.
void Crear(Carrera c);

/// Devuelve la cantidad de elementos de la secuencia.
int Largo(Carrera c);

/// Devuelve el elemento que ocupa la posici�n K de la secuencia.
/// Precondici�n: El largo de la secuencia es mayor o igual a K.
Asignatura KEsimo(Carrera c, int k);

/// Operaciones adicionales.

///Agrega un elemento al final del secuencia.
void InsBack(Carrera c, Asignatura a);

///Lista por pantalla la secuencia.
void Listar(Carrera c);

#endif // ACTASIGNATURAS_H_INCLUDED
