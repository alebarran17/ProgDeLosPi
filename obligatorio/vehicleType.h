#ifndef VEHICLETYPE_H_INCLUDED
#define VEHICLETYPE_H_INCLUDED

typedef enum { CAR, TRUCK } VehicleType;

//Carga el tipo de vehiculo
void LoadVehicleType(VehicleType &vt);

//Muestra el tipo de vehiculo
void ShowVehicleType(VehicleType v);

#endif // VEHICLETYPE_H_INCLUDED
