#include "Alumno.h"
#include "Escolaridad.h"
#include <stdio.h>

void CargarAlumno(Alumno& a) {
    printf("Ingrese el número de cédula: ");
    scanf("%ld", &a.cedula);

    printf("Ingrese el nombre: ");
    scan(a.nombre);

    printf("Ingrese el apellido: ");
    scan(a.apellido);

    printf("Ingrese el número de teléfono: ");
    scan(a.telefono);

    a.escolaridad = Crear();
}

long ObtenerCedulaAlumno(Alumno a) {
    return a.cedula;
}

void ObtenerNombreAlumno(Alumno a, String& s) {
    strcop(a.nombre, s);
}

void ObtenerApellidoAlumno(Alumno a, String& s) {
    strcop(a.apellido, s);
}

void ObtenerTelefonoAlumno(Alumno a, String& s) {
    strcop(a.telefono, s);
}

Escolaridad ObtenerEscolaridadAlumno(Alumno a) {
    return a.escolaridad;
}

void SetEscolaridadAlumno(Alumno &a, Escolaridad e) {
    a.escolaridad = e;
}

void MostrarAlumno(Alumno a) {
    print(a.nombre);
    printf(" ");
    print(a.apellido);
    printf(" (%ld):\r\n", a.cedula);

    printf("\tNúmero de contacto: ");
    print(a.telefono);
    printf("\r\n");

    printf("\tCantidad de cursos: %d\r\n", Largo(a.escolaridad));
}
