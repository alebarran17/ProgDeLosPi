#include "boolean.h"
#include <stdio.h>

void carga(boolean &b){
                int num;
                printf("Ingrese un valor: 0-False 1-True:\n");
                scanf("%d", &num);
                if(num==1)
                                b=TRUE;
                else
                                b=FALSE;
}
void mostrar(boolean b){
                if(b==TRUE)
                                printf("EL valor es TRUE");
                else
                                printf("El valor es FALSE");
}
