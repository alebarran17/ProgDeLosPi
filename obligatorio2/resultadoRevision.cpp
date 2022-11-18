#include <stdio.h>

#include "resultadoRevision.h"

void CargarResultadoRevision(ResultadoRevision &r) {
    printf("1> Satisfactoria\r\n");
    printf("2> Incompleta\r\n");
    printf("3> Pendiente\r\n");

    int opt;
    do {
        printf(">> ");
        scanf("%d", &opt);
    } while (opt < 1 || opt > 3);

    switch (opt) {
        case 1:
            r = SATISFACTORIA;

        case 2:
            r = INCOMPLETA;

        case 3:
            r = PENDIENTE;

    }
}

void MostrarResultadoRevision(ResultadoRevision r) {

}