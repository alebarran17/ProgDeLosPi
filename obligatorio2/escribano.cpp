#include "stdio.h"
#include "escribano.h"

// Cargar la informacion del escribano por teclado.
void CargarEscribano(Escribano &e){
    printf("Ingrese el nombre del escribano:\r\n");
    printf(">> ");
    scan(e.nombre);

    printf("Ingrese el apellido del escribano:\r\n");
    printf(">> ");
    scan(e.apellido);
}

// Mostrar en pantalla la información del escribano ingresado.
void MostrarEscribano(Escribano e){
    print(e.nombre);
    printf(" ");
    print(e.apellido);
}

// Cargar el nombre del escribano desde el string ingresado.
void CargarNombreEscribano(Escribano &e, string s) {
    strcrear(e.nombre);
    strcop(s, e.nombre);
}

// Cargar el nombre del escribano en un string ingresado.
void ObtenerNombreEscribano(Escribano e, string &s){
    strcop(e.nombre, s);
}

// Cargar el apellido del escribano desde el string ingresado.
void CargarApellidoEscribano(Escribano &e, string s) {
    strcrear(e.apellido);
    strcop(s, e.apellido);
}

// Cargar el apellido del escribano en un string ingresado.
void ObtenerApellidoEscribano(Escribano e, string &s){
    strcop(e.apellido, s);
}

// Guardar la información del escribano en un archivo.
// Precondición: El archivo debe estar abierto.
void GuardarEscribano(FILE* f, Escribano e) {
    GuardarString(e.nombre, f);
    GuardarString(e.apellido, f);
}

// Cargar la información del escribano desde un archivo.
// Precondición: El archivo debe estar abierto.
void LeerEscribano(FILE* f, Escribano &e) {
    LeerString(e.nombre, f);
    LeerString(e.apellido, f);
}
