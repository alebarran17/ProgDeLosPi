#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED
#include "vehicle.h"
const int MAX_Park = 3;

typedef struct{
    Vehicle ArrVehicle[MAX_Park];
    int Max;
    int Income;
} Parking;

//Procedimiento inicia el Tope en uno
void LoadParking(Parking &arr);

//Funcion dice si el arreglo esta lleno
boolean IsFull(Parking arr);

//Funcion devuelve TRUE si el elemento existe o FALSE si no existe
boolean HasVehicle(Parking arr, string p);

//Procedimiento añade un vehiculo al arreglo
//Precondicion: Debe existir un lugar en el estacionamiento.
void InsertVehicle(Parking &arr, Vehicle v);

//Funcion dice si el arreglo esta vacio
boolean IsEmpty(Parking arr);

//Muestra los elementos del arreglo
void ShowVehicles(Parking arr);

//Procedimiento Borra el vehiculo seleccionado
//Precondicion: El vehiculo seleccionado debe estar cargado
void RemoveVehicle(Parking &arre, string p, Time t);

//procedimiento devuelve la cantidad de autos y de camionetas
void Quantity(Parking arr, int &quantCar, int &quantTrucks);

// Devuelve un entero positivo si existe, o -1 si no existe
int GetVehiclePos(Parking arre, string plate);

// Devuelve el vehículo en el arreglo según su matrícula
// Precondición: El vehiculo está en el arreglo.
Vehicle GetVehicle(Parking arre, string plate);

int GetIncome(Parking arre);

void ShowIncome(Parking arre);

int QuantityPerDepartment(Parking arr, string depa);

void ShowVehiclesBetween(Parking arr, Time from, Time to);

void ShowTrucksWithMoreKGThan(Parking arr, float kg);


#endif // PARKING_H_INCLUDED
