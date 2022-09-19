#include <stdio.h>
#include "vehicleType.h"

void LoadVehicleType(VehicleType &vt) {
    int opt = 0;
    do {
        printf("Seleccione el tipo de vehiculo: 1-Auto, 2-Camioneta\r\n");
        scanf("%d", &opt);
    } while (opt != 1 && opt != 2);

    if (opt == 1) {
        vt = CAR;
    } else if (opt == 2) {
        vt = TRUCK;
    }
}
