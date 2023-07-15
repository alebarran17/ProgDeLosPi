#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED
#include "String.h"
#include "Fecha.h"
#include "Carrera.h"

const int NOTA_MINIMA = 6;

typedef struct {
    int asignaturaId;
    Fecha finalizacion;
    int calificacion;
} Curso;

///Cargar curso por teclado
void CargarCurso(Curso& c);

///Devuelve la identificacion de la asignatura asociada al curso
int ObtenerAsignaturaIDCurso(Curso c);

///Devuelve la fecha de finalizacion del curso
Fecha ObtenerFinalizacionCurso(Curso c);

///Devuelve la calificacion del curso
int ObtenerCalifiacionCurso(Curso c);

///Obtiene la asignatura a traves del ID de curso
Asignatura ObtenerAsignaturaPorID(Curso c, Carrera carrera);

///Muestra el curso
void MostrarCurso(Curso c, Carrera carrera);

#endif // CURSO_H_INCLUDED
