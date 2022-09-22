#include "Parking.h"
#include "menu.h"

void ProcessSecondaryMenu(Parking park) {
    int opt;
    do {
        opt = ShowSecondaryMenu();
        switch (opt) {
            // Total income
            case 1:
                ShowIncome(park);
                break;

            // Count cars and trucks separately
            case 2:
                int cars, trucks;
                Quantity(park, cars, trucks);
                printf("Total autos: %d\r\n", cars);
                printf("Total Camionetas: %d\r\n", trucks);
                break;

            // Number of vehicles from a specific department
            case 3:
                string depa;
                printf("Ingrese el departamento: ");
                scan(depa);

                printf("Hay %d vehiculos en el departamento ingresado\r\n", QuantityPerDepartment(park, depa));
                break;

            // List vehicles
            case 4:
                ShowVehicles(park);
                break;

            // Print vehicle
            case 5:
                string plate;
                printf("Ingrese la matricula: ");
                scan(plate);

                ShowVehicle(park.ArrVehicle[GetVehiclePos(park, plate)]);
                break;

            // List vehicles between two times
            case 6:
                Time from;
                Time to;
                printf("--- Desde ---\r\n");
                LoadTime(from);

                printf("--- Hasta ---\r\n");
                LoadTime(to);

                ShowVehiclesBetween(park, from, to);
                break;

            // List of trucks with more kg than...
            case 7:
                float kg;
                printf("Ingrese la capacidad de carga en kg: ");
                scanf("%f", &kg);

                ShowTrucksWithMoreKGThan(park, kg);
                break;
        }
        printf("\r\n");
    } while (opt != 8);
}

int main()
{
    Parking park;
    LoadParking(park);

    int opt;
    do {
        opt = ShowMainMenu();
        switch (opt) {
            // New vehicle
            case 1:
                if (IsFull(park) == TRUE) {
                    printf("Estacionamiento lleno\r\n");
                } else {
                    Vehicle v;
                    LoadVehicle(v);
                    InsertVehicle(park, v);
                }
                break;

            // Charge and remove vehicle
            case 2:
                if (IsEmpty(park) == TRUE) {
                    printf("Estacionamiento vacio\r\n");
                } else {
                    string plate;
                    printf("Ingrese la matricula del vehiculo a eliminar: ");
                    scan(plate);

                    if (HasVehicle(park, plate) == TRUE) {
                        Vehicle v = GetVehicle(park, plate);
                        Time now;
                        printf("Ingrese la hora actual: \r\n");
                        do {
                            LoadTime(now);
                            if (TimeLessThan(GetEntryTime(v), now)) {
                                printf("El vehiculo no puede salir antes de que entro\r\n");
                            }
                        } while (TimeLessThan(GetEntryTime(v), now));

                        RemoveVehicle(park, plate, now);
                    } else {
                        printf("El vehiculo no existe\r\n");
                    }
                }
                break;

            // Secondary menu
            case 3:
                ProcessSecondaryMenu(park);
                break;
        }
        printf("\r\n");
    } while (opt != 4);
    return 0;
}
