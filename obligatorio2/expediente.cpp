#include "expediente.h"

// Cargar la informacion del expediente por teclado.
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

// Mostrar en pantalla la informaci�n del expediente ingresado.
void MostrarExpediente(Expediente e) {
    printf("C�digo: %d - ", e.id);

    printf("Car�tula: ");
    print(e.caratula);

    printf(" - Escribano: ");
    MostrarEscribano(e.escribano);

    printf(" - P�ginas: %d", e.paginas);

    printf("\r\n");
}

// Obtener el identificador del expediente ingresado.
int ObtenerIdExpediente(Expediente e) {
    return e.id;
}

// Cargar la caratula del expediente en una string ingresada.
void ObtenerCaratulaExpediente(Expediente e, string &s) {
    strcop(e.caratula, s);
}

// Obtener las paginas del expediente ingresado.
int ObtenerPaginasExpediente(Expediente e) {
    return e.paginas;
}

// Cargar la informaci�n de en escribano con el escribano del expediente ingresado.
void ObtenerEscribano(Expediente expediente, Escribano &escribano) {
    string nombre;
    ObtenerNombreEscribano(expediente.escribano, nombre);

    string apellido;
    ObtenerApellidoEscribano(expediente.escribano, apellido);

    CargarNombreEscribano(escribano, nombre);
    CargarApellidoEscribano(escribano, apellido);
}

// Guardar la informaci�n del expediente en un archivo.
// Precondici�n: El archivo debe estar abierto.
void GuardarExpediente(FILE* f, Expediente e) {
    fwrite(&e.id, sizeof(int), 1, f);
    GuardarString(e.caratula, f);
    fwrite(&e.paginas, sizeof(int), 1, f);
    GuardarEscribano(f, e.escribano);
}

// Cargar la informaci�n del escribano desde un archivo.
// Precondici�n: El archivo debe estar abierto.
void LeerExpediente(FILE* f, Expediente& e) {
    fread(&e.id, sizeof(int), 1, f);
    LeerString(e.caratula, f);
    fread(&e.paginas, sizeof(int), 1, f);
    LeerEscribano(f, e.escribano);
}
