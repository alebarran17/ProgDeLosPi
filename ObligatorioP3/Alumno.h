#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct {
    int cedula;
    string nombre;
    string apellido;
    string telefono;
    ListaCursos cursos;
} Alumno;

void CargarAlumno(Alumno& a);

long ObtenerCedulaAlumno(Alumno a);

void ObtenerNombreAlumno(Alumno a, string& s);

void ObtenerApellidoAlumno(Alumno a, string& s);

void ObtenerTelefonoAlumno(Alumno a, string& s);

ListaCursos ObtenerCursosAlumno(Alumno a);

#endif // ALUMNO_H_INCLUDED
