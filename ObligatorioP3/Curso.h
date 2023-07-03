#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

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

#endif // CURSO_H_INCLUDED
