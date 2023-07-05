#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED

typedef struct {
    int idAsignatura;
    string nombre;
    int horas;
} Asignatura;

void CargarAsignatura(Asignatura& a);

void ObtenerNombre(Asignatura a, string& s);

void ObtenerHoras(Asignatura a);

void MostrarAsignatura(Asignatura c);

#endif // ASIGNATURA_H_INCLUDED
