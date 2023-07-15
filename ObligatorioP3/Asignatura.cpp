#include "Asignatura.h"

void CargarAsignatura(Asignatura& a){
    printf("Ingrese un nombre de asignatura: ");
    scan(a.nombre);
    printf("Ingrese la cantidad de horas: ");
    scanf("%d", &a.horas);
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
