#include "Curso.h"
#include <stdio.h>

void CargarCurso(Curso& c){
    printf("Ingrese un ID de asignatura: ");
    scanf("%d", &c.asignaturaId);
    printf("\r\n");
    printf("Ingrese el nombre de asignatura: ");
    scan(c.nombreAsignatura);
    printf("\r\n");
    printf("Ingrese la fecha de finalizacion: ");
    CargarFecha(c.finalizacion);
    printf("\r\n");
    printf("Ingrese la calificacion: ");
    scanf("%d", &c.calificacion);
}

int ObtenerAsignaturaIDCurso(Curso c){
    return c.asignaturaId;
}

void ObtenerNombreAsignaturaCurso(Curso c, String& s){
    strcop(c.nombreAsignatura, s);
}

Fecha ObtenerFinalizacionCurso(Curso c){
    return c.finalizacion;
}

int ObtenerCalifiacionCurso(Curso c){
    return c.calificacion;
}

void MostrarCurso(Curso c){
    printf("El ID de asignatura es: %d\r\n",c.asignaturaId);
    printf("El nombre de la asignatura es: ");
    print(c.nombreAsignatura);
    printf("La fecha es: ");
    MostrarFecha(c.finalizacion);
    printf("La calificacion es: %d", c.calificacion);
}
