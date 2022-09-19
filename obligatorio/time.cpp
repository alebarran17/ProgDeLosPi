#include <stdio.h>

#include "time.h"

void LoadTime(Time &time) {
    printf("Hora: ");
    scanf("%d", &time.Hours);

    printf("Minutos: ");
    scanf("%d", &time.Minutes);
}

void ShowTime(Time t) {
    printf("%d:%d\r\n", t.Hours, t.Minutes);
}

int GetHours(Time time) {
    return time.Hours;
}

int GetMinutes(Time time) {
    return time.Minutes;
}

Time GetDifference(Time from, Time to) {
    Time t;
    t.Hours = to.Hours - from.Hours;
    t.Minutes = to.Minutes - from.Minutes;
    return t;
}
