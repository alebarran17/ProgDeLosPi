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

void ShowVehicle(Vehicle v) {
    printf("Empadronado en: ");
    print(v.Department);

    printf("Matrícula: ");
    print(v.Plate);

    printf("Cedula del conductor: %d\r\n", v.DNI);

    printf("Hora de entrada: ");
    ShowTime(v.EntryTime);

    printf("Tipo de vehiculo: %s\r\n", v.Type == CAR ? "auto" : "camioneta");

    if (v.Type == CAR) {
        ShowCar(v.More.CarDetails);
    } else {
        ShowTruck(v.More.TruckDetails);
    }
}
