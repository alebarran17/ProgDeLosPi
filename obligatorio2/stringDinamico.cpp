#include "stringDinamico.h"
#include <stdio.h>

void strcrear(string &s) {
    s = new char [1];
    s[0] = '\0';
}

void strdestruir(string &s) {
    delete[] s;
    s = NULL;
}

int strlar(string s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void strcop(string from, string &to) {
    int i = 0;
    strdestruir(to);
    to = new char [strlar(from) + 1];
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

void scan(string &s) {
    fflush(stdin);

    string aux = new char [MAX];

    char c;
    scanf("%c", &c);

    int i = 0;
    while (i < MAX - 1 && c != '\n') {
        aux[i] = c;
        scanf("%c", &c);
        i++;
    }
    aux[i] = '\0';

    strcop(aux, s);
    strdestruir(aux);
}

void strcon(string &s1, string s2) {
    string aux = new char[strlar(s1) + strlar(s2) + 1];

    int i = 0;
    while (s1[i] != '\0') {
        aux[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0') {
        aux[i + j] = s2[j];
        j++;
    }
    aux[i + j] = '\0';

    strcop(aux, s1);
    strdestruir(aux);
}

void strswp(string &s1, string &s2) {
    string aux;
    strcrear(aux);
    strcop(s1, aux);

    strcop(s2, s1);
    strcop(aux, s2);

    strdestruir(aux);
}

void print(string s1) {
    int i = 0;
    while (s1[i] != '\0') {
        printf("%c", s1[i]);
        i++;
    }
}

boolean strmen(string s1, string s2) {
    boolean existe=FALSE;
    int i=0;
    while(i<MAX-1 && !existe){
        if(s1[i]==s2[i])
            i++;
        else
            existe=TRUE;
    }
    if(existe){
        if(s1[i]<s2[i]){
            existe=TRUE;
        }else
            existe=FALSE;
    }else
            existe=FALSE;

    return existe;
}

boolean streq(string s1, string s2){
    boolean iguales = TRUE;
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0' && iguales == TRUE){
        if(s1[i]!=s2[i])
                iguales=FALSE;
        i++;
    }
    if(s1[i]!='\0' || s2[i]!='\0')
                iguales=FALSE;
    return iguales;
}

// Precondici�n: El archivo viene abierto para escritura.
void GuardarString (string s, FILE * f){
    int i=0;
    while(s[i] != '\0'){
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, f);
}

// Precondici�n: El archivo viene abierto para lectura, y el string debe venir creado.
void LeerString (string &s, FILE * f){
    strcrear(s);

    string aux = new char[MAX];
    int i=0;
    fread(&aux[i], sizeof(char), 1, f);
    while(aux[i]!='\0'){
        i++;
        fread(&aux[i], sizeof(char), 1, f);
    }
    strcop(aux, s);
    strdestruir(aux);
}
