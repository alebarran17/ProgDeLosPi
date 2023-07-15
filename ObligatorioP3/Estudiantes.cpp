#include "Estudiantes.h"

int Hash(int dni) {
    int sum = 0;
    while (dni > 0) {
        sum += dni % 10;
        dni /= 10;
    }

    return sum % B;
}

void Make(Estudiantes& e) {
    for (int i = 0; i < B; i++) {
        e[i] = NULL;
    }
}

bool Member(Estudiantes e, int k) {
    bool found = false;
    int key = Hash(k);
    HNode* aux = e[key];
    while (aux != NULL && !found) {
        if (k == ObtenerCedulaAlumno(aux->alumno)) {
            found = true;
        } else {
            aux = aux->sig;
        }
    }

    return found;
}

void Insert(Estudiantes e, Alumno a) {
    int key = Hash(ObtenerCedulaAlumno(a));
    HNode* newNode = new HNode;
    newNode->alumno = a;
    newNode->sig = e[key];
    e[key] = newNode;
}

void Modify(Estudiantes &e, Alumno a) {
    int dni = ObtenerCedulaAlumno(a);
    int key = Hash(dni);
    HNode* aux = e[key];

    bool found = false;
    while (aux != NULL && !found) {
        if (dni == ObtenerCedulaAlumno(aux->alumno)) {
            aux->alumno = a;
            found = true;
        } else {
            aux = aux->sig;
        }
    }
}

Alumno Find(Estudiantes e, int dni) {
    HNode* node = NULL;

    int key = Hash(dni);
    HNode* aux = e[key];
    while (aux != NULL && node == NULL) {
        if (dni == ObtenerCedulaAlumno(aux->alumno)) {
            node = aux;
        } else {
            aux = aux->sig;
        }
    }

    return node->alumno;
}
