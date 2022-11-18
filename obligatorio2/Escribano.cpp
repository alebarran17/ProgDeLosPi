#include "stdio.h"
#include "escribano.h"

void CargarEscribano(Escribano &e){
    printf("Ingrese el nombre del escribano: ");
    scan(e.nombre);
    printf("Ingrese el apellido del escribano: ");
    scan(e.apellido);
}

void MostrarEscribano(Escribano e){
    printf("Escribano: ");
    print(e.nombre);
    printf(" ");
    print(e.apellido);
}

void ObtenerNombreEscribano(Escribano e, string &s){
    strcop(e.nombre, s);
}

void ObtenerApellidoEscribano(Escribano e, string &s){
    strcop(e.apellido, s);
}