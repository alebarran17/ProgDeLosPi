#ifndef PREVIATURAS_H_INCLUDED
#define PREVIATURAS_H_INCLUDED

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

void DFS(Grafo g, int v, bool& visitados[N]);

bool ContieneCiclos(Grafo g);

#endif // PREVIATURAS_H_INCLUDED
