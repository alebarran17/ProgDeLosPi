#include "expediente.h"

void CargarExpediente(Expediente &e) {
    printf("==== Cargar expediente ====\r\n");

    printf("Ingrese el código: ");
    scanf("%d", &e.id);

    printf("\r\n");

    printf("Ingrese la carátula: ");
    scan(e.caratula);

    printf("\r\n");

    printf("Ingrese la cantidad de páginas: ");
    scanf("%d", &e.paginas);

    printf("\r\n");
}

void MostrarExpediente(Expediente e) {
    printf("Código: %d - ", e.id);

    printf("Carátula: ");
    print(e.caratula);

    printf(" - Páginas: %d", e.paginas);

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
