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
    do {
        LoadTime(v.EntryTime);

        if (GetHours(v.EntryTime) == 22) {
            printf("El vehiculo no puede entrar despues las 22:00\r\n");
        }
    } while (GetHours(v.EntryTime) == 22);

    LoadVehicleType(v.Type);
    if (v.Type == CAR) {
        LoadCar(v.More.CarDetails);
    } else {
        LoadTruck(v.More.TruckDetails);
    }
}

void ShowVehicle(Vehicle v) {
    printf("Empadronado en: ");
    print(v.Department, TRUE);

    printf("Matrícula: ");
    print(v.Plate, TRUE);

    printf("Cedula del conductor: %d\r\n", v.DNI);

    printf("Hora de entrada: ");
    ShowTime(v.EntryTime, TRUE);

    printf("Tipo de vehiculo: ");
    ShowVehicleType(v.Type);

    if (v.Type == CAR) {
        ShowCar(v.More.CarDetails);
    } else {
        ShowTruck(v.More.TruckDetails);
    }
}

void GetDepartment(Vehicle v, string &d) {
    strcop(d, v.Department);
}

void GetPlate(Vehicle v, string &d) {
    strcop(d, v.Plate);
}

long int GetDNI(Vehicle v) {
    return v.DNI;
}

Time GetEntryTime(Vehicle v) {
    return v.EntryTime;
}

VehicleType GetVehicleType(Vehicle v) {
    return v.Type;
}

Car GetCarDetails(Vehicle v) {
    return v.More.CarDetails;
}

Truck GetTruckDetails(Vehicle v) {
    return v.More.TruckDetails;
}

void ShowVehicleMin(Vehicle v, boolean addEntryTime) {
    printf("Matricula: ");
    print(v.Plate, FALSE);

    printf(", cedula del conductor: %d", v.DNI);

    if (addEntryTime == TRUE) {
        printf(", hora de entrada: ");
        ShowTime(v.EntryTime, FALSE);
    }
}
