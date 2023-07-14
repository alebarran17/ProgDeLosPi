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

///Cargar el alumno por teclado
void CargarAlumno(Alumno& a);

///Devuelve la cedula del alumno
long ObtenerCedulaAlumno(Alumno a);

///Devuelve el nombre del alumno
void ObtenerNombreAlumno(Alumno a, String& s);

///Devuelve el apellido del alumno
void ObtenerApellidoAlumno(Alumno a, String& s);

///Devuelve el telefono del alumno
void ObtenerTelefonoAlumno(Alumno a, String& s);

///Devuelve la escolaridad del alumno
Escolaridad ObtenerEscolaridadAlumno(Alumno a);

///Modifica la escolaridad del alumno
void SetEscolaridadAlumno(Alumno &a, Escolaridad e);

///Muestra el alumno
void MostrarAlumno(Alumno a);

#endif // ALUMNO_H_INCLUDED
