#ifndef LISTAREVISIONES_H_INCLUDED
#define LISTAREVISIONES_H_INCLUDED

#include "revision.h"
#include "boolean.h"

typedef struct nodoR {
                Revision infoRev;
                nodoR * sigRev;
} ListaRevision;

typedef ListaRevision * Lista;

void CrearListaRevision(Lista &L);

void MostrarLista(Lista root);

boolean VaciaListaRevision(Lista L);

/* Precondición: lista NO vacía */
Revision Primero (Lista L);

/* Precondición: lista NO vacía */
void Resto (Lista & L);

void InsertarRevision (Lista & L, Revision R);

void GuardarListaRevisiones(Lista L, FILE * f);

void LeerListaRevisiones(Lista &L, FILE * f);

void ListarRPorExpediente(Lista L, int ID);

int ContarRevisiones(Lista root);

#endif // LISTAREVISIONES_H_INCLUDED
