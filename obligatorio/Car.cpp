#include "Car.h"
#include "boolean.h"

#include <stdio.h>
#include <locale.h>

//Cargar el auto
void LoadCar(Car &c){
                setlocale(LC_ALL, "spanish");
                printf("Ingrese la marca: ");
                scan(c.Brand);
                printf("Ingrese el a�o: ");
                scanf("%d", &c.Year);
}

//Mostrar el auto
void ShowCar(Car c){
                printf("La marca es: ");
                print(c.Brand, TRUE);
                printf("El a�o es: %d\n", c.Year);
}

//Selectora devuelve la marca.
void GetBrand(Car c, string &brand){
                strcop(brand, c.Brand);
}

//Selectora devuelve el a�o
int GetYear(Car c){
                return c.Year;
}
