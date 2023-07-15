#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED
#include "String.h"
#include "Fecha.h"
#include "Carrera.h"

const int NOTA_MINIMA = 0;
const int NOTA_APROBACION = 6;
const int NOTA_MAXIMA = 12;

typedef struct {
    int asignaturaId;
    Fecha finalizacion;
    int calificacion;
} Curso;

/// Cargar el id de la asignatura.
void CargarCursoAsignaturaId(Curso& c, int asignaturaId);

/// Cargar la fecha de finalización.
void CargarCursoFinalizacion(Curso& c, Fecha finalizacion);

/// Cargar la calificación.
void CargarCursoCalificacion(Curso& c, int calificacion);

/// Devuelve la identificacion de la asignatura asociada al curso.
int ObtenerAsignaturaIDCurso(Curso c);

/// Devuelve la fecha de finalizacion del curso.
Fecha ObtenerFinalizacionCurso(Curso c);

/// Devuelve la calificacion del curso.
int ObtenerCalifiacionCurso(Curso c);

/// Obtiene la asignatura a traves del ID de curso.
Asignatura ObtenerAsignaturaPorID(Curso c, Carrera carrera);

/// Muestra el curso.
void MostrarCurso(Curso c, Carrera carrera);

#endif // CURSO_H_INCLUDED
