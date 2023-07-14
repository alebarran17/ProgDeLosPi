#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED
#include "String.h"
#include "Fecha.h"

const int NOTA_MINIMA = 6;

typedef struct {
    int asignaturaId;
    String nombreAsig;
    Fecha finalizacion;
    int calificacion;
} Curso;

///Cargar curso por teclado
void CargarCurso(Curso& c);

///Devuelve la identificacion de la asignatura asociada al curso
int ObtenerAsignaturaIDCurso(Curso c);

///Devuelve el nombre de la asignatura
void ObtenerNombreAsignatura(Curso c, String &s);

///Devuelve la fecha de finalizacion del curso
Fecha ObtenerFinalizacionCurso(Curso c);

///Devuelve la calificacion del curso
int ObtenerCalifiacionCurso(Curso c);

///Muestra el curso
void MostrarCurso(Curso c);

#endif // CURSO_H_INCLUDED
