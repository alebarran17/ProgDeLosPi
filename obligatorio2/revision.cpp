#include "revision.h"

void CargarRevision(Revision &r) {
    printf("============ CARGAR REVISION ==========\r\n");

    printf("Ingrese el c�digo del expediente:\r\n");
    printf(">>");
    scanf("%d", &r.expedienteId);

    printf("Ingrese la fecha de creaci�n:\r\n");
    CargarFecha(r.fecha);

    printf("Ingrese una descripci�n:\r\n");
    printf(">>");
    scan(r.descripcion);

    printf("Estado de la revisi�n:\r\n");
    CargarResultadoRevision(r.resultado);
}

void MostrarRevision(Revision r) {
    printf("Fecha: ");
    MostrarFecha(r.fecha);

    printf(" - Descripci�n: ");
    print(r.descripcion);

    printf(" - C�digo del expediente: %d", r.expedienteId);
    printf("\r\n");
}

int ObtenerExpedienteIdRevision(Revision r) {
    return r.expedienteId;
}

Fecha ObtenerFechaRevision(Revision r) {
    return r.fecha;
}

void ObtenerDescripcionRevision(Revision r, string &s) {
    strcop(r.descripcion, s);
}

ResultadoRevision ObtenerResultadoRevision(Revision r) {
    return r.resultado;
}

void GuardarRevision(Revision R, string NomArch){
                FILE * f = fopen(NomArch, "ab");
                fwrite(&R.expedienteId, sizeof(int), 1, f);
                BajarFecha(R.fecha, NomArch);
                Bajar_String(R.descripcion, NomArch);
                fwrite(&R.resultado, sizeof(enum), 1, f);
                fclose(f);
}

//Precondicion: el archivo debe venir abierto para lectura.
void CargarRevision(Revision &R, FILE * f){
                fread(&R.expedienteId, sizeof(int), 1, f);
                CargarFecha(R.fecha, NomArch);
                CargarString(R.descripcion, NomArch);
                fread(&R.resultado, sizeof(enum), 1, f);
}
