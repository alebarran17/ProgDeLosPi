#include "revision.h"

// Cargar la información de una revisión por teclado.
void CargarRevision(Revision &r) {
    printf("============ CARGAR REVISION ==========\r\n");

    printf("Ingrese el código del expediente:\r\n");
    printf(">> ");
    scanf("%d", &r.expedienteId);

    printf("Ingrese una fecha de creación...\r\n");
    CargarFecha(r.fecha, CargarFechaMinima());

    printf("Ingrese una descripción:\r\n");
    printf(">> ");
    scan(r.descripcion);

    CargarResultadoRevision(r.resultado);
}

// Mostrar en pantalla la información de una revisión.
void MostrarRevision(Revision r) {
    printf("Fecha: ");
    MostrarFecha(r.fecha);

    printf(" - Descripción: ");
    print(r.descripcion);

    printf(" - Código del expediente: %d", r.expedienteId);

    printf(" - Estado: ");
    MostrarResultadoRevision(r.resultado);

    printf("\r\n");
}

// Devolver el identificador del expediente de la revision.
int ObtenerExpedienteIdRevision(Revision r) {
    return r.expedienteId;
}

// Devolver la fecha de la revision.
Fecha ObtenerFechaRevision(Revision r) {
    return r.fecha;
}

// Cargar la descripcion de una revision en el string ingresado.
void ObtenerDescripcionRevision(Revision r, string &s) {
    strcop(r.descripcion, s);
}

// Devolver el resultado de la revision.
ResultadoRevision ObtenerResultadoRevision(Revision r) {
    return r.resultado;
}

// Guardar la información de la revision en un archivo.
// Precondicion: El archivo debe venir abierto para escritura
void GuardarRevision(Revision R, FILE * f){
    fwrite(&R.expedienteId, sizeof(int), 1, f);
    GuardarFecha(R.fecha, f);
    GuardarString(R.descripcion, f);
    fwrite(&R.resultado, sizeof(int), 1, f);
}

// Leer la información de la fecha desde un archivo.
// Precondicion: el archivo debe venir abierto para lectura.
void CargarRevision(Revision &R, FILE * f){
    fread(&R.expedienteId, sizeof(int), 1, f);
    LeerFecha(R.fecha, f);
    LeerString(R.descripcion, f);
    fread(&R.resultado, sizeof(int), 1, f);
}
