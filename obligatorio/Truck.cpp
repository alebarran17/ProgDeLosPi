#include "Truck.h"
#include <stdio.h>

//Cargar camioneta
void LoadTruck(Truck &t){
                printf("Ingrese el modelo de la camioneta: ");
                scan(t.Model);
                printf("Ingrese la capacidad de carga en kg: ");
                scanf("%f", &t.MaxLoad);
}

//Mostrar camioneta
void ShowTruck(Truck t){
                printf("El modelo de la camioneta es: ");
                print(t.Model, TRUE);
                printf("La capacidad de carga es de: %5.2f kilos\n", t.MaxLoad);
}

//selectora devuelve el modelo
void GetModel(Truck t, string &model){
                strcop(model, t.Model );
}

//selectora devuelve la capacidad de carga
float GetMaxLoad(Truck t){
                return t.MaxLoad;
}
