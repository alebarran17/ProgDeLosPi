#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

///Carga la fecha por teclado
void CargarFecha(Fecha& f);

///Muestra la fecha en pantalla
void MostrarFecha(Fecha f);

///Devuelve el dia de la fecha
int ObtenerDiaFecha(Fecha f);

///Devuelve el mes de la fecha
int ObtenerMesFecha(Fecha f);

///Devuelve el año de la fecha
int ObtenerAnioFecha(Fecha f);

///Determina si la fecha f1 es posterior a la f2
bool FechaPosterior(Fecha f1, Fecha f2);

///Determina si el formato de la fecha es correcto
bool ValidarFormato(Fecha f);

#endif // FECHA_H_INCLUDED
