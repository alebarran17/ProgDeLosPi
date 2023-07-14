#include "menu.h"
#include <stdio.h>

int MenuPrincipal() {
    printf("======================================\r\n");
    printf("====   Universidad de los capos   ====\r\n");
    printf("====                              ====\r\n");
    printf("====        MENÚ PRINCIPAL        ====\r\n");
    printf("======================================\r\n");
    printf("1> Asignaturas...\r\n");
    printf("2> Previas...\r\n");
    printf("3> Alumnos...\r\n");
    printf("4> Salir\r\n");

    return CargarOpcion(1, 4);
}

int MenuAsignaturas() {
    printf("======================================\r\n");
    printf("====   Universidad de los capos   ====\r\n");
    printf("====                              ====\r\n");
    printf("====         ASIGNATURAS          ====\r\n");
    printf("======================================\r\n");

    /// REST
    printf("1> Agregar asignatura\r\n");
    printf("2> Listar asignaturas\r\n");
    printf("3> Atrás\r\n");

    return CargarOpcion(1, 3);
}

int MenuPrevias() {
    printf("======================================\r\n");
    printf("====   Universidad de los capos   ====\r\n");
    printf("====                              ====\r\n");
    printf("====           PREVIAS            ====\r\n");
    printf("======================================\r\n");

    /// REST
    printf("1> Listar previas\r\n");
    printf("2> Agregar previa\r\n");
    printf("3> Atrás\r\n");

    return CargarOpcion(1, 3);
}

int MenuAlumno() {
    printf("======================================\r\n");
    printf("====   Universidad de los capos   ====\r\n");
    printf("====                              ====\r\n");
    printf("====           ALUMNOS            ====\r\n");
    printf("======================================\r\n");

    /// REST
    printf("1> Mostrar alumno\r\n");
    printf("2> Agregar alumno\r\n");
    printf("3> Agregar asignatura a escolaridad\r\n");
    printf("4> Listar escolaridad de alumno\r\n");
    printf("5> Atrás\r\n");

    return CargarOpcion(1, 5);
}

int CargarOpcion(int min, int max) {
    int o;
    do {
        printf(">> ");
        scanf("%d", &o);
    } while (o < min || o > max);

    printf("\r\n");

    return o;
}
