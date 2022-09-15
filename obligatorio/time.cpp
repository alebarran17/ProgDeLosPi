#include "time.h"

void loadTime(Time &time) {
    printf("Hora: ");
    scanf("%d\r\n", time.Hours);

    printf("Minutos: ");
    scanf("%d\r\n", time.Minutes);
}

int getHours(Time time) {
    return time.Hours;
}

int getMinutes(Time time) {
    return time.Minutes;
}
