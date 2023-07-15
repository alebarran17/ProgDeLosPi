#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Escolaridad.h"

typedef struct {
    long cedula;
    String nombre;
    String apellido;
    String telefono;
    Escolaridad escolaridad;
} Alumno;

/// Cargar la cédula del alumno.
void CargarAlumnoCedula(Alumno& a, long dni);

/// Cargar el nombre del alumno.
void CargarAlumnoNombre(Alumno& a, String nombre);

/// Cargar el apellido del alumno.
void CargarAlumnoApellido(Alumno& a, String apellido);

/// Cargar el teléfono del alumno.
void CargarAlumnoTelefono(Alumno& a, String telefono);

/// Modifica la escolaridad del alumno.
void CargarEscolaridadAlumno(Alumno &a, Escolaridad e);

/// Devuelve la cedula del alumno.
long ObtenerCedulaAlumno(Alumno a);

/// Devuelve el nombre del alumno.
void ObtenerNombreAlumno(Alumno a, String& s);

/// Devuelve el apellido del alumno.
void ObtenerApellidoAlumno(Alumno a, String& s);

/// Devuelve el telefono del alumno.
void ObtenerTelefonoAlumno(Alumno a, String& s);

/// Devuelve la escolaridad del alumno.
Escolaridad ObtenerEscolaridadAlumno(Alumno a);

/// Muestra el alumno.
void MostrarAlumno(Alumno a);

#endif // ALUMNO_H_INCLUDED
