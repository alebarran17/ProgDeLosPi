#include <stdio.h>
#include "Producto.h"
//cargar un produto por teclado
void CargarProducto(Producto &p){
                printf("Ingrese nombre:");
                scan(p.nombre);

                printf("Ingrese un numero: ");
                scanf("%ld", &p.numero);

                printf("Ingrese un precio: ");
                scanf("%f", &p.precio);

                printf("Ingrese si esta en stock: ");
                carga(p.en_stock);

                printf("Ingrese la fecha: ");
                CargarFecha(p.fecha_adquisicion);

}

//Mostrar un producto por pantalla
void MostrarProducto(Producto p){
                printf("El nombre del producto es: ");
                print(p.nombre);
                printf("\nEl numero es: %ld", p.numero);
                printf("\nEl precio es: %f", p.precio);
                printf("\nEsta en stock: \n");
                mostrar(p.en_stock);
                printf("\nLa fecha de adquisicion es: ");
                MostrarFecha(p.fecha_adquisicion);
}

//Selectora devuelve el nombre
void DarNombre(Producto p, string &nom){
                strcop(nom, p.nombre);
}

//Selectora devuelve el numero
long int DarNumero(Producto p){
                return p.numero;
}

//Selectora devuelve el precio
float DarPrecio(Producto p){
                return p.precio;
}

//Selectora devuelve si esta en stock el producto
boolean DarEnStock(Producto p){
                return p.en_stock;
}

//Selectora devuelve fecha
Fecha DarFechaAdquisicion(Producto p){
                return p.fecha_adquisicion;
}
