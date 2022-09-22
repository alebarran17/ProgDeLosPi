#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include "boolean.h"

typedef struct {
    int Hours;
    int Minutes;
} Time;

//Carga el tiempo
void LoadTime(Time &time);

//Muestra el tiempo
void ShowTime(Time time, boolean newLine);

//Funcion devuelve las horas
int GetHours(Time time);

//Funcion devuelve los minutos
int GetMinutes(Time time);

// Funcion obtiene la diferencia entre dos horas
Time GetDifference(Time from, Time to);

//Funcion dados dos tiempos devuelve TRUE si el 2do es mas grande que el 1ro y FALSE si es al reves.
boolean TimeGreaterThan(Time a, Time b);

//Funcion devuelve TRUE si el 2do es mas chico que el 1ro y FALSE si es al reves
boolean TimeLessThan(Time a, Time b);

#endif // TIME_H_INCLUDED
