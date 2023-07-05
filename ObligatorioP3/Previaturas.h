#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

#include "Escolaridad.h"

const int N = 30;
typedef int Grafo[N][N];

/// Operaciones primitivas.

/// Crea un grafo vacío.
void Crear(Grafo& g);

/// Determina si en el grafo existe el vértice especificado.
bool PerteneceVertice(Grafo g, int v);

/// Determina si en el grafo existe la arista especificada.
bool PerteneceArista(Grafo g, int v, int u);

/// Inserta el nuevo vértice al grafo.
/// Precondición: el vértice no pertenece al grafo.
void InsertarVertice(Grafo& g, int v);

/// Inserta la nueva arista al grafo.
/// Precondición: la arista no pertenece al grafo.
void InsertarArista(Grafo& g, int v, int u);

/// Operaciones adicionales.

void DFS_Previas(Grafo g, int v, bool& visitados[N]);

void ListarPrevias(Grafo g, int v);

void DFS_Ciclos(Grafo g, int v, bool& visitados[N]);

bool ContieneCiclos(Grafo g);

bool AproboPreviasInmediatas(Grafo g, Escolaridad e, int v);

#endif // PREVIATURAS_H_INCLUDED
