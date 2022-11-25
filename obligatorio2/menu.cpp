#include <stdio.h>

#include "menu.h"

int IniciarMenu() {
    printf("============= MENU PRINCIPAL ============\r\n");
    printf("1> Expedientes\r\n");
    printf("2> Revisiones\r\n");
    printf("3> Salir\r\n");

    return CargarOpcion(3);
}

int MostrarMenuExpedientes() {
    printf("============ MENU EXPEDIENTES ===========\r\n");
    printf("1> Agregar expediente\r\n");
    printf("2> Listar expedientes\r\n");
    printf("3> Contar expedientes por apellido del escribano\r\n");
    printf("4> Mostrar el primer y último expediente\r\n");
    printf("5> Código del expediente con más revisiones\r\n");
    printf("6> Borrar expediente\r\n");
    printf("7> Atrás\r\n");

    return CargarOpcion(7);
}

int MostrarMenuRevisiones() {
    printf("============ MENU REVISIONES ============\r\n");
    printf("1> Agregar revisión\r\n");
    printf("2> Listar revisiones\r\n");
    printf("3> Listar revisiones por código\r\n");
    printf("4> Atrás\r\n");

    return CargarOpcion(4);
}

int CargarOpcion(int max) {
    int o;
    do {
        printf(">> ");
        scanf("%d", &o);
    } while (o < 1 || o > max);

    printf("\r\n");

    return o;
}
