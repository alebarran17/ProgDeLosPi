#include "Alumno.h"
#include "Escolaridad.h"
#include <stdio.h>

/// Cargar la cédula del alumno.
void CargarAlumnoCedula(Alumno& a, long dni) {
    a.cedula = dni;
}

/// Cargar el nombre del alumno.
void CargarAlumnoNombre(Alumno& a, String nombre) {
    strcrear(a.nombre);
    strcop(nombre, a.nombre);
}

/// Cargar el apellido del alumno.
void CargarAlumnoApellido(Alumno& a, String apellido){
    strcrear(a.apellido);
    strcop(apellido, a.apellido);
}

/// Cargar el teléfono del alumno.
void CargarAlumnoTelefono(Alumno& a, String telefono) {
    strcrear(a.telefono);
    strcop(telefono, a.telefono);
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
