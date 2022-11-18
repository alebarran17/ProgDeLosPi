#ifndef REVISIONRESULTADO_H_INCLUDED
#define REVISIONRESULTADO_H_INCLUDED

typedef enum { SATISFACTORIA, INCOMPLETA, PENDIENTE } ResultadoRevision;

void CargarResultadoRevision(ResultadoRevision &r);

void MostrarResultadoRevision(ResultadoRevision r);

#endif // REVISIONRESULTADO_H_INCLUDED
