#include "stdio.h"
#include "Escribano.h"

void CargarEscribano(Escribano &e){
                strcrear(e.nombre);
                strcrear(e.apellido);
                printf("Ingrese el nombre del escribano: ");
                scan(e.nombre);
                printf("Ingrese el apellido del escribano: ");
                scan(e.apellido);
}

void MostrarEscribano(Escribano e){
                printf("El nombre del escribano es: ");
                print(e.nombre);
                printf(" ");
                print(e.apellido);
}

void ObtenerNombreEscribano(Escribano e, string &s){
                strcrear(s);
                strcop(e.nombre, s);
}

void ObtenerApellidoEscribano(Escribano e, string &s){
                strcrear(s);
                strcop(e.apellido, s);
}
