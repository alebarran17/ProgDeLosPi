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

    FILE* expFile = fopen("expedientes.dat", "rb");
    LeerArbolExpedientes(expFile, root);
    fclose(expFile);

    expFile = fopen("expedientes.dat", "wb");

    int total = ContarExpedientes(root);
    if (total > 0) {
        printf("%d expedientes fueron cargados correctamente!\r\n", total);
        printf("\r\n");
    }

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
                    total++;
                }
                break;
            case 2:
                printf("Actualmente hay %d expedientes guardados...\r\n", total);
                ListarExpedientes(root);
                break;
            case 3:
                printf("Ingrese el código del expediente a borrar:\r\n");

                int id;
                do {
                    printf(">> ");
                    scanf("%d", &id);
                } while (BuscarExpediente(root, id) == NULL);

                BorrarExpediente(root, id);
                total--;
                break;
        }
        printf("\r\n");
    }

    total = ContarExpedientes(root);
    if (total > 0) {
        printf("Guardando %d expedientes...\r\n", total);
        GuardarArbolExpedientes(expFile, root);
        printf("Expedientes guardados correctamente!\r\n");
    }

    return 0;
}
