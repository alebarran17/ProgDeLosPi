#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

#include "Carrera.h"
#include "Escolaridad.h"

const int N = 30;
typedef int Previaturas[N][N];

/// Operaciones primitivas.

/// Crea un grafo vacío.
void Crear(Previaturas& g);

/// Determina si en el grafo existe la arista especificada.
bool PerteneceArista(Previaturas g, int v, int u);

/// Inserta la nueva arista al grafo.
/// Precondición: la arista no pertenece al grafo.
void InsertarArista(Previaturas g, int v, int u);

/// Operaciones adicionales.

void DFS_Previas(Previaturas g, Carrera c, int v, bool visitados[N]);

void ListarPrevias(Previaturas g, Carrera c, int v);

void DFS_Ciclos(Previaturas g, int v, bool visitados[N], bool& ciclo);

bool ContieneCiclos(Previaturas g, int v);

bool AproboPreviasInmediatas(Previaturas g, Escolaridad e, int v);

#endif // PREVIATURAS_H_INCLUDED
