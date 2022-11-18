#include "Parking.h"
#include "Truck.h"
#include <stdio.h>

//Procedimiento inicia el Tope en 0, y el ingreso en 0.
void LoadParking(Parking &arr) {
    arr.Max = 0;
    arr.Income = 0;
}

//Funcion dice si el arreglo esta lleno
boolean IsFull(Parking arr) {
    return arr.Max == MAX_Park ? TRUE : FALSE;
}

//Funcion devuelve TRUE si el elemento existe o FALSE si no existe
boolean HasVehicle(Parking arr, string p) {
    return GetVehiclePos(arr, p) >= 0 ? TRUE : FALSE;
}

//Procedimiento añade un vehiculo al arreglo
//Precondicion: Debe existir un lugar en el estacionamiento.
void InsertVehicle(Parking &arr, Vehicle v) {
    arr.ArrVehicle[arr.Max] = v;
    arr.Max++;
}

//Funcion dice si el arreglo esta vacio
boolean IsEmpty(Parking arr) {
    return arr.Max == 0 ? TRUE : FALSE;
}

//Muestra los elementos del arreglo
void ShowVehicles(Parking arr) {
    printf("Hay %d de vehiculos en el estacionamiento...\r\n", arr.Max);
    for (int i = 0; i < arr.Max; i++) {
        ShowVehicleMin(arr.ArrVehicle[i], TRUE);
        printf("\r\n");
    }
}

//Procedimiento Borra el vehiculo seleccionado
//Precondicion: El vehiculo seleccionado debe estar cargado
void RemoveVehicle(Parking &arre, string p, Time t){
    int idx = GetVehiclePos(arre, p);
    if (idx >= 0) {
        Vehicle v = arre.ArrVehicle[idx];
        Time time = GetDifference(GetEntryTime(v), t);

        printf("Tiempo total: \r\n");
        ShowTime(time, TRUE);

        int income = 100 * time.Hours;
        if (time.Minutes > 0) {
            income += 60;
        }
        printf("Ingresos: %d\r\n", income);

        for (int i = idx; i < arre.Max; i++) {
            arre.ArrVehicle[i + 1] = arre.ArrVehicle[i];
        }

        arre.Max--;
        arre.Income += income;
    }
}

//procedimiento devuelve la cantidad de autos y de camionetas
void Quantity(Parking arr, int &quantCar, int &quantTrucks){
    quantCar=0;
    quantTrucks=0;
    for(int i=0; i<arr.Max; i++){
        if(GetVehicleType(arr.ArrVehicle[i])==TRUCK)
            quantTrucks=quantTrucks+1;
        else
            quantCar=quantCar+1;
    }
}

// Devuelve un entero positivo si existe, o -1 si no existe
int GetVehiclePos(Parking arre, string plate) {
    int i = 0;
    boolean found = FALSE;

    string strAux;
    while(i < arre.Max && found == FALSE){
        GetPlate(arre.ArrVehicle[i], strAux);
        if(streq(strAux, plate))
            found = TRUE;
        else
            i++;
    }
    return found == TRUE ? i : -1;
}

//Funcion devuelve los ingresos hasta el momento
int GetIncome(Parking arre) {
    return arre.Income;
}

//Procedimiento muestra los ingresos
void ShowIncome(Parking arre) {
    printf("Total recaudado: %d\r\n", arre.Income);
}

//Funcion cuenta la cantidad de autos que hay por departamento ingresado
int QuantityPerDepartment(Parking p, string depa) {
    int c = 0;
    for(int i = 0; i < p.Max; i++) {
        string aux;
        GetDepartment(p.ArrVehicle[i], aux);
        if (streq(aux, depa)) {
            c++;
        }
    }

    return c;
}

//Procedimiento muestra los vehiculos que estan entre dos horas
void ShowVehiclesBetween(Parking p, Time from, Time to) {
    int total = 0;
    for(int i = 0; i < p.Max; i++) {
        Time entryTime = GetEntryTime(p.ArrVehicle[i]);
        if (TimeGreaterThan(from, entryTime) && TimeLessThan(to, entryTime)) {
            ShowVehicleMin(p.ArrVehicle[i], FALSE);
            printf("\r\n");
            total++;
        }
    }
    printf("Total: %d\r\n", total);
}

//Procedimiento muestra las camionetas con carga mas alta a la ingresada
void ShowTrucksWithMoreKGThan(Parking p, float kg) {
    int total = 0;
    for(int i = 0; i < p.Max; i++) {
        VehicleType vt = GetVehicleType(p.ArrVehicle[i]);
        if (vt == TRUCK) {
            float actualKg = GetMaxLoad(GetTruckDetails(p.ArrVehicle[i]));
            if (actualKg > kg) {
                ShowVehicleMin(p.ArrVehicle[i], FALSE);

                Truck truck = GetTruckDetails(p.ArrVehicle[i]);
                string m;
                GetModel(truck, m);

                printf(", modelo: ");
                print(m, TRUE);

                total++;
            }
        }
    }
    printf("Total: %d\r\n", total);
}

// Devuelve el vehículo en el arreglo según su matrícula
// Precondición: El vehiculo está en el arreglo.
Vehicle GetVehicle(Parking park, string plate) {
    int idx = GetVehiclePos(park, plate);
    return park.ArrVehicle[idx];
}
