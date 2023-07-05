#ifndef LISTAREVISIONES_H_INCLUDED
#define LISTAREVISIONES_H_INCLUDED

#include "revision.h"
#include "boolean.h"

typedef struct nodoR {
                Revision infoRev;
                nodoR * sigRev;
} ListaRevision;

typedef ListaRevision * Lista;

// Mostrar en pantalla todas las revisiones.
void MostrarLista(Lista root);

// Mostrar en pantalla todas las revisiones cuya relación con
// el expediente sea igual al ingresado.
void MostrarLista(Lista root, int expedienteId);

// Devolver TRUE si la lista esta vacia, FALSE en caso contrario.
boolean VaciaListaRevision(Lista L);

// Agregar una revision a la lista.
void InsertarRevision (Lista & L, Revision R);

// Guardar la información de todas las revisiones en un archivo.
// Precondicion: El archivo debe venir abierto para escritura.
void GuardarListaRevisiones(Lista L, FILE * f);

// Cargar la información de todas las revisiones desde un archivo.
// Precondicion: El archivo debe venir abierto para lectura.
void LeerListaRevisiones(Lista &L, FILE * f);

// Devolver la cantidad total de revisiones en la lista.
int ContarRevisiones(Lista root);

// Devolver la cantidad total de revisiones cuyo codigo de
// identificacion del expediente sea igual al ingresado.
int ContarRevisiones(Lista root, int expedienteId);

// Devolver la cantidad total de revisiones en la lista por resultado.
void ContarRevisiones(Lista root, int& s, int& i, int& p);

// Devolver la cantidad total de revisiones en la lista dentro de un
// rango de fechas.
int ContarRevisiones(Lista root, Fecha desde, Fecha hasta);

// Eliminar las revisiones de la lista con el codigo de
// identificacion del expediente ingresado.
void BorrarRevisiones(Lista &from, int expedienteId);

#endif // LISTAREVISIONES_H_INCLUDED
