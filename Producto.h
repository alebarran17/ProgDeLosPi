#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "string.h"
#include "Fecha.h"

typedef struct{
                string nombre;
                long int numero;
                float precio;
                boolean en_stock;
                Fecha fecha_adquisicion;
}Producto;

//cargar un produto por teclado
void CargarProducto(Producto &p);

//Mostrar un producto por pantalla
void MostrarProducto(Producto p);

//Selectora devuelve el nombre
void DarNombre(Producto p, string &nom);

//Selectora devuelve el numero
long int DarNumero(Producto p);

//Selectora devuelve el precio
float DarPrecio(Producto p);

//Selectora devuelve si esta en stock el producto
boolean DarEnStock(Producto p);

//Selectora devuelve fecha
Fecha DarFechaAdquisicion(Producto p);


#endif // PRODUCTO_H_INCLUDED
