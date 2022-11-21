#include <locale.h>

#include "ABBExpediente.h"

int MostrarMenuPrincipal() {
    printf("1> Agregar expediente\r\n");
    printf("2> Salir\r\n");

    int o;
    do {
        printf(">> ");
        scanf("%d", &o);
    } while (o < 1 || o > 2);

    return o;
}

int main()
{
    setlocale(LC_ALL, "spanish");

    ABBExpediente* root;

    int opt;
    while ((opt = MostrarMenuPrincipal()) != 2) {
        switch (opt) {
            case 1:
                Expediente e;
                CargarExpediente(e);
                AgregarExpediente(root, e);
                break;
        }
    }

    return 0;
}
