#include <stdio.h>

#include "menu.h"

//Funcion muestra el menu principal
int ShowMainMenu() {
    printf("--------------------\r\n");
    printf("-- Menu principal --\r\n");
    printf("--------------------\r\n");

    printf("1> Registrar ingreso de un vehiculo\r\n");
    printf("2> Registrar partida de un vehiculo\r\n");
    printf("3> Menu de consultas y listados\r\n");
    printf("4> Salir\r\n");

    int opt;
    do {
        printf(">> ");
        scanf("%d", &opt);
    } while (opt < 1 || opt > 4);

    printf("\r\n");

    return opt;
}

//Funcion muestra el menu secundario
int ShowSecondaryMenu() {
    printf("-------------------------\r\n");
    printf("-- Consultas y listado --\r\n");
    printf("-------------------------\r\n");

    printf("1> Total recaudado hasta el momento por concepto de tickets\r\n");
    printf("2> Cantidad de autos y cantidad de camionetas registrados actualmente\r\n");
    printf("3> Cantidad de vehiculos matriculados en un departamento determinado\r\n");
    printf("4> Listado de vehiculos registrados actualmente\r\n");
    printf("5> Listado detallado de un vehículo\r\n");
    printf("6> Listado de vehiculos que ingresaron dentro de una hora determinada\r\n");
    printf("7> Listado de camionetas que superan una capacidad de carga determinada\r\n");
    printf("8> Volver al menu principal\r\n");

    int opt;
    do {
        printf(">> ");
        scanf("%d", &opt);
    } while (opt < 1 || opt > 8);

    printf("\r\n");

    return opt;
}
