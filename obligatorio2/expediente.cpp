#include "expediente.h"

void CargarExpediente(Expediente &e) {
    printf("=========== CARGAR EXPEDIENTE =========\r\n");

    printf("Ingrese el código:\r\n");
    printf(">> ");
    scanf("%d", &e.id);

    printf("Ingrese la carátula:\r\n");
    printf(">> ");
    scan(e.caratula);

    printf("Ingrese la cantidad de páginas:\r\n");
    printf(">> ");
    scanf("%d", &e.paginas);
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

void GuardarExpediente(FILE* f, Expediente e) {
    fwrite(&e.id, sizeof(int), 1, f);
    GuardarString(e.caratula, f);
    fwrite(&e.paginas, sizeof(int), 1, f);
}

void LeerExpediente(FILE* f, Expediente& e) {
    fread(&e.id, sizeof(int), 1, f);
    LeerString(e.caratula, f);
    fread(&e.paginas, sizeof(int), 1, f);
}
