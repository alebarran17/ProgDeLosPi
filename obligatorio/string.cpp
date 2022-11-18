#include "string.h"
#include <stdio.h>

//Funcion calcula el largo del string
int strlar(string str){
                int lar=0, i=0;
                while(str[i]!='\0' && i<MAX-1){
                                lar++;
                                i++;
                }
                return lar;
}

//Procedimiento muestra el string por pantalla
void print(string str, boolean newLine){
                int i=0;
                while(i<MAX-1 && str[i]!='\0'){
                                printf("%c", str[i]);
                                i++;
                }
                if (newLine == TRUE) {
                    printf("\n");
                }
}

//Procedimiento para cargar un string
void scan(string &str){
                char car;
                int i = 0;
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

//Funcion devuelve TRUE si el primero de ellos es menor (en orden alfabético) que el segundo, o FALSE en caso contrario.
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

//Funcion devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
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

//Procedimiento copia el segundo en el primero.
void strcop(string &str1, string str2){
    int i=0;
    while(i<MAX-1 && str2[i]!='\0'){
        str1[i]=str2[i];
        i++;
    }
    str1[i]='\0';
}

//Procedimiento concatena el 2do string con el primero y lo guarda en el primero
void strcon(string &str1, string str2){
    int i=0,j=strlar(str1);
    while(i<MAX-1 && str2[i]!='\0'){
        str1[j+i]=str2[i];
        i++;
    }
    str1[j+i]='\0';
}

//Procedimiento intercambia el primer string con el 2do
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
