#include <stdio.h>

#include "menu.h"

// Motrar el menu principal
int IniciarMenu() {
    printf("============= MENU PRINCIPAL ============\r\n");
    printf("1> Expedientes\r\n");
    printf("2> Revisiones\r\n");
    printf("3> Guardar todo\r\n");
    printf("4> Salir\r\n");

    return CargarOpcion(4);
}

// Motrar el menu de expedientes
int MostrarMenuExpedientes() {
    printf("============ MENU EXPEDIENTES ===========\r\n");
    printf("1> Agregar expediente\r\n");
    printf("2> Listar expedientes\r\n");
    printf("3> Listar revisiones\r\n");
    printf("4> Contar expedientes por apellido del escribano\r\n");
    printf("5> Mostrar el primer y �ltimo expediente\r\n");
    printf("6> C�digo del expediente con m�s revisiones\r\n");
    printf("7> Borrar expediente\r\n");
    printf("8> Atr�s\r\n");

    return CargarOpcion(8);
}

// Motrar el menu de revisiones
int MostrarMenuRevisiones() {
    printf("============ MENU REVISIONES ============\r\n");
    printf("1> Agregar revisi�n\r\n");
    printf("2> Listar revisiones\r\n");
    printf("3> Listar revisiones entre fechas\r\n");
    printf("4> Listar revisiones por c�digo\r\n");
    printf("5> Contar revisiones por tipo\r\n");
    printf("6> Atr�s\r\n");

    return CargarOpcion(6);
}

// Devolver la opci�n seleccionada por teclado desde 1 hasta max.
int CargarOpcion(int max) {
    int o;
    do {
        printf(">> ");
        scanf("%d", &o);
    } while (o < 1 || o > max);

    printf("\r\n");

    return o;
}
