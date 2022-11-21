#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "expediente.h"

typedef struct node {
    Expediente info;
    node* izq;
    node* der;
} ABBExpediente;

// Agrega un expediente al arbol.
void AgregarExpediente(ABBExpediente*& root, Expediente e);

// Imprime los nodos del arbol en orden.
void MostrarArbol(ABBExpediente* root, Expediente e);

// Devuelve un puntero al expediente buscado, o NULL si no existe.
Expediente* BuscarExpediente(ABBExpediente* root, int id);

// Devuelve un puntero al siguiente nodo del arbol según la propiedad ABB.
ABBExpediente* SiguienteNodo(ABBExpediente* root, int id);

#endif // ABBEXPEDIENTE_H_INCLUDED
