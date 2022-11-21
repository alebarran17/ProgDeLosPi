#include "expediente.h"

void CargarExpediente(Expediente &e) {
    printf("=========== CARGAR EXPEDIENTE =========\r\n");

    printf("Ingrese el c�digo:\r\n");
    printf(">>");
    scanf("%d", &e.id);

    printf("Ingrese la car�tula:\r\n");
    printf(">>");
    scan(e.caratula);

    printf("Ingrese la cantidad de p�ginas:\r\n");
    printf(">>");
    scanf("%d", &e.paginas);
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
