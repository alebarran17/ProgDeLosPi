#include "string.h"
#include <stdio.h>

int strlar(string str){
                int lar=0, i=0;
                while(str[i]!='\0' && i<MAX-1){
                                lar++;
                                i++;
                }
                return lar;
}
//parte b
void print(string str){
                int i=0;
                printf("La frase ingresada es: ");
                while(i<MAX-1 && str[i]!='\0'){
                                printf("%c", str[i]);
                                i++;
                }
                printf("\n");
}
//parte c
void scan(string &str){
                char car;
                int i = 0;
                printf ("Ingrese una frase y termine con ENTER: ");
                fflush (stdin);
                scanf ("%c", &car);
                while (car != '\n' && i < MAX-1)
                {
                                str[i] = car;
                                i++;
                                scanf ("%c", &car);
                }
                str[i]= '\0';

}
//parte d hasta aca anda
boolean strmen(string str1, string str2){
    boolean existe=FALSE;
    int i=0;
    while(i<MAX-1 && !existe){
        if(str1[i]==str2[i])
            i++;
        else
            existe=TRUE;
    }
    if(existe)
        if(str1[i]<str2[i])
            return TRUE;
        else
            return FALSE;
    else
            return FALSE;
}
//parte e este anda
boolean streq(string str1, string str2){
                boolean iguales=TRUE;
                int i=0;
                while(i<MAX-1 && iguales && str1[i]!='\0' && str2[i]!='\0' ){
                                if(str1[i]!=str2[i])
                                    iguales=FALSE;
                                else
                                    i++;
                }
                if(str1[i]=='\0' && str2[i]=='\0')
                    return iguales;
                else
                    return FALSE;
}
//parte f
void strcop(string &str1, string str2){
    int i=0;
    while(i<MAX-1 && str2[i]!='\0'){
        str1[i]=str2[i];
        i++;
    }
    str1[i]='\0';
}
void strcon(string &str1, string str2){
    int i=0,j=strlar(str1);
    while(i<MAX-1 && str2[i]!='\0'){
        str1[j+i]=str2[i];
        i++;
    }
    str1[j+i]='\0';
}
void strswp(string &str1, string &str2){
    int i=0;
    char aux;
    while(i<MAX-1){
        aux=str1[i];
        str1[i]=str2[i];
        str2[i]=aux;
        i++;
    }
}
