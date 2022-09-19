#include "Parking.h"
#include <stdio.h>

void Init(Parking &arr) {
    arr.Max = 0;
}

boolean Full(Parking arr) {
    if (arr.Max == MAX_Park) {
        return TRUE;
    } else {
        return FALSE;
    }
}

boolean IncludesVehicle(Parking arr, string p) {
    boolean exist=FALSE;
    i=0;
    string strAux;
    while(i<arr.Max && !exist){
    GetPlate(arr.ArrVehicle(i), strAux);
    if(streq(strAux, p))
        existe=TRUE
    else
        i++;
    }
    return exist;
}

void InsertVehicle(Parking &arr, Vehicle v) {
    arr.ArrVehicle[arr.Max] = v;
    arr.Max++;
}

boolean Empty(Parking arr) {
    if (arr.Max == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void ShowVehicles(Parking arr) {
    printf("Hay %d elemetos en el arreglo...\r\n", arr.Max);
    for (int i = 0; i < arr.Max; i++) {
        ShowVehicle(arr.ArrVehicle[i]);
        printf("\r\n");
    }

void RemoveVehicle(Parking arre, string p){
    boolean exist=FALSE;
    i=0;
    string strAux;
    while(i<arr.Max && !exist){
    GetPlate(arr.ArrVehicle(i), strAux);
    if(streq(strAux, p))
        existe=TRUE
    else
        i++;
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


