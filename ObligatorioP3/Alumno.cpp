#include "Alumno.h"
#include "Escolaridad.h"
#include <stdio.h>

void CargarAlumno(Alumno& a) {
    String aux;

    printf("Ingrese el n�mero de c�dula: ");
    scanf("%ld", a.cedula);

    printf("Ingrese el nombre: ");
    scan(aux);

    printf("Ingrese el apellido: ");
    scan(aux);

    printf("Ingrese el n�mero de tel�fono: ");
    scan(aux);

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

Escolaridad ObtenerCursosAlumno(Alumno a) {
    return a.escolaridad;
}

void SetEscolaridadAlumno(Alumno &a, Escolaridad e) {
    a.escolaridad = e;
}

void MostrarAlumno(Alumno a) {
    printf("Nombre: ");
    print(a.nombre);

    printf("Apellido: ");
    print(a.apellido);

    printf("Tel�fono: ");
    print(a.telefono);

    printf("Cantidad de cursos: %d\r\n", Largo(a.escolaridad));
}
