#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED

#include "stringDinamico.h"

typedef struct {
    int id;
    string caratula;
    int paginas;
} Expediente;

void CargarExpediente(Expediente &e);

void MostrarExpediente(Expediente e);

int ObtenerIdExpediente(Expediente e);

void ObtenerCaratulaExpediente(Expediente e, string &s);

int ObtenerPaginasExpediente(Expediente e);

#endif // EXPEDIENTE_H_INCLUDED
