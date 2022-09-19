#include "Parking.h"
#include <stdio.h>

void LoadParking(Parking &arr) {
    arr.Max = 0;
    arr.Income = 0;
}

boolean IsFull(Parking arr) {
    return arr.Max == MAX_Park ? TRUE : FALSE;
}

boolean HasVehicle(Parking arr, string p) {
    return GetVehiclePos(arr, p) >= 0 ? TRUE : FALSE;
}

void InsertVehicle(Parking &arr, Vehicle v) {
    arr.ArrVehicle[arr.Max] = v;
    arr.Max++;
}

boolean IsEmpty(Parking arr) {
    return arr.Max == 0 ? TRUE : FALSE;
}

void ShowVehicles(Parking arr) {
    printf("Hay %d elemetos en el arreglo...\r\n", arr.Max);
    for (int i = 0; i < arr.Max; i++) {
        ShowVehicle(arr.ArrVehicle[i]);
        printf("\r\n");
    }
}

void RemoveVehicle(Parking &arre, string p, Time t){
    int idx = GetVehiclePos(arre, p);
    if (idx >= 0) {
        Vehicle v = arre.ArrVehicle[idx];
        Time time = GetDifference(GetEntryTime(v), t);

        printf("Tiempo total: \r\n");
        ShowTime(time);

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

int GetIncome(Parking arre) {
    return arre.Income;
}

void ShowIncome(Parking arre) {
    printf("Total recaudado: %d\r\n", arre.Income);
}
