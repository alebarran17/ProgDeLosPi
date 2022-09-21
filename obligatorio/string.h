#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"
#include <stdio.h>
const int MAX = 80;
typedef char string[MAX];

int strlar(string str);

void print(string str, boolean newLine);

void scan(string &str);

boolean strmen(string str1, string str2);

boolean streq(string str1, string str2);

void strcop(string &str1, string str2);

void strcon(string &str1, string str2);

void strswp(string &str1, string &str2);



#endif // STRING_H_INCLUDED
