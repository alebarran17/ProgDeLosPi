#ifndef REVISIONRESULTADO_H_INCLUDED
#define REVISIONRESULTADO_H_INCLUDED

typedef enum { SATISFACTORIA, INCOMPLETA, PENDIENTE } ResultadoRevision;

// Cargar la informaci�n del resultado de una revision
// por teclado.
void CargarResultadoRevision(ResultadoRevision &r);

// Mostrar en pantalla la informaci�n del resultado
// de una revision.
void MostrarResultadoRevision(ResultadoRevision r);

#endif // REVISIONRESULTADO_H_INCLUDED
