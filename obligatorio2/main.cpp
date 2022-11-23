#include <locale.h>

#include "logger.h"
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
        info("%d expedientes fueron cargados correctamente!", expTotal);
    }

    FILE* revFile = fopen("revisiones.dat", "rb");
    if (revFile != NULL) LeerListaRevisiones(revisiones, revFile);
    fclose(revFile);

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        info("%d revisiones fueron cargadas correctamente!", revTotal);
    }

    if (revTotal > 0 || expTotal > 0) {
        printf("\r\n");
    }
}

void GuardarArchivos() {
    int expTotal = ContarExpedientes(expedientes);
    if (expTotal > 0) {
        info("Guardando %d expedientes...", expTotal);

        FILE* expFile = fopen("expedientes.dat", "wb");
        GuardarArbolExpedientes(expFile, expedientes);

        info("Expedientes guardados correctamente!");
    }

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        info("Guardando %d revisiones...", revTotal);

        FILE* revFile = fopen("revisiones.dat", "wb");
        GuardarListaRevisiones(revisiones, revFile);

        info("Revisiones guardadas correctamente!");
    }
}

void ProcesarMenuExpedientes() {
    int opt;
    while ((opt = MostrarMenuExpedientes()) != 4) {
        switch (opt) {
            case 1:
                Expediente e;
                CargarExpediente(e);
                printf("\r\n");

                if (!BuscarExpediente(expedientes, e.id)) {
                    AgregarExpediente(expedientes, e);
                    info("Expediente ingresado correctamente...");
                } else {
                    error("Ya existe un expediente con ese código...");
                }
                break;

            case 2:
                ListarExpedientes(expedientes);
                break;

            case 3:
                int id;
                printf("Ingrese el código del expediente a borrar:\r\n");
                printf(">> ");
                scanf("%d", &id);
                printf("\r\n");

                if (BuscarExpediente(expedientes, id)) {
                    BorrarExpediente(expedientes, id);
                    info("Expediente eliminado correctamente...");
                } else {
                    error("No hemos podido encontrar el expediente con el código ingresado...");
                }
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
                printf("\r\n");

                if (BuscarExpediente(expedientes, r.expedienteId)) {
                    InsertarRevision(revisiones, r);
                    info("Revisión ingresada correctamente...");
                } else {
                    error("No hemos podido encontrar el expediente con el código ingresado...");
                }
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
