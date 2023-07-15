#include "Escolaridad.h"

Escolaridad Crear() {
    Escolaridad e;
    e.pri = e.ult = NULL;
    return e;
}

int Largo(Escolaridad e) {
    int c = 0;
    while (e.pri != NULL) {
        e.pri = e.pri->sig;
        c++;
    }

    return c;
}

Curso KEsimo(Escolaridad e, int n) {
    int c = 0;
    while (c != n) {
        e.pri = e.pri->sig;
        c++;
    }

    return e.pri->curso;
}

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

Curso Ultimo(Escolaridad e) {
    return e.ult->curso;
}
