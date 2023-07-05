#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

const int NOTA_MINIMA = 6;

typedef struct {
    int asignaturaId;
    string nombreAsignatura;
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
