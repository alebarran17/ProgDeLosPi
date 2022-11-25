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
        printf("[I]: %d expedientes fueron cargados correctamente!\r\n", expTotal);
    }

    FILE* revFile = fopen("revisiones.dat", "rb");
    if (revFile != NULL) LeerListaRevisiones(revisiones, revFile);
    fclose(revFile);

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        printf("[I]: %d revisiones fueron cargadas correctamente!\r\n", revTotal);
    }

    if (revTotal > 0 || expTotal > 0) {
        printf("\r\n");
    }
}

void GuardarArchivos() {
    int expTotal = ContarExpedientes(expedientes);
    if (expTotal > 0) {
        printf("[I]: Guardando %d expedientes...\r\n", expTotal);

        FILE* expFile = fopen("expedientes.dat", "wb");
        GuardarArbolExpedientes(expFile, expedientes);

        printf("[I]: Expedientes guardados correctamente!\r\n");
    }

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        printf("[I]: Guardando %d revisiones...\r\n", revTotal);

        FILE* revFile = fopen("revisiones.dat", "wb");
        GuardarListaRevisiones(revisiones, revFile);

        printf("[I]: Revisiones guardadas correctamente!\r\n");
    }
}

void ProcesarMenuExpedientes() {
    int opt;
    while ((opt = MostrarMenuExpedientes()) != 7) {
        switch (opt) {
            case 1:
                Expediente e;
                CargarExpediente(e);
                printf("\r\n");

                if (!BuscarExpediente(expedientes, e.id)) {
                    AgregarExpediente(expedientes, e);
                    MostrarExpediente(e);
                    printf("[I]: Expediente ingresado correctamente...\r\n");
                } else {
                    printf("[E]: Ya existe un expediente con ese código...\r\n");
                }
                break;

            case 2:
                if (expedientes != NULL) {
                    MostrarArbol(expedientes);
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;

            case 3:
                if (expedientes != NULL) {
                    string apellido;
                    printf("Ingrese el apellido del escribano:\r\n");
                    printf(">> ");
                    scan(apellido);

                    printf("[I]: Hay un total de %d expedientes con ese apellido\r\n", ContarExpedientes(expedientes, apellido));
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;

            case 4:
                if (expedientes != NULL) {
                    MostrarExpediente(PrimerExpediente(expedientes));
                    MostrarExpediente(UltimoExpediente(expedientes));
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;

            case 5:
                if (expedientes != NULL) {
                    int rev = -1;
                    int eid = -1;
                    ExpedienteConMasRevisiones(expedientes, revisiones, rev, eid);
                    printf("[I]: El expediente con más revisiones es el %d con un total de %d revisiones\r\n", eid, rev);
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;

            case 6:
                if (expedientes != NULL) {
                    int id;
                    printf("Ingrese el código del expediente a borrar:\r\n");
                    printf(">> ");
                    scanf("%d", &id);
                    printf("\r\n");

                    if (BuscarExpediente(expedientes, id)) {
                        BorrarExpediente(expedientes, id);
                        BorrarRevisiones(revisiones, id);
                        printf("[I]: Expediente eliminado correctamente...\r\n");
                    } else {
                        printf("[E]: No hemos podido encontrar el expediente con el código ingresado...\r\n");
                    }
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;
        }
        printf("\r\n");
    }
}

void ProcesarMenuRevisiones() {
    int opt;
    while ((opt = MostrarMenuRevisiones()) != 5) {
        switch(opt) {
            case 1:
                Revision r;
                CargarRevision(r);
                printf("\r\n");

                if (BuscarExpediente(expedientes, r.expedienteId)) {
                    InsertarRevision(revisiones, r);
                    MostrarRevision(r);
                    printf("[I]: Revisión ingresada correctamente...\r\n");
                } else {
                    printf("[E]: No hemos podido encontrar el expediente con el código ingresado...\r\n");
                }
                break;

            case 2:
                MostrarLista(revisiones);
                break;

            case 3:
                int id;
                printf("Ingrese el código del expediente a filtrar:\r\n");
                printf(">> ");
                scanf("%d", &id);
                printf("\r\n");

                if (BuscarExpediente(expedientes, id)) {
                    MostrarLista(revisiones, id);
                } else {
                    printf("[E]: No hemos podido encontrar el expediente con el código ingresado...\r\n");
                }
                break;

            case 4:
                int s, i, p;
                ContarRevisiones(revisiones, s, i, p);
                printf("[I]: Hay un total de %d revisiones: %d SATISFACTORIAS, %d INCOMPLETAS y %d PENDIENTES\r\n", s + i + p, s, i, p);
                break;
        }
        printf("\r\n");
    }
}

int main() {
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
