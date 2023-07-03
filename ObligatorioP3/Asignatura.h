#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

typedef struct {
    string nombre;
    int horas;
} Asignatura;

void CargarAsignatura(Asignatura& a);

void ObtenerNombre(Asignatura a, string& s);

void ObtenerHoras(Asignatura a);

#endif // ASIGNATURA_H_INCLUDED
