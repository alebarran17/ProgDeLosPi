#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

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

void DFS(Grafo g, int v, bool& visitados[N]);

bool ContieneCiclos(Grafo g);

#endif // PREVIATURAS_H_INCLUDED
