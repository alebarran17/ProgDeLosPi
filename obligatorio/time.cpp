#include <stdio.h>

#include "time.h"

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
    } while (h < 0 || h > 59);
    time.Minutes = m;
}

void ShowTime(Time t, boolean newLine) {
    printf("%d:%d", t.Hours, t.Minutes);
    if (newLine == TRUE) {
        printf("\r\n");
    }
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

boolean TimeGreaterThan(Time a, Time b) {
    if (b.Hours > a.Hours) {
        return TRUE;
    } else if (b.Hours < a.Hours) {
        return FALSE;
    } else {
        return b.Minutes > a.Minutes ? TRUE : FALSE;
    }
}

boolean TimeLessThan(Time a, Time b) {
    if (b.Hours < a.Hours) {
        return TRUE;
    } else if (b.Hours > a.Hours) {
        return FALSE;
    } else {
        return b.Minutes < a.Minutes ? TRUE : FALSE;
    }
}
