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
    } else {
        fclose(fopen("expedientes.dat", "w"));
    }

    int revTotal = ContarRevisiones(revisiones);
    if (revTotal > 0) {
        printf("[I]: Guardando %d revisiones...\r\n", revTotal);

        FILE* revFile = fopen("revisiones.dat", "wb");
        GuardarListaRevisiones(revisiones, revFile);
        fclose(revFile);

        printf("[I]: Revisiones guardadas correctamente!\r\n");
    } else {
        fclose(fopen("revisiones.dat", "w"));
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

                while (BuscarExpediente(expedientes, ObtenerIdExpediente(e)) != NULL) {
                    printf("[E]: Ya existe un expediente con ese c�digo...\r\n");
                    printf("[E]: Por favor, ingresa un nuevo c�digo de identificaci�n:\r\n");
                    CargarIdExpediente(e);

                    printf("\r\n");
                }

                AgregarExpediente(expedientes, e);
                MostrarExpediente(e);
                printf("[I]: Expediente ingresado correctamente...\r\n");
                break;

            case 2:
                if (expedientes != NULL) {
                    MostrarArbol(expedientes);
                } else {
                    printf("[I]: No hay ning�n expediente guardado\r\n");
                }
                break;

            case 3:
                if (expedientes != NULL) {
                    int id;
                    printf("Ingrese el c�digo del expediente a filtrar:\r\n");
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
                        printf("[E]: No hemos podido encontrar el expediente con el c�digo ingresado...\r\n");
                    }
                } else {
                    printf("[I]: No hay ning�n expediente guardado\r\n");
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
                    printf("[I]: No hay ning�n expediente guardado\r\n");
                }
                break;

            case 5:
                if (expedientes != NULL) {
                    MostrarExpediente(PrimerExpediente(expedientes));
                    MostrarExpediente(UltimoExpediente(expedientes));
                } else {
                    printf("[I]: No hay ning�n expediente guardado\r\n");
                }
                break;

            case 6:
                if (expedientes != NULL) {
                    int rev = -1;
                    int eid = -1;
                    ExpedienteConMasRevisiones(expedientes, revisiones, rev, eid);
                    printf("[I]: El expediente con m�s revisiones es el %d con un total de %d revisiones\r\n", eid, rev);
                } else {
                    printf("[I]: No hay ning�n expediente guardado\r\n");
                }
                break;

            case 7:
                if (expedientes != NULL) {
                    int id;
                    printf("Ingrese el c�digo del expediente a borrar:\r\n");
                    printf(">> ");
                    scanf("%d", &id);
                    printf("\r\n");

                    if (BuscarExpediente(expedientes, id)) {
                        BorrarExpediente(expedientes, id);
                        BorrarRevisiones(revisiones, id);
                        printf("[I]: Expediente eliminado correctamente...\r\n");
                    } else {
                        printf("[E]: No hemos podido encontrar el expediente con el c�digo ingresado...\r\n");
                    }
                } else {
                    printf("[I]: No hay ning�n expediente guardado\r\n");
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
                    while (FechaMayorIgual(ObtenerFechaRevision(r), ultimaFecha) == FALSE) {
                        printf("[E]: La fecha de revisi�n (");
                        MostrarFecha(ObtenerFechaRevision(r));
                        printf(") debe ser mayor a la �ltima ingresada (");
                        MostrarFecha(ultimaFecha);
                        printf(")...\r\n");
                        printf("[E]: Por favor, ingresa una fecha mayor o igual a la �ltima ingresada:\r\n");
                        CargarFechaRevision(r);

                        printf("\r\n");
                    }
                }

                while (BuscarExpediente(expedientes, ObtenerExpedienteIdRevision(r)) == NULL) {
                    printf("[E]: No hemos podido encontrar el expediente con el c�digo ingresado...\r\n");
                    printf("[E]: Por favor, ingresa un c�digo de identificaci�n existente:\r\n");
                    CargarExpedienteIdRevision(r);

                    printf("\r\n");
                }

                InsertarRevision(revisiones, r);
                MostrarRevision(r);
                printf("[I]: Revisi�n ingresada correctamente...\r\n");
                break;

            case 2:
                if (revisiones != NULL) {
                    MostrarLista(revisiones);
                } else {
                    printf("[I]: No hay ninguna revisi�n guardada\r\n");
                }
                break;

            case 3:
                if (revisiones != NULL) {
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
                } else {
                    printf("[I]: No hay ninguna revisi�n guardada\r\n");
                }
                break;

            case 4:
                if (revisiones != NULL) {
                    int id;
                    printf("Ingrese el c�digo del expediente a filtrar:\r\n");
                    printf(">> ");
                    scanf("%d", &id);
                    printf("\r\n");

                    if (BuscarExpediente(expedientes, id) != NULL) {
                        MostrarLista(revisiones, id);
                    } else {
                        printf("[E]: No hemos podido encontrar el expediente con el c�digo ingresado...\r\n");
                    }
                } else {
                    printf("[I]: No hay ninguna revisi�n guardada\r\n");
                }
                break;

            case 5:
                if (revisiones != NULL) {
                    int s, i, p;
                    ContarRevisiones(revisiones, s, i, p);
                    printf("[I]: Hay un total de %d revisiones: %d SATISFACTORIAS, %d INCOMPLETAS y %d PENDIENTES\r\n", s + i + p, s, i, p);
                } else {
                    printf("[I]: No hay ninguna revisi�n guardada\r\n");
                }
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
