#include "stdio.h"
#include "escribano.h"

void CargarEscribano(Escribano &e){
    printf("Ingrese el nombre del escribano:\r\n");
    printf(">> ");
    scan(e.nombre);

    printf("Ingrese el apellido del escribano:\r\n");
    printf(">> ");
    scan(e.apellido);
}

void MostrarEscribano(Escribano e){
    print(e.nombre);
    printf(" ");
    print(e.apellido);
}

void CargarNombreEscribano(Escribano &e, string s) {
    strcrear(e.nombre);
    strcop(s, e.nombre);
}

void ObtenerNombreEscribano(Escribano e, string &s){
    strcop(e.nombre, s);
}

void CargarApellidoEscribano(Escribano &e, string s) {
    strcrear(e.apellido);
    strcop(s, e.apellido);
}

void ObtenerApellidoEscribano(Escribano e, string &s){
    strcop(e.apellido, s);
}

void GuardarEscribano(FILE* f, Escribano e) {
    GuardarString(e.nombre, f);
    GuardarString(e.apellido, f);
}

void LeerEscribano(FILE* f, Escribano &e) {
    LeerString(e.nombre, f);
    LeerString(e.apellido, f);
}
