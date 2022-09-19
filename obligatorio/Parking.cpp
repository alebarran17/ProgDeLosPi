#include "Parking.h"
#include <stdio.h>

void LoadParking(Parking &arr) {
    arr.Max = 0;
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

void RemoveVehicle(Parking &arre, string p){
    int idx = GetVehiclePos(arre, p);
    if (idx >= 0) {
        for (int i = idx; i < arre.Max; i++) {
            arre.ArrVehicle[i + 1] = arre.ArrVehicle[i];
        }
        arre.Max--;
    }
}

while(i<arr.Max && !exist){
    GetPlate(arr.ArrVehicle(i), strAux);
    if(streq(strAux, p))
        existe=TRUE
    else
        i++;
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
    return found == TRUE ? -1 : i;
}
