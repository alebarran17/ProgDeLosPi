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
        fclose(expFile);

        printf("[I]: Expedientes guardados correctamente!\r\n");
    }

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        printf("[I]: Guardando %d revisiones...\r\n", revTotal);

        FILE* revFile = fopen("revisiones.dat", "wb");
        GuardarListaRevisiones(revisiones, revFile);
        fclose(revFile);

        printf("[I]: Revisiones guardadas correctamente!\r\n");
    }

    if (revTotal == 0 && expTotal == 0) {
        printf("[I]: No hay cambios para guardar...\r\n");
    }
}

void ProcesarMenuExpedientes() {
    int opt;
    while ((opt = MostrarMenuExpedientes()) != 8) {
        switch (opt) {
            case 1:
                Expediente e;
                CargarExpediente(e);
                printf("\r\n");

                if (!BuscarExpediente(expedientes, ObtenerIdExpediente(e))) {
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
                    int id;
                    printf("Ingrese el código del expediente a filtrar:\r\n");
                    printf(">> ");
                    scanf("%d", &id);
                    printf("\r\n");

                    if (BuscarExpediente(expedientes, id)) {
                        int c = ContarRevisiones(revisiones, id);
                        if (c > 0) {
                            printf("El expediente %d tiene un total de %d revisiones:\r\n", id, c);
                            MostrarLista(revisiones, id);
                        } else {
                            printf("[E]: No existen revisiones asociadas al expediente seleccionado...\r\n");
                        }
                    } else {
                        printf("[E]: No hemos podido encontrar el expediente con el código ingresado...\r\n");
                    }
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;

            case 4:
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

            case 5:
                if (expedientes != NULL) {
                    MostrarExpediente(PrimerExpediente(expedientes));
                    MostrarExpediente(UltimoExpediente(expedientes));
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;

            case 6:
                if (expedientes != NULL) {
                    int rev = -1;
                    int eid = -1;
                    ExpedienteConMasRevisiones(expedientes, revisiones, rev, eid);
                    printf("[I]: El expediente con más revisiones es el %d con un total de %d revisiones\r\n", eid, rev);
                } else {
                    printf("[I]: No hay ningún expediente guardado\r\n");
                }
                break;

            case 7:
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
    while ((opt = MostrarMenuRevisiones()) != 6) {
        switch(opt) {
            case 1:
                Revision r;
                CargarRevision(r);
                printf("\r\n");

                if (revisiones != NULL) {
                    Fecha ultimaFecha = ObtenerFechaRevision(revisiones->infoRev);
                    if (FechaMayorIgual(ultimaFecha, ObtenerFechaRevision(r)) == TRUE) {
                        printf("[E]: La fecha de revisión (");
                        MostrarFecha(ObtenerFechaRevision(r));
                        printf(") debe ser mayor a la última ingresada (");
                        MostrarFecha(ultimaFecha);
                        printf(")...\r\n");

                        break;
                    }
                }

                if (BuscarExpediente(expedientes, ObtenerExpedienteIdRevision(r))) {
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
                Fecha from, to;

                printf("Ingresa una fecha de inicio...\r\n");
                CargarFecha(from, CargarFechaMinima());
                printf("\r\n");

                printf("Ingresa una fecha de fin...\r\n");
                CargarFecha(to, from);
                printf("\r\n");

                printf("[I]: Hay %d revisiones creadas desde ", ContarRevisiones(revisiones, from, to));
                MostrarFecha(from);
                printf(" hasta ");
                MostrarFecha(to);
                printf(" inclusive\r\n");
                break;

            case 4:
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

            case 5:
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
    while ((opt = IniciarMenu()) != 4) {
        switch (opt) {
            case 1:
                ProcesarMenuExpedientes();
                break;
            case 2:
                ProcesarMenuRevisiones();
                break;
            case 3:
                GuardarArchivos();
                printf("\r\n");
                break;
        }
    }

    GuardarArchivos();

    return 0;
}
