#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include "string.h"

typedef struct{
                string Brand;
                int Year;
}Car;

//Cargar el auto
void LoadCar(Car &c);

//Mostrar el auto
void ShowCar(Car c);

//Selectora devuelve la marca.
void GetBrand(Car c, string &brand);

//Selectora devuelve el año
int GetYear(Car c);

#endif // CAR_H_INCLUDED
