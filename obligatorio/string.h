#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"
#include <stdio.h>
const int MAX = 80;
typedef char string[MAX];

//Funcion calcula el largo del string
int strlar(string str);

//Procedimiento muestra el string por pantalla
void print(string str, boolean newLine);

//Procedimiento para cargar un string
void scan(string &str);

//Funcion devuelve TRUE si el primero de ellos es menor (en orden alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(string str1, string str2);

//Funcion devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(string str1, string str2);

//Procedimiento copia el segundo en el primero.
void strcop(string &str1, string str2);

//Procedimiento concatena el 2do string con el primero y lo guarda en el primero
void strcon(string &str1, string str2);

//Procedimiento intercambia el primer string con el 2do
void strswp(string &str1, string &str2);



#endif // STRING_H_INCLUDED
