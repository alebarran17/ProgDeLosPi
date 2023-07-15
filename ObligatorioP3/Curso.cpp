#include "Curso.h"
#include <stdio.h>

void CargarCursoAsignaturaId(Curso& c, int asignaturaId) {
    c.asignaturaId = asignaturaId;
}

void CargarCursoFinalizacion(Curso& c, Fecha finalizacion) {
    c.finalizacion = finalizacion;
}

void CargarCursoCalificacion(Curso& c, int calificacion) {
    c.calificacion = calificacion;
}

int ObtenerAsignaturaIDCurso(Curso c){
    return c.asignaturaId;
}

Fecha ObtenerFinalizacionCurso(Curso c){
    return c.finalizacion;
}

int ObtenerCalifiacionCurso(Curso c){
    return c.calificacion;
}

Asignatura ObtenerAsignaturaPorID(Curso c, Carrera carrera) {
    int asignaturaId = c.asignaturaId;
    return KEsimo(carrera, asignaturaId);
}

void MostrarCurso(Curso c, Carrera carrera){
    Asignatura asignatura = ObtenerAsignaturaPorID(c, carrera);

    printf("[%d] ", c.asignaturaId);
    print(asignatura.nombre);
    printf(":\r\n");

    printf("\tFinalizado en: ");
    MostrarFecha(c.finalizacion);
    printf("\r\n");

    printf("\tCalificacion: %d", c.calificacion);
    if (c.calificacion >= NOTA_APROBACION) {
        printf(" (aprobada)");
    }

    printf("\r\n");
}
