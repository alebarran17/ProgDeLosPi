#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include "Producto.h"

const int MAX_STOCK = 50;
typedef struct {
    Producto list[MAX_STOCK];
    int tope;
} Stock;

void init(Stock &arr);

boolean full(Stock arr);

boolean includes(Stock arr, int long num);

// Precondicion: el arreglo no puede estar lleno
void add(Stock &arr, Producto prod);

boolean empty(Stock arr);

void show(Stock arr);

void getStock(Stock arr, int &inStock, int &notStock);

// Precondicion: el producto está en el arreglo
void remove(Stock &arr, int idx);

#endif // STOCK_H_INCLUDED
