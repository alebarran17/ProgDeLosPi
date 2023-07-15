#include "Asignatura.h"

void CargarAsignaturaNombre(Asignatura& a, String nombre) {
    strcrear(a.nombre);
    strcop(nombre, a.nombre);
}

void CargarAsignaturaHoras(Asignatura& a, int horas) {
    a.horas = horas;
}

int ObtenerIdAsignatura(Asignatura a) {
    return a.idAsignatura;
}

void ObtenerNombre(Asignatura a, String& s){
    strcrear(s);
    strcop(a.nombre, s);
}

int ObtenerHoras(Asignatura a){
    return a.horas;
}

void MostrarAsignatura(Asignatura a){
    printf("[%d]: ", a.idAsignatura);
    print(a.nombre);
    printf(" (%d horas)\r\n", a.horas);
}
