#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdio.h>

const int MAX = 200;
typedef char * String;

/// Crea el string con \0
void strcrear(String &s);

/// Libera el espacio de memoria usado por le string
void LiberarString(String &s);

/// Devuelve el largo del string
int strlar(String s);

/// Copia el primer string al segundo
void strcop(String from, String &to);

/// Lee un string desde teclado
void scan(String &s);

/// Despliega una string por pantalla
void print(String s1);

/// Devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.
bool streq(String s1, String s2, bool ignoreCase);

/// Devuelve el string desde donde termina la primer palabra.
void Substr(String &input, int from);

/// Recorta el espacio vacío a los extremos de la cadena.
void Trim(String &input);

/// Recorta el espacio vacío al inicio de la cadena.
void TrimLeft(String &input);

/// Recorta el espacio vacío al final de la cadena.
void TrimRight(String &input);

#endif // STRING_H_INCLUDED
