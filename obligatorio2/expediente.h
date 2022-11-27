#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED

#include "stringDinamico.h"
#include "escribano.h"

typedef struct {
    int id;
    string caratula;
    int paginas;
    Escribano escribano;
} Expediente;

// Cargar la informacion del expediente por teclado.
void CargarExpediente(Expediente &e);

// Mostrar en pantalla la información del expediente ingresado.
void MostrarExpediente(Expediente e);

// Cargar el codigo de identificacion de un expediente
// por teclado.
void CargarIdExpediente(Expediente& e);

// Obtener el identificador del expediente ingresado.
int ObtenerIdExpediente(Expediente e);

// Cargar la caratula del expediente en una string ingresada.
void ObtenerCaratulaExpediente(Expediente e, string &s);

// Obtener las paginas del expediente ingresado.
int ObtenerPaginasExpediente(Expediente e);

// Cargar la información de en escribano con el escribano del expediente ingresado.
void ObtenerEscribano(Expediente expediente, Escribano &escribano);

// Guardar la información del expediente en un archivo.
// Precondición: El archivo debe estar abierto.
void GuardarExpediente(FILE* f, Expediente e);

// Cargar la información del escribano desde un archivo.
// Precondición: El archivo debe estar abierto.
void LeerExpediente(FILE* f, Expediente& e);

#endif // EXPEDIENTE_H_INCLUDED
