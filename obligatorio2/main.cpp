#include <locale.h>

#include "menu.h"
#include "ABBExpediente.h"
#include "listaRevisiones.h"

Arbol expedientes = NULL;
Lista revisiones = NULL;

void LeerArchivos() {
    FILE* expFile = fopen("expedientes.dat", "rb");
    if (expFile != NULL) LeerArbolExpedientes(expFile, expedientes);
    fclose(expFile);

    int expTotal = ContarExpedientes(expedientes);
    if (expTotal > 0) {
        printf("%d expedientes fueron cargados correctamente!\r\n", expTotal);
    }

    FILE* revFile = fopen("revisiones.dat", "rb");
    if (revFile != NULL) LeerListaRevisiones(revisiones, revFile);
    fclose(revFile);

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        printf("%d revisiones fueron cargadas correctamente!\r\n", revTotal);
    }

    if (revTotal > 0 || expTotal > 0) {
        printf("\r\n");
    }
}

void GuardarArchivos() {
    int expTotal = ContarExpedientes(expedientes);
    if (expTotal > 0) {
        printf("Guardando %d expedientes...\r\n", expTotal);

        FILE* expFile = fopen("expedientes.dat", "wb");
        GuardarArbolExpedientes(expFile, expedientes);

        printf("Expedientes guardados correctamente!\r\n");
    }

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        printf("Guardando %d revisiones...\r\n", revTotal);

        FILE* revFile = fopen("revisiones.dat", "wb");
        GuardarListaRevisiones(revisiones, revFile);

        printf("Revisiones guardadas correctamente!\r\n");
    }
}

void ProcesarMenuExpedientes() {
    int opt;
    while ((opt = MostrarMenuExpedientes()) != 4) {
        switch (opt) {
            case 1:
                Expediente e;
                CargarExpediente(e);

                if (BuscarExpediente(expedientes, e.id)) {
                    printf("Ya existe un expediente con ese código.\r\n");
                } else {
                    AgregarExpediente(expedientes, e);
                }
                break;

            case 2:
                ListarExpedientes(expedientes);
                break;

            case 3:
                printf("Ingrese el código del expediente a borrar:\r\n");

                int id;
                do {
                    printf(">> ");
                    scanf("%d", &id);
                } while (BuscarExpediente(expedientes, id) == NULL);

                BorrarExpediente(expedientes, id);
                break;
        }
        printf("\r\n");
    }
}

void ProcesarMenuRevisiones() {
    int opt;
    while ((opt = MostrarMenuRevisiones()) != 3) {
        switch(opt) {
            case 1:
                Revision r;
                CargarRevision(r);
                InsertarRevision(revisiones, r);
                break;

            case 2:
                MostrarLista(revisiones);
                break;
        }
        printf("\r\n");
    }
}

int main()
{
    setlocale(LC_ALL, "spanish");

    LeerArchivos();

    int opt;
    while ((opt = IniciarMenu()) != 3) {
        switch (opt) {
            case 1:
                ProcesarMenuExpedientes();
                break;
            case 2:
                ProcesarMenuRevisiones();
                break;
        }
    }

    GuardarArchivos();

    return 0;
}
