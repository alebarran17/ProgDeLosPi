#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

#include "Escolaridad.h"

const int N = 30;
typedef int Grafo[N][N];

/// Operaciones primitivas.

/// Crea un grafo vac�o.
void Crear(Grafo& g);

/// Determina si en el grafo existe el v�rtice especificado.
bool PerteneceVertice(Grafo g, int v);

/// Determina si en el grafo existe la arista especificada.
bool PerteneceArista(Grafo g, int v, int u);

/// Inserta el nuevo v�rtice al grafo.
/// Precondici�n: el v�rtice no pertenece al grafo.
void InsertarVertice(Grafo& g, int v);

/// Inserta la nueva arista al grafo.
/// Precondici�n: la arista no pertenece al grafo.
void InsertarArista(Grafo& g, int v, int u);

/// Operaciones adicionales.

void DFS_Previas(Grafo g, int v, bool& visitados[N]);

void ListarPrevias(Grafo g, int v);

void DFS_Ciclos(Grafo g, int v, bool& visitados[N]);

bool ContieneCiclos(Grafo g);

bool AproboPreviasInmediatas(Grafo g, Escolaridad e, int v);

#endif // PREVIATURAS_H_INCLUDED
