#include <stdio.h>
#include "Stock.h"

int getAction() {
    printf("Selecciona una opcion:\r\n");
    printf("1> ¿Esta lleno?...\r\n");
    printf("2> ¿Esta vacio?...\r\n");
    printf("3> ¿Existe?...\r\n");
    printf("4> Agregar producto...\r\n");
    printf("5> Mostrar lista\r\n");
    printf("6> Obtener productos en stock y sin stock\r\n");
    printf("7> Eliminar producto...\r\n");
    printf(">> ");

    int opt;
    scanf("%d", &opt);
    return opt;
}

int main()
{
    Stock s;
    init(s);

    while (true) {
        int opt = getAction();

        switch (opt) {
            case 1:
                mostrar(full(s));
                printf("\r\n");
                break;
            case 2:
                mostrar(empty(s));
                printf("\r\n");
                break;
            case 3:
                int num;
                printf("Ingrese el numero del producto que quiere buscar: ");
                scanf("%d", &num);

                mostrar(includes(s, num));
                printf("\r\n");
                break;
            case 4:
                Producto p;
                CargarProducto(p);
                add(s, p);
                printf("\r\n"); // CargarProducto() no tiene salto de linea
                break;
            case 5:
                show(s);
                break;
            case 6:
                int stock, notStock;
                getStock(s, stock, notStock);
                printf("En stock: %d\r\n", stock);
                printf("Sin stock: %d\r\n", notStock);
            case 7:
                int pos;
                printf("Ingrese la posicion del producto que quiere eliminar: ");
                scanf("%d", &pos);
                printf("\r\n");
                remove(s, pos);

                printf("Elemento eliminado.\r\n");
                break;
        }
    }

    return 0;
}
