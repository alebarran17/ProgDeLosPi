#include <stdio.h>

#include "resultadoRevision.h"

// Cargar la información del resultado de una revision
// por teclado.
void CargarResultadoRevision(ResultadoRevision &r) {
    printf("Estado de la revisión (1-SATISFACTORIA, 2-INCOMPLETA, 3-PENDIENTE):\r\n");

    int opt;
    do {
        printf(">> ");
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

// Mostrar en pantalla la información del resultado
// de una revision.
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
