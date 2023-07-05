#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED
#include "String.h"
#include "Fecha.h"

const int NOTA_MINIMA = 6;

typedef struct {
    int asignaturaId;
    String nombreAsignatura;
    Fecha finalizacion;
    int calificacion;
} Curso;

void CargarCurso(Curso& c);

int ObtenerAsignaturaIDCurso(Curso c);

void ObtenerNombreAsignaturaCurso(Curso c, string& s);

Fecha ObtenerFinalizacionCurso(Curso c);

int ObtenerCalifiacionCurso(Curso c);

void MostrarCurso(Curso c);

#endif // CURSO_H_INCLUDED
