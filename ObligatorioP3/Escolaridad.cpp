#include "Escolaridad.h"

/// Operaciones primitivas.

/// Crea una secuencia vacía.
Escolaridad Crear() {
    Escolaridad e;
    e.pri = e.ult = NULL;
    return e;
}

/// Devuelve la cantidad de elementos de la secuencia.
int Largo(Escolaridad e) {
    int c = 0;
    while (e.pri != NULL) {
        e.pri = e.pri->sig;
        c++;
    }

    return c;
}

/// Devuelve el elemento que ocupa la posición K de la secuencia.
/// Precondición: El largo de la secuencia es mayor o igual a K.
Curso KEsimo(Escolaridad e, int n) {
    int c = 0;
    while (c != n) {
        e.pri = e.pri->sig;
        c++;
    }

    return e.pri->curso;
}

/// Operaciones adicionales.

void InsBack(Escolaridad &e, Curso c) {
    ENode* nodo = new ENode;
    nodo->curso = c;
    nodo->sig = NULL;

    if (e.ult == NULL) {
        e.pri = e.ult = nodo;
    } else {
        e.ult->sig = nodo;
        e.ult = nodo;
    }
}

void ListarOrdenada(Escolaridad e, Carrera c){
    while (e.pri != NULL) {
        MostrarCurso(e.pri->curso, c);
        e.pri = e.pri->sig;
    }
}

bool AproboAsignatura(Escolaridad e, int asignaturaId) {
    bool aprobo = false;
    while (e.pri != NULL && !aprobo) {
        int auxId = ObtenerAsignaturaIDCurso(e.pri->curso);
        if (ObtenerAsignaturaIDCurso(e.pri->curso) == asignaturaId) {
            int calif = ObtenerCalifiacionCurso(e.pri->curso);
            if (calif >= NOTA_APROBACION) {
                aprobo = true;
            }
        }
        e.pri = e.pri->sig;
    }

    return aprobo;
}

/// Precondición: La lista no es vacía.
Curso Ultimo(Escolaridad e) {
    return e.ult->curso;
}
