#ifndef HASHALUMNOS_H_INCLUDED
#define HASHALUMNOS_H_INCLUDED

#include "Alumno.h"

typedef struct _h_node {
    Alumno alumno;
    _h_node* sig;
} HNode;

const int B = 100;
typedef Alumno* Estudiantes[B];

/// Operaciones primitivas.

int Hash(Alumno a);

/// Crea un diccionario vacío.
void Make(Estudiantes& e);

/// Determina si en el diccionario existe un elemento con la clave especificada.
bool Member(Estudiantes e, int k);

/// Inserta un elemento de tipo T en el diccionario.
/// Precondición: el elemento a insertar no es miembro del diccionario.
void Insert(Estudiantes& e, Alumno a);

void Modify(Estudiantes &e, Alumno a);

/// Dada la clave de un elemento devuelve el elemento con dicha clave
/// Precondición: el elemento es miembro del diccionario.
Alumno Find(Estudiantes e, int k);

#endif // HASHALUMNOS_H_INCLUDED
