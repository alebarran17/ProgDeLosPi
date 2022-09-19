#include "Parking.h"
#include "menu.h"

void ProcessSecondaryMenu(Parking park) {
    int opt;
    do {
        opt = ShowSecondaryMenu();
        switch (opt) {
            // Total income
            case 1:
                break;

            // Count cars and trucks separately
            case 2:
                break;

            // Number of vehicles from a specific department
            case 3:
                break;

            // List vehicles
            case 4:
                ShowVehicles(park);
                break;

            // Print vehicle
            case 5:
                break;

            // List vehicles between two times
            case 6:
                break;

            // List of trucks with more kg than...
            case 7:
                break;
        }
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
                Vehicle v;
                LoadVehicle(v);
                InsertVehicle(park, v);
                break;

            // Charge and remove vehicle
            case 2:
                string plate;
                printf("Ingrese la matricula del vehiculo a eliminar: ");
                scan(plate);

                RemoveVehicle(park, plate);
                break;

            // Secondary menu
            case 3:
                ProcessSecondaryMenu(park);
                break;
        }
    } while (opt != 4);
    return 0;
}
