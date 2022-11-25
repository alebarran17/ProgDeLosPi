#include "expediente.h"

void CargarExpediente(Expediente &e) {
    printf("=========== CARGAR EXPEDIENTE =========\r\n");

    printf("Ingrese el c�digo:\r\n");
    printf(">> ");
    scanf("%d", &e.id);

    printf("Ingrese la car�tula:\r\n");
    printf(">> ");
    scan(e.caratula);

    printf("Ingrese la cantidad de p�ginas:\r\n");
    printf(">> ");
    scanf("%d", &e.paginas);

    CargarEscribano(e.escribano);
}

void MostrarExpediente(Expediente e) {
    printf("C�digo: %d - ", e.id);

    printf("Car�tula: ");
    print(e.caratula);

    printf(" - Escribano: ");
    MostrarEscribano(e.escribano);

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

void ObtenerEscribano(Expediente expediente, Escribano &escribano) {
    string nombre;
    ObtenerNombreEscribano(expediente.escribano, nombre);

    string apellido;
    ObtenerApellidoEscribano(expediente.escribano, apellido);

    CargarNombreEscribano(escribano, nombre);
    CargarApellidoEscribano(escribano, apellido);
}

void GuardarExpediente(FILE* f, Expediente e) {
    fwrite(&e.id, sizeof(int), 1, f);
    GuardarString(e.caratula, f);
    fwrite(&e.paginas, sizeof(int), 1, f);
    GuardarEscribano(f, e.escribano);
}

void LeerExpediente(FILE* f, Expediente& e) {
    fread(&e.id, sizeof(int), 1, f);
    LeerString(e.caratula, f);
    fread(&e.paginas, sizeof(int), 1, f);
    LeerEscribano(f, e.escribano);
}
