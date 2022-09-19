#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "string.h"
#include "time.h"
#include "vehicleType.h"
#include "Car.h"
#include "Truck.h"

typedef struct {
    string Department;
    string Plate;
    long int DNI;
    Time EntryTime;

    VehicleType Type;
    union {
        Car CarDetails;
        Truck TruckDetails;
    } More;
} Vehicle;

void LoadVehicle(Vehicle &v);

void ShowVehicle(Vehicle v);

void GetDepartment(Vehicle v, string &d);

void GetPlate(Vehicle v, string &plate);

long int GetDNI(Vehicle v);

Time GetEntryTime(Vehicle v);

VehicleType GetVehicleType(Vehicle v);

Car GetCarDetails(Vehicle v);

Truck GetTruckDetails(Vehicle v);

#endif // VEHICLE_H_INCLUDED
