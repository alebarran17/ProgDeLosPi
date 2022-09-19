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

void GetDepartment(Vehicle v, string &d);

void GetPlate(Vehicle v, string &plate);

long int GetDNI(Vehicle v);

Time GetEntryTime(Vehicle v);

#endif // VEHICLE_H_INCLUDED
