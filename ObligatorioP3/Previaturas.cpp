#include "Previaturas.h"

/// Operaciones primitivas.

/// Crea un grafo vacío.
void Crear(Previaturas& g) {
    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        for (int j = 0; j < CANT_ASIGNATURAS; j++) {
            g[i][j] = 0;
        }
    }
}

/// Determina si en el grafo existe la arista especificada.
bool PerteneceArista(Previaturas g, int v, int u) {
    return g[v][u] == 1;
}

/// Inserta una nueva arista al grafo partiendo de v a u.
/// Precondición: la arista no pertenece al grafo.
void InsertarArista(Previaturas g, int v, int u) {
    g[v][u] = 1;
    if (ContieneCiclos(g, v)) {
        printf("[E]: %d no puede ser previa de %d porque generaría un ciclo.\r\n", u, v);
        g[v][u] = 0;
    }
}

/// Operaciones adicionales.

void DFS_Previas(Previaturas g, Carrera c, int v, bool visitados[CANT_ASIGNATURAS]) {
    visitados[v] = true;

    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        if (!visitados[i] && PerteneceArista(g, v, i)) {
            Asignatura a = KEsimo(c, i);
            MostrarAsignatura(a);
            printf("\r\n");

            DFS_Previas(g, c, i, visitados);
        }
    }
}

void ListarPrevias(Previaturas g, Carrera c, int v) {
    bool visitados[CANT_ASIGNATURAS];
    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        visitados[i] = false;
    }

    DFS_Previas(g, c, v, visitados);
    printf("\r\n");
}

void DFS_Ciclos(Previaturas g, int v, bool visitados[CANT_ASIGNATURAS], bool& ciclo) {
    visitados[v] = true;

    int i = 0;
    while (i < CANT_ASIGNATURAS && !ciclo) {
        if (i != v && PerteneceArista(g, v, i)) {
            if (!visitados[i]) {
                DFS_Ciclos(g, i, visitados, ciclo);
            } else {
                ciclo = true;
            }
        }
        i++;
    }
}

bool ContieneCiclos(Previaturas g, int v) {
    bool visitados[CANT_ASIGNATURAS];
    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        visitados[i] = false;
    }

    bool ciclo = false;
    DFS_Ciclos(g, v, visitados, ciclo);

    return ciclo;
}

bool AproboPreviasInmediatas(Previaturas g, Escolaridad e, int v) {
    bool aprobo = true;
    int i = 0;
    while (i < CANT_ASIGNATURAS && aprobo) {
        if (g[v][i] == 1 && v != i) {
            if (!AproboAsignatura(e, i)) {
                aprobo = false;
            }
        }
        i++;
    }

    return aprobo;
}
