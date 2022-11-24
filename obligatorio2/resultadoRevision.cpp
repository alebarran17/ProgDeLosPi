#include <stdio.h>

#include "resultadoRevision.h"

void CargarResultadoRevision(ResultadoRevision &r) {
    printf("1> Satisfactoria\r\n");
    printf("2> Incompleta\r\n");
    printf("3> Pendiente\r\n");

    int opt;
    do {
        printf("Ingrese una opcion de las de arriba: \n>> ");
        scanf("%d", &opt);
    } while (opt < 1 || opt > 3);

    switch (opt) {
        case 1:
            r = SATISFACTORIA;
        break;
        case 2:
            r = INCOMPLETA;
        break;
        case 3:
            r = PENDIENTE;
        break;
    }
}

void MostrarResultadoRevision(ResultadoRevision r) {
    switch (r) {
        case SATISFACTORIA:
            printf("Satisfactoria");
        break;
        case INCOMPLETA:
            printf("Incompleta");
        break;
        case PENDIENTE:
            printf("Pendiente");
        break;
        default: 
            printf("Error!");
        break;

    }
}
