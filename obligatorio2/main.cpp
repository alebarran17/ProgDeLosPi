#include <locale.h>

#include "ABBExpediente.h"
#include "menu.h"

void ProcesarMenuExpedientes(ABBExpediente*& root, int& total) {
    int opt;
    while ((opt = MostrarMenuExpedientes()) != 4) {
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
}

void ProcesarMenuRevisiones() {
int opt;
    while ((opt = MostrarMenuRevisiones()) != 1) {
        printf("\r\n");
    }
}

int main()
{
    setlocale(LC_ALL, "spanish");

    ABBExpediente* root = NULL;

    FILE* expFile = fopen("expedientes.dat", "rb");
    if (expFile != NULL) LeerArbolExpedientes(expFile, root);
    fclose(expFile);

    int total = ContarExpedientes(root);
    if (total > 0) {
        printf("%d expedientes fueron cargados correctamente!\r\n", total);
        printf("\r\n");
    }

    int opt;
    while ((opt = IniciarMenu()) != 3) {
        switch (opt) {
            case 1:
                ProcesarMenuExpedientes(root, total);
                break;
            case 2:
                ProcesarMenuRevisiones();
                break;
        }
        printf("\r\n");
    }

    total = ContarExpedientes(root);
    if (total > 0) {
        printf("Guardando %d expedientes...\r\n", total);

        expFile = fopen("expedientes.dat", "wb");
        GuardarArbolExpedientes(expFile, root);

        printf("Expedientes guardados correctamente!\r\n");
    }

    return 0;
}
