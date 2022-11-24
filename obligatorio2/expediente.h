#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED

#include "stringDinamico.h"
#include "escribano.h"

typedef struct {
    int id;
    string caratula;
    int paginas;
    Escribano escribano;
} Expediente;

void CargarExpediente(Expediente &e);

void MostrarExpediente(Expediente e);

int ObtenerIdExpediente(Expediente e);

void ObtenerCaratulaExpediente(Expediente e, string &s);

int ObtenerPaginasExpediente(Expediente e);

void GuardarExpediente(FILE* f, Expediente e);

void LeerExpediente(FILE* f, Expediente& e);

#endif // EXPEDIENTE_H_INCLUDED
