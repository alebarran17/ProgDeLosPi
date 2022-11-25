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

void MostrarLista(Lista root, int expedienteId);

boolean VaciaListaRevision(Lista L);

/* Precondici�n: lista NO vac�a */
Revision Primero (Lista L);

/* Precondici�n: lista NO vac�a */
void Resto (Lista & L);

void InsertarRevision (Lista & L, Revision R);

void GuardarListaRevisiones(Lista L, FILE * f);

void LeerListaRevisiones(Lista &L, FILE * f);

int ContarRevisiones(Lista root);

int ContarRevisiones(Lista root, int expedienteId);

void ContarRevisiones(Lista root, int& s, int& i, int& p);

void BorrarRevisiones(Lista &from, int expedienteId);

#endif // LISTAREVISIONES_H_INCLUDED
