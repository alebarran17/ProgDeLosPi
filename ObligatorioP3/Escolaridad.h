#ifndef LPPFCURSOS_H_INCLUDED
#define LPPFCURSOS_H_INCLUDED

#include "Curso.h"
#include "Carrera.h"

typedef struct _e_node {
    Curso curso;
    _e_node* sig;
} ENode;

typedef struct {
    _e_node* pri;
    _e_node* ult;
} Escolaridad;

/// Operaciones primitivas.

/// Crea una secuencia vac�a.
Escolaridad Crear();

/// Devuelve la cantidad de elementos de la secuencia.
int Largo(Escolaridad e);

/// Devuelve el elemento que ocupa la posici�n K de la secuencia.
/// Precondici�n: El largo de la secuencia es mayor o igual a K.
Curso KEsimo(Escolaridad e, int n);

/// Operaciones adicionales.
///Inserta un elemento al final de la lista
void InsBack(Escolaridad &e, Curso c);
///Lista en pantalla la escolaridad de forma ordenada
void ListarOrdenada(Escolaridad e, Carrera c);
///Demuestra si la asignatura se aprobo
bool AproboAsignatura(Escolaridad e, int asignaturaId);

///Devuelve el ultimo curso de la escolaridad
/// Precondici�n: La lista no es vac�a.
Curso Ultimo(Escolaridad e);

#endif // LPPFCURSOS_H_INCLUDED
