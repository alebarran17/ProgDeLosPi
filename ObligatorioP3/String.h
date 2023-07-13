#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdio.h>

const int MAX = 200;
typedef char * String;

//Crea el string con \0
void strcrear(String &s);

//Devuelve el largo del string
int strlar(String s);

//Copia el primer string al segundo
void strcop(String from, String &to);

//Lee un string desde teclado
void scan(String &s);

//Concatena dos string
void strcon(String &s1, String s2);

//Cambia el primer string con el segundo
void strswp(String &s1, String &s2);

//Despliega una string por pantalla
void print(String s1);

//Devuelva TRUE si el primero de ellos es menor (en orden alfab�tico) que el segundo, o FALSE en caso contrario.
bool strmen(String s1, String s2);

//Devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.
bool streq(String s1, String s2, bool ignoreCase);

// Precondici�n: El archivo viene abierto para escritura.
void GuardarString(String s, FILE * f);

// Precondici�n: El archivo viene abierto para lectura.
void LeerString(String &s, FILE * f);

//Verifica que nombre sea alfab�tico
bool NombreAlfabetico(String nom);

//Pasa a mayusculas el String
void PasarMayus(String &nombre);

//Verifica que el parametro sea "->"
bool EsFlecha(String flecha);

//Libera el espacio de memoria usado por le string
void LiberarString(String &s);

//Devuelve la primera palabra del string
void PrimerPalabra(String &input, String &palabra);

//Elimina los espacios que esten delante de la primer palabra.
void Recortar(String &input);

//Devuelve el string desde donde termina la primer palabra.
void Substr(String &input, int from);

//Devuelve si el string es vacio
bool StringVacio(String input);

//Valida que el formato de la fecha sea valido
bool ValidarFormato(String fecha);

#endif // STRING_H_INCLUDED
