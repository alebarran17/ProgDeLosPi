#include "Curso.h"
#include <stdio.h>

void CargarCurso(Curso& c){
    printf("Ingrese un ID de asignatura: ");
    scanf("%d", &c.asignaturaId);

    printf("Ingrese la fecha de finalizacion:\r\n");
    CargarFecha(c.finalizacion);

    printf("Ingrese la calificacion: ");
    scanf("%d", &c.calificacion);
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
    if (c.calificacion >= NOTA_MINIMA) {
        printf(" (aprobada)");
    }

    printf("\r\n");
}
