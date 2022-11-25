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

// Agrega un expediente al arbol.
void AgregarExpediente(Arbol& root, Expediente e);

// Imprime los nodos del arbol en orden.
void MostrarArbol(Arbol root);

//Devuelve el primer expediente.
Expediente PrimerExpediente(Arbol root);

//Devuelve el ultimo expediente.
Expediente UltimoExpediente(Arbol root);

// Devuelve un puntero al expediente buscado, o NULL si no existe.
Expediente* BuscarExpediente(Arbol root, int id);

//Borrar un expediente.
void BorrarExpediente(Arbol& root, int id);

//Busca el expediente con menor codigo.
Arbol BuscarExpedienteMinimo(Arbol root);

//Guarda el arbol de expedientes en un archivo.
void GuardarArbolExpedientes(FILE* f, Arbol root);

//Lee desde un archivo un arbol de expedientes.
void LeerArbolExpedientes(FILE* f, Arbol &root);

//Cuenta la cantidad de expedientes.
int ContarExpedientes(Arbol root);

//Cuenta la cantidad de expedientes dado un apellido.
int ContarExpedientes(Arbol root, string apellido);

//Devuelve el expediente con mas revisiones.
void ExpedienteConMasRevisiones(Arbol root, Lista revisiones, int& rev, int &eid);

#endif // ABBEXPEDIENTE_H_INCLUDED
