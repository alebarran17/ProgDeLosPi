#ifndef ESCRIBANO_H_INCLUDED
#define ESCRIBANO_H_INCLUDED

#include "stringDinamico.h"

typedef struct{
    string nombre;
    string apellido;
} Escribano;

// Cargar la informacion del escribano por teclado.
void CargarEscribano(Escribano &e);

// Mostrar en pantalla la informaci�n del escribano ingresado.
void MostrarEscribano(Escribano e);

// Cargar el nombre del escribano desde el string ingresado.
void CargarNombreEscribano(Escribano &e, string s);

// Cargar el nombre del escribano en un string ingresado.
void ObtenerNombreEscribano(Escribano e, string &s);

// Cargar el apellido del escribano desde el string ingresado.
void CargarApellidoEscribano(Escribano &e, string s);

// Cargar el apellido del escribano en un string ingresado.
void ObtenerApellidoEscribano(Escribano e, string &s);

// Guardar la informaci�n del escribano en un archivo.
// Precondici�n: El archivo debe estar abierto.
void GuardarEscribano(FILE* f, Escribano e);

// Cargar la informaci�n del escribano desde un archivo.
// Precondici�n: El archivo debe estar abierto.
void LeerEscribano(FILE* f, Escribano &e);

#endif // ESCRIBANO_H_INCLUDED
