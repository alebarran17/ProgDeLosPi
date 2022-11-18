#include "boolean.h"
#include <stdio.h>

void carga(boolean &b){
                int num;
                printf("0-No hay 1-Hay:\n");
                scanf("%d", &num);
                if(num==1)
                                b=TRUE;
                else
                                b=FALSE;
}
void mostrar(boolean b){
                if(b==TRUE)
                                printf("Si");
                else
                                printf("No");
}
