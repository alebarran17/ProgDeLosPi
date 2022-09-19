#include "string.h"
#include "vehicle.h"

void LoadVehicle(Vehicle &v) {
    printf("Ingrese el departamento donde el vehiculo fue empadronado: ");
    scan(v.Department);

    printf("Ingrese la matricula: ");
    scan(v.Plate);

    printf("Ingrese la cedula del conductor: ");
    scanf("%ld", &v.DNI);

    printf("Cargue la hora de entrada...\r\n");
    LoadTime(v.EntryTime);

    LoadVehicleType(v.Type);
    if (v.Type == CAR) {
        LoadCar(v.More.CarDetails);
    } else {
        LoadTruck(v.More.TruckDetails);
    }
}
