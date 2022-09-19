#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

typedef struct {
    int Hours;
    int Minutes;
} Time;

void LoadTime(Time &time);

void ShowTime(Time time);

int GetHours(Time time);

int GetMinutes(Time time);

Time GetDifference(Time from, Time to);

#endif // TIME_H_INCLUDED
