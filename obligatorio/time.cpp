#include <stdio.h>

#include "time.h"

//Carga el tiempo
void LoadTime(Time &time) {
    int h = 0;
    do {
        printf("Hora: ");
        scanf("%d", &h);
    } while (h < 8 || h > 22);
    time.Hours = h;

    int m = 0;
    do {
        printf("Minutos: ");
        scanf("%d", &m);
    } while (h < 0 || h > 59 || m<0 || m>59);
    time.Minutes = m;
}

//Muestra el tiempo
void ShowTime(Time t, boolean newLine) {
    printf("%d:%d", t.Hours, t.Minutes);
    if (newLine == TRUE) {
        printf("\r\n");
    }
}

//Funcion devuelve las horas
int GetHours(Time time) {
    return time.Hours;
}

//Funcion devuelve los minutos
int GetMinutes(Time time) {
    return time.Minutes;
}

// Funcion obtiene la diferencia entre dos horas
Time GetDifference(Time from, Time to) {
    Time t;
    t.Hours = to.Hours - from.Hours;
    t.Minutes = to.Minutes - from.Minutes;
    if(t.Minutes<0){
                t.Minutes=60+t.Minutes;
    }
    return t;
}

//Funcion dados dos tiempos devuelve TRUE si el 2do es mas grande que el 1ro y FALSE si es al reves.
boolean TimeGreaterThan(Time a, Time b) {
    if (b.Hours > a.Hours) {
        return TRUE;
    } else if (b.Hours < a.Hours) {
        return FALSE;
    } else {
        return b.Minutes > a.Minutes ? TRUE : FALSE;
    }
}

//Funcion devuelve TRUE si el 2do es mas chico que el 1ro y FALSE si es al reves
boolean TimeLessThan(Time a, Time b) {
    if (b.Hours < a.Hours) {
        return TRUE;
    } else if (b.Hours > a.Hours) {
        return FALSE;
    } else {
        return b.Minutes < a.Minutes ? TRUE : FALSE;
    }
}
