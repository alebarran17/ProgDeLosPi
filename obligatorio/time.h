#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

typedef struct {
    int Hours;
    int Minutes;
} Time;

void loadTime(Time &time);

int getHours(Time time);

int getMinutes(Time time);

Time getDifference(Time from, Time to);

#endif // TIME_H_INCLUDED
