#include "Asignatura.h"

void CargarAsignatura(Asignatura& a){
    printf("Ingrese un ID de asignatura: ");
    scanf("%d", a.IdAsignatura);
    printf("\r\n");
    printf("Ingrese un nombre de asignatura: ");
    scan(a.nombre);
    printf("\r\n");
    printf("Ingrese la cantidad de horas: ");
    scanf("%d", a.horas);
    printf("\r\n");
}

void ObtenerNombre(Asignatura a, String& s){
    strcrear(s);
    strcop(a.nombre, s);
}

int ObtenerHoras(Asignatura a){
    return a.horas;
}

void MostrarAsignatura(Asignatura a){
    printf("El numero de la asignatura es %d", &a.IdAsignatura);
    printf("\r\n");
    printf("El nombre de la asignatura es: ");
    print(a.nombre);
    printf("\r\n");
    printf("La cantidad de horas son %d", &a.horas);
    printf("\r\n");
}
