#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Escolaridad.h"

typedef struct {
    int cedula;
    string nombre;
    string apellido;
    string telefono;
    Escolaridad escolaridad;
} Alumno;

void CargarAlumno(Alumno& a);

long ObtenerCedulaAlumno(Alumno a);

void ObtenerNombreAlumno(Alumno a, string& s);

void ObtenerApellidoAlumno(Alumno a, string& s);

void ObtenerTelefonoAlumno(Alumno a, string& s);

Escolaridad ObtenerEscolaridadAlumno(Alumno a);

void SetEscolaridadAlumno(Alumno &a, Escolaridad e);

void MostrarAlumno(Alumno a);

#endif // ALUMNO_H_INCLUDED
