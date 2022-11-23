#include <locale.h>

#include "menu.h"
#include "ABBExpediente.h"
#include "listaRevisiones.h"

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

void ProcesarMenuRevisiones(Lista& root, int& total) {
    int opt;
    while ((opt = MostrarMenuRevisiones()) != 3) {
        switch(opt) {
            case 1:
                Revision r;
                CargarRevision(r);
                InsertarRevision(root, r);
                total++;
                break;

            case 2:
                printf("Actualmente hay %d revisiones guardadas...\r\n", total);
                MostrarLista(root);
                break;
        }
        printf("\r\n");
    }
}

int main()
{
    setlocale(LC_ALL, "spanish");

    ABBExpediente* exp = NULL;
    Lista rev = NULL;

    FILE* expFile = fopen("expedientes.dat", "rb");
    if (expFile != NULL) LeerArbolExpedientes(expFile, exp);
    fclose(expFile);

    int expTotal = ContarExpedientes(exp);
    if (expTotal > 0) {
        printf("%d expedientes fueron cargados correctamente!\r\n", expTotal);
    }

    FILE* revFile = fopen("revisiones.dat", "rb");
    if (revFile != NULL) LeerListaRevisiones(rev, revFile);
    fclose(revFile);

    int revTotal = ContarRevisiones(rev);
    if (revTotal > 0) {
        printf("%d revisiones fueron cargadas correctamente!\r\n", revTotal);
    }

    if (revTotal > 0 || expTotal > 0) {
        printf("\r\n");
    }

    int opt;
    while ((opt = IniciarMenu()) != 3) {
        switch (opt) {
            case 1:
                ProcesarMenuExpedientes(exp, expTotal);
                break;
            case 2:
                ProcesarMenuRevisiones(rev, revTotal);
                break;
        }
        printf("\r\n");
    }

    expTotal = ContarExpedientes(exp);
    if (expTotal > 0) {
        printf("Guardando %d expedientes...\r\n", expTotal);

        expFile = fopen("expedientes.dat", "wb");
        GuardarArbolExpedientes(expFile, exp);

        printf("Expedientes guardados correctamente!\r\n");
    }

    revTotal = ContarRevisiones(rev);
    if (revTotal > 0) {
        printf("Guardando %d revisiones...\r\n", revTotal);

        revFile = fopen("revisiones.dat", "wb");
        GuardarListaRevisiones(rev, revFile);

        printf("Revisiones guardadas correctamente!\r\n");
    }

    return 0;
}
