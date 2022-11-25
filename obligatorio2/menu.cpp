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
    printf("4> Borrar expediente\r\n");
    printf("5> Atr�s\r\n");

    return CargarOpcion(5);
}

int MostrarMenuRevisiones() {
    printf("============ MENU REVISIONES ============\r\n");
    printf("1> Agregar revisi�n\r\n");
    printf("2> Listar revisiones\r\n");
    printf("3> Listar revisiones por c�digo\r\n");
    printf("4> Atr�s\r\n");

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
