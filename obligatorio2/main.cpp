#include <locale.h>

#include "ABBExpediente.h"

int MostrarMenuPrincipal() {
    printf("============ MENU PRINCIPAL ===========\r\n");
    printf("1> Agregar expediente\r\n");
    printf("2> Listar expedientes\r\n");
    printf("3> Borrar expediente\r\n");
    printf("4> Salir\r\n");

    int o;
    do {
        printf(">> ");
        scanf("%d", &o);
    } while (o < 1 || o > 4);

    printf("\r\n");

    return o;
}

int main()
{
    setlocale(LC_ALL, "spanish");

    ABBExpediente* root = NULL;

    int opt;
    while ((opt = MostrarMenuPrincipal()) != 4) {
        switch (opt) {
            case 1:
                Expediente e;
                CargarExpediente(e);

                if (BuscarExpediente(root, e.id)) {
                    printf("Ya existe un expediente con ese código.\r\n");
                } else {
                    AgregarExpediente(root, e);
                }
                break;
            case 2:
                ListarExpedientes(root);
                break;
            case 3:
                printf("Ingrese el código del expediente a borrar:\r\n");
                Expediente* ptr = NULL;
                int id;
                do {
                    printf(">> ");
                    scanf("%d", &id);

                    ptr = BuscarExpediente(root, id);
                } while (ptr == NULL);

                BorrarExpediente(root, id);
                break;
        }
        printf("\r\n");
    }

    return 0;
}
