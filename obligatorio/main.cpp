#include "vehicle.h"
#include "menu.h"

void ProcessSecondaryMenu() {
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
                ProcessSecondaryMenu();
                break;

            // List vehicles
            case 4:
                break;

            // Print vehicle
            case 5:
                break;

            // List vehicles between two times
            case 6:
                ProcessSecondaryMenu();
                break;

            // List of trucks with more kg than...
            case 7:
                break;
        }
    } while (opt != 8);
}

int main()
{
    int opt;
    do {
        opt = ShowMainMenu();
        switch (opt) {
            // New vehicle
            case 1:
                Vehicle v;
                LoadVehicle(v);
                // TODO: add to parking
                break;

            // Charge and remove vehicle
            case 2:
                break;

            // Secondary menu
            case 3:
                ProcessSecondaryMenu();
                break;
        }
    } while (opt != 4);
    return 0;
}
