#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

#include "Escolaridad.h"

typedef int Previaturas[CANT_ASIGNATURAS][CANT_ASIGNATURAS];

/// Operaciones primitivas.

/// Crea un grafo vacío.
void Crear(Previaturas& g);

/// Determina si en el grafo existe la arista especificada.
bool PerteneceArista(Previaturas g, int v, int u);

/// Inserta la nueva arista al grafo.
/// Precondición: la arista no pertenece al grafo.
void InsertarArista(Previaturas g, int v, int u);

/// Operaciones adicionales.

/// Devuelve la cantidad que tiene una asignatura.
int CantidadPrevias(Previaturas g, Carrera c, int v);

/// Lista las previas de un alumno.
void ListarPrevias(Previaturas g, Carrera c, int v);

/// Determina si un grafo contiene ciclos.
bool ContieneCiclos(Previaturas g, int v);

/// Determina si un alumno aprobo las previas inmediatas a una asignatura.
bool AproboPreviasInmediatas(Previaturas g, Escolaridad e, int v);

#endif // PREVIATURAS_H_INCLUDED
