#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "string.h"
#include "time.h"

typedef struct {
    string Department;
    string Plate;
    long int DNI;
    Time EntryTime;
} Vehicle;

void LoadVehicle(Vehicle &v);

void getDepartment(Vehicle v, string &d);

void getPlate(Vehicle v, string &plate);

long int getDNI(Vehicle v);

Time getEntryTime(Vehicle v);

#endif // VEHICLE_H_INCLUDED
