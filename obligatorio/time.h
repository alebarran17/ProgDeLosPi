#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include "boolean.h"

typedef struct {
    int Hours;
    int Minutes;
} Time;

void LoadTime(Time &time);

void ShowTime(Time time, boolean newLine);

int GetHours(Time time);

int GetMinutes(Time time);

Time GetDifference(Time from, Time to);

boolean TimeGreaterThan(Time a, Time b);

boolean TimeLessThan(Time a, Time b);

#endif // TIME_H_INCLUDED
