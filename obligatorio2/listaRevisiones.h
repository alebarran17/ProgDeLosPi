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

boolean VaciaListaRevision(Lista L);

/* Precondición: lista NO vacía */
Revision Primero (Lista L);

/* Precondición: lista NO vacía */
void Resto (Lista & L);

void InsertarRevision (Lista & L, Revision R);

void GuardarListaRevisiones(Lista L, string nomArch);

void LevantarListaRevisiones(Lista &L, string NomArch);

void ListarRPorExpediente(Lista L, int ID);

#endif // LISTAREVISIONES_H_INCLUDED
