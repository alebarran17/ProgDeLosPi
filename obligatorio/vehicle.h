#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "string.h"

typedef struct {
    string Plate;
    long int DNI;
    Time EntryTime;
} Vehicle;

void getPlate(Vehicle v, string &plate);

long int getDNI(Vehicle v);

Time getEntryTime(Vehicle v);

#endif // VEHICLE_H_INCLUDED
