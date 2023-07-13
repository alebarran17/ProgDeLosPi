#include "Estudiantes.h"

/// Operaciones primitivas.

int Hash(int dni) {
    int sum = 0;
    while (dni > 0) {
        sum += dni % 10;
        dni /= 10;
    }

    return sum % B;
}

/// Crea un diccionario vacío.
void Make(Estudiantes& e) {
    for (int i = 0; i < B; i++) {
        e[i] = NULL;
    }
}

/// Determina si en el diccionario existe un elemento con la clave especificada.
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

/// Inserta un elemento de tipo T en el diccionario.
/// Precondición: el elemento a insertar no es miembro del diccionario.
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

/// Dada la clave de un elemento devuelve el elemento con dicha clave
/// Precondición: el elemento es miembro del diccionario.
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
