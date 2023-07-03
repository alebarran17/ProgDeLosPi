#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

void CargarFecha(Fecha& f);

int ObtenerDiaFecha(Fecha f);

int ObtenerMesFecha(Fecha f);

int ObtenerAnioFecha(Fecha f);

#endif // FECHA_H_INCLUDED
