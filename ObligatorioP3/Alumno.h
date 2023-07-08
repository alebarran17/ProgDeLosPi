#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Escolaridad.h"

typedef struct {
    int cedula;
    String nombre;
    String apellido;
    String telefono;
    Escolaridad escolaridad;
} Alumno;

void CargarAlumno(Alumno& a);

long ObtenerCedulaAlumno(Alumno a);

void ObtenerNombreAlumno(Alumno a, String& s);

void ObtenerApellidoAlumno(Alumno a, String& s);

void ObtenerTelefonoAlumno(Alumno a, String& s);

Escolaridad ObtenerEscolaridadAlumno(Alumno a);

void SetEscolaridadAlumno(Alumno &a, Escolaridad e);

void MostrarAlumno(Alumno a);

#endif // ALUMNO_H_INCLUDED
