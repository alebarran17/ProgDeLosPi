#include "Escolaridad.h"

/// Operaciones primitivas.

/// Crea una secuencia vac�a.
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

/// Devuelve el elemento que ocupa la posici�n K de la secuencia.
/// Precondici�n: El largo de la secuencia es mayor o igual a K.
Curso KEsimo(Escolaridad e, int n) {
    int c = 0;
    while (c != n) {
        e.pri = e.pri->sig;
        c++;
    }

    return e.pri.curso;
}

/// Operaciones adicionales.

void InsBack(Escolaridad &e, Curso c) {
    ENode nodo = ENode;
    nodo.curso = c;
    nodo.sig = NULL;

    if (e.ult == NULL) {
        e.pri = e.ult = nodo;
    } else {
        e.ult->sig = nodo;
        e.ult = nodo;
    }
}

void ListarOrdenada(Escolaridad e){
    while (e.pri != NULL) {
        MostrarCurso(e.pri);
        e.pri = e.pri->sig;
    }
}

bool AproboAsignatura(Escolaridad e, int asignaturaId) {
    bool aprobo = false;
    while (e.pri != NULL && !aprobo) {
        Fecha f = ObtenerFinalizacionCurso(e.pri->curso);
        if (f.dia > 0) {
            aprobo = true;
        } else {
            e.pri = e.pri->sig;
        }
    }

    return aprobo;
}

/// Precondici�n: La lista no es vac�a.
Curso Ultimo(Escolaridad e) {
    return e.ult->curso;
}
