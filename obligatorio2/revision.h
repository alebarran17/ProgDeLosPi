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

// Cargar la información de una revisión por teclado.
void CargarRevision(Revision &r);

// Mostrar en pantalla la información de una revisión.
void MostrarRevision(Revision r);

// Devolver el identificador del expediente de la revision.
int ObtenerExpedienteIdRevision(Revision r);

// Devolver la fecha de la revision.
Fecha ObtenerFechaRevision(Revision r);

// Cargar la descripcion de una revision en el string ingresado.
void ObtenerDescripcionRevision(Revision r, string &s);

// Devolver el resultado de la revision.
ResultadoRevision ObtenerResultadoRevision(Revision r);

// Guardar la información de la revision en un archivo.
// Precondicion: El archivo debe venir abierto para escritura
void GuardarRevision(Revision R, FILE * f);

// Leer la información de la fecha desde un archivo.
// Precondicion: el archivo debe venir abierto para lectura.
void CargarRevision(Revision &R, FILE * f);

#endif // REVISION_H_INCLUDED
