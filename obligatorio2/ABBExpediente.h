#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "expediente.h"

typedef struct node {
    Expediente info;
    node* izq;
    node* der;
} ABBExpediente;

typedef ABBExpediente* Arbol;

// Agrega un expediente al arbol.
void AgregarExpediente(Arbol& root, Expediente e);

// Imprime los nodos del arbol en orden.
void MostrarArbol(Arbol root, Expediente e);

// Devuelve un puntero al expediente buscado, o NULL si no existe.
Expediente* BuscarExpediente(Arbol root, int id);

void ListarExpedientes(Arbol root);

void BorrarExpediente(Arbol& root, int id);

Arbol BuscarExpedienteMinimo(Arbol root);

#endif // ABBEXPEDIENTE_H_INCLUDED
