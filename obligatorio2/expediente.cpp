#include "expediente.h"

void CargarExpediente(Expediente &e) {
    printf("==== Cargar expediente ====\r\n");

    printf("Ingrese el c�digo: ");
    scanf("%d", &e.id);

    printf("\r\n");

    printf("Ingrese la car�tula: ");
    scan(e.caratula);

    printf("\r\n");

    printf("Ingrese la cantidad de p�ginas: ");
    scanf("%d", &e.paginas);

    printf("\r\n");
}

void MostrarExpediente(Expediente e) {
    printf("C�digo: %d - ", e.id);

    printf("Car�tula: ");
    print(e.caratula);

    printf(" - P�ginas: %d", e.paginas);

    printf("\r\n");
}

int ObtenerIdExpediente(Expediente e) {
    return e.id;
}

void ObtenerCaratulaExpediente(Expediente e, string &s) {
    strcop(e.caratula, s);
}

int ObtenerPaginasExpediente(Expediente e) {
    return e.paginas;
}
