#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "expediente.h"
#include "listaRevisiones.h"

typedef struct node {
    Expediente info;
    node* izq;
    node* der;
} ABBExpediente;

typedef ABBExpediente* Arbol;

// Agregar un expediente al arbol.
void AgregarExpediente(Arbol& root, Expediente e);

// Mostrar en pantalla todos los expedientes.
void MostrarArbol(Arbol root);

// Obtener el expediente con el codigo de identificacion menor.
Expediente PrimerExpediente(Arbol root);

// Obtener el expediente con el codigo de identificacion mayor.
Expediente UltimoExpediente(Arbol root);

// Obtener un expediente con el codigo de identificacion ingresado,
// o NULL si no existe en el arbol.
Expediente* BuscarExpediente(Arbol root, int id);

// Eliminar el expediente del arbol con el codigo de
// identificacion ingresado.
// Precondicion: El expediente debe existir.
void BorrarExpediente(Arbol& root, int id);

// Devolver el nodo del arbol cuyo numero de identificacion
// es el menor de todos.
Arbol BuscarExpedienteMinimo(Arbol root);

// Cargar la información de todos los expedientes desde un archivo.
// Precondicion: El archivo debe venir abierto para lectura.
void LeerArbolExpedientes(FILE* f, Arbol &root);

// Guardar la información de todos los expedientes en un archivo.
// Precondicion: El archivo debe venir abierto para escritura.
void GuardarArbolExpedientes(FILE* f, Arbol root);

// Devolver la cantidad total de expedientes en el arbol.
int ContarExpedientes(Arbol root);

// Devolver la cantidad de expedientes cuyo apellido del escribano
// coincide con el ingresado.
int ContarExpedientes(Arbol root, string apellido);

// Devolver el codigo de identificacion y la cantidad de revisiones
// del expediente con mas revisiones.
void ExpedienteConMasRevisiones(Arbol root, Lista revisiones, int& rev, int &eid);

#endif // ABBEXPEDIENTE_H_INCLUDED
