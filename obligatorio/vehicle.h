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

//Carga del Vehiculo
void LoadVehicle(Vehicle &v);

//Muestra del vehiculo
void ShowVehicle(Vehicle v);

//Procedimiento devuelve el departamento
void GetDepartment(Vehicle v, string &d);

//Procedimiento devuelve la matricula
void GetPlate(Vehicle v, string &plate);

//Funcion devuelve la cedula
long int GetDNI(Vehicle v);

//Funcion devuelve el tiempo de entrada
Time GetEntryTime(Vehicle v);

//Funcion devuelve el tipo de vehiculo
VehicleType GetVehicleType(Vehicle v);

//Funcion devuelve los datos del auto
Car GetCarDetails(Vehicle v);

//Funcion devuelve los datos de la camioneta
Truck GetTruckDetails(Vehicle v);

//Funcion devuelve la matricula, la cedula del conductor y la hora de entrada de un auto
void ShowVehicleMin(Vehicle v, boolean addEntryTime);

#endif // VEHICLE_H_INCLUDED
