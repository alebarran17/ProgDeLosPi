#include "Previaturas.h"

void Crear(Previaturas& g) {
    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        for (int j = 0; j < CANT_ASIGNATURAS; j++) {
            g[i][j] = 0;
        }
    }
}

bool PerteneceArista(Previaturas g, int v, int u) {
    return g[v][u] == 1;
}

void InsertarArista(Previaturas g, int v, int u) {
    g[v][u] = 1;
    if (ContieneCiclos(g, v)) {
        printf("[E]: %d no puede ser previa de %d porque generaría un ciclo.\r\n", u, v);
        g[v][u] = 0;
    } else {
        printf("[I]: %d ahora es previa de %d.\r\n", u, v);
    }
}

int DFS_CantPrevias(Previaturas g, Carrera c, int v, bool visitados[CANT_ASIGNATURAS]) {
    visitados[v] = true;

    int count = 0;
    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        if (!visitados[i] && PerteneceArista(g, v, i)) {
            count = DFS_CantPrevias(g, c, i, visitados) + 1;
        }
    }

    return count;
}

int CantidadPrevias(Previaturas g, Carrera c, int v) {
    bool visitados[CANT_ASIGNATURAS];
    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        visitados[i] = false;
    }

    return DFS_CantPrevias(g, c, v, visitados);
}

void DFS_Previas(Previaturas g, Carrera c, int v, bool visitados[CANT_ASIGNATURAS]) {
    visitados[v] = true;

    for (int i = 0; i < CANT_ASIGNATURAS; i++) {
        if (!visitados[i] && PerteneceArista(g, v, i)) {
            Asignatura a = KEsimo(c, i);
            MostrarAsignatura(a);

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
