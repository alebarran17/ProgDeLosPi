#ifndef LPPFCURSOS_H_INCLUDED
#define LPPFCURSOS_H_INCLUDED

#include "Curso.h"

typedef struct _e_node {
    Curso curso;
    _e_node* sig;
} ENode;

typedef struct {
    _e_node* pri;
    _e_node* ult;
} Escolaridad;

/// Operaciones primitivas.

/// Crea una secuencia vacía.
Escolaridad Crear();

/// Devuelve la cantidad de elementos de la secuencia.
int Largo(Escolaridad e);

/// Devuelve el elemento que ocupa la posición K de la secuencia.
/// Precondición: El largo de la secuencia es mayor o igual a K.
Curso KEsimo(Escolaridad e, int n);

/// Operaciones adicionales.

void InsBack(Escolaridad e);

void ListarOrdenada(Escolaridad e);

#endif // LPPFCURSOS_H_INCLUDED
