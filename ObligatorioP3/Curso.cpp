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

void MostrarCurso(Curso c){
    printf("El ID de asignatura es: %d\r\n",c.asignaturaId);
    printf("La fecha es: ");
    MostrarFecha(c.finalizacion);
    printf("La calificacion es: %d", c.calificacion);
}
