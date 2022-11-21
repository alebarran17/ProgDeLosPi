#ifndef STRINGDINAMICO_H_INCLUDED
#define STRINGDINAMICO_H_INCLUDED
#include "boolean.h"
#include <stdio.h>
const int MAX = 80;
typedef char* string;

void strcrear(string &s);

void strdestruir(string &s);

int strlar(string s);

void strcop(string from, string &to);

void scan(string &s);

void strcon(string &s1, string s2);

void strswp(string &s1, string &s2);

void print(string s1);

boolean strmen(string s1, string s2);

boolean streq(string s1, string s2);

// Precondición: El archivo viene abierto para escritura.
void GuardarString(string s, FILE * f);

// Precondición: El archivo viene abierto para lectura.
void CargarString(string &s, FILE * f);

#endif // STRINGDINAMICO_H_INCLUDED
