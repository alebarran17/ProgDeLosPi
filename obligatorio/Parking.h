#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED
#include "Vehicle.h"
const int MAX_Park = 50;

typedef struct{
    Vehicle ArrVehicle[MAX_Park];
    int Max;
} Parking;

//Procedimiento inicia el Tope en uno
void init(Parking &arr);

//Funcion dice si el arreglo esta lleno
boolean Full(Parking arr);

//Funcion devuelve TRUE si el elemento existe o FALSE si no existe
boolean Includes(Parking arr, string p);

//Procedimiento añade un vehiculo al arreglo
//Precondicion: Debe existir un lugar en el estacionamiento.
void AddVehicle(Parking &arr, Vehicle v);

//Funcion dice si el arreglo esta vacio
boolean Empty(Parking arr);

//Muestra los elementos del arreglo
void Show(Parking arr);

//Procedimiento Borra el vehiculo seleccionado
//Precondicion: El vehiculo seleccionado debe estar cargado
void RemoveVehicle(Parking arre, string p);





#endif // PARKING_H_INCLUDED
