#ifndef REVISION_H_INCLUDED
#define REVISION_H_INCLUDED

#include "fecha.h"
#include "stringDinamico.h"
#include "resultadoRevision.h"

typedef struct {
    int expedienteId;
    Fecha fecha;
    string descripcion;
    ResultadoRevision resultado;
} Revision;

void CargarRevision(Revision &r);

void MostrarRevision(Revision r);

int ObtenerExpedienteIdRevision(Revision r);

Fecha ObtenerFechaRevision(Revision r);

void ObtenerDescripcionRevision(Revision r, string &s);

ResultadoRevision ObtenerResultadoRevision(Revision r);

//Precondicion: El archivo debe venir abierto para escritura
void GuardarRevision(Revision R, FILE * f);

//Precondicion: el archivo debe venir abierto para lectura.
void CargarRevision(Revision &R, FILE * f);

#endif // REVISION_H_INCLUDED
