#include "Stock.h"

void init(Stock &arr) {
    arr.tope = 0;
}

boolean full(Stock arr) {
    if (arr.tope == MAX_STOCK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

boolean includes(Stock arr, int long num) {
    boolean found = FALSE;
    int i = 0;
    while (i < arr.tope && found == FALSE) {
        if (DarNumero(arr.list[i]) == num) {
            found = TRUE;
        }
        i++;
    }

    return found;
}

void add(Stock &arr, Producto prod) {
    arr.list[arr.tope] = prod;
    arr.tope++;
}

boolean empty(Stock arr) {
    if (arr.tope == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void show(Stock arr) {
    printf("Hay %d elemetos en el arreglo...\r\n", arr.tope);
    for (int i = 0; i < arr.tope; i++) {
        MostrarProducto(arr.list[i]);
        printf("\r\n"); // MostrarProducto() no tiene salto de linea
    }
}

void getStock(Stock arr, int &inStock, int &notStock) {
    inStock = 0;
    notStock = 0;

    for (int i = 0; i < arr.tope; i++) {
        Producto p = arr.list[i];
        if (p.en_stock) {
            inStock++;
        } else {
            notStock++;
        }
    }
}

void remove(Stock &arr, int numProd) {
    int idx = 0;
    while (idx < arr.tope && DarNumero(arr[idx]) != numProd) {
        idx++;
    }

    while (idx < arr.tope) {
        arr.list[idx] = arr.list[idx + 1];
        idx++;
    }

    arr.tope--;
}
