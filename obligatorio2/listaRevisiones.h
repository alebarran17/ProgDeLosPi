#ifndef LISTAREVISIONES_H_INCLUDED
#define LISTAREVISIONES_H_INCLUDED

#include "revision.h"
#include "boolean.h"

typedef struct nodoR {
                Revision infoRev;
                nodoR * sigRev;
} ListaRevision;

typedef ListaRevision * Lista;

//Crea una lista vacia.
void CrearListaRevision(Lista &L);

//Imprime la lista.
void MostrarLista(Lista root);

//Imprime una revision dado un codigo de expediente.
void MostrarLista(Lista root, int expedienteId);

//Devuelve TRUE si la lista es vacia, FALSE en caso contrario.
boolean VaciaListaRevision(Lista L);

//Devuevle el primero de la lista.
/* Precondición: lista NO vacía */
Revision Primero (Lista L);

//Devuelve del segundo en adelante.
/* Precondición: lista NO vacía */
void Resto (Lista & L);

//Inserta una revision en una lista.
void InsertarRevision (Lista & L, Revision R);

//Guarda la lista en una archivo
//Precondicion: El archivo debe venir abierto para escritura.
void GuardarListaRevisiones(Lista L, FILE * f);

//Lee una lista desde un archivo.
//Precondicion: El archivo debe venir abierto para lectura.
void LeerListaRevisiones(Lista &L, FILE * f);

//Cuenta la cantidad de revisiones de la lista.
int ContarRevisiones(Lista root);

//Cuenta la cantidad de revisiones con el codigo ingresado
int ContarRevisiones(Lista root, int expedienteId);

//Cuenta la cantidad de revisiones Satisfactorias, Incompletas y pendientes.
void ContarRevisiones(Lista root, int& s, int& i, int& p);

//Cuenta las revisiones entre dos fechas.
int ContarRevisiones(Lista root, Fecha desde, Fecha hasta);

//Borra las revisiones dado un codigo de expediente.
void BorrarRevisiones(Lista &from, int expedienteId);

#endif // LISTAREVISIONES_H_INCLUDED
