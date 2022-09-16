#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED
#include "string.h"

typedef struct{
                string Model;
                float MaxLoad;
}Truck;

//Cargar camioneta
void LoadTruck(Truck &t);

//Mostrar camioneta
void ShowTruck(Truck t);

//selectora devuelve el modelo
void GetModel(Truck t, string &model);

//selectora devuelve la capacidad de carga
float GetMaxLoad(Truck t);

#endif // TRUCK_H_INCLUDED
