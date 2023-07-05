#include "Alumno.h"
#include "Escolaridad.h"
#include <stdio.h>

void CargarAlumno(Alumno& a) {
    String aux;

    printf("Ingrese el número de cédula: ");
    scanf("%ld", a.cedula);

    printf("Ingrese el nombre: ");
    scan(aux);
    strcpy(aux, a.nombre);
    strdestroy(aux);

    printf("Ingrese el apellido: ");
    scan(aux);
    strcpy(aux, a.apellido);
    strdestroy(aux);

    printf("Ingrese el número de teléfono: ");
    scan(aux);
    strcpy(aux, a.telefono);
    strdestroy(aux);

    a.cursos = Crear();
}

long ObtenerCedulaAlumno(Alumno a) {
    return a.cedula;
}

void ObtenerNombreAlumno(Alumno a, string& s) {
    strcpy(a.nombre, s);
}

void ObtenerApellidoAlumno(Alumno a, string& s) {
    strcpy(a.apellido, s);
}

void ObtenerTelefonoAlumno(Alumno a, string& s) {
    strcpy(a.telefono, s);
}

ListaCursos ObtenerCursosAlumno(Alumno a) {
    return a.cursos;
}

void SetEscolaridadAlumno(Alumno &a, Escolaridad e) {
    a.escolaridad = e;
}

void MostrarAlumno(Alumno a) {
    printf("Nombre: ");
    print(a.nombre);

    printf("Apellido: ");
    print(a.apellido);

    printf("Teléfono: ");
    print(a.telefono);

    printf("Cantidad de cursos: %d\r\n", Largo(a.escolaridad));
}
