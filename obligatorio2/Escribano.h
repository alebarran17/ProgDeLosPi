#ifndef ESCRIBANO_H_INCLUDED
#define ESCRIBANO_H_INCLUDED
#include "stringDinamico.h"

typedef struct{
                string nombre;
                string apellido;
} Escribano;

void CargarEscribano(Escribano &e);

void MostrarEscribano(Escribano e);

void ObtenerNombreEscribano(Escribano e, string &s);

void ObtenerApellidoEscribano(Escribano e, string &s);

#endif // ESCRIBANO_H_INCLUDED
