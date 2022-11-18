#include <locale.h>

#include "expediente.h"
#include "revision.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    Expediente e;
    CargarExpediente(e);
    MostrarExpediente(e);
    printf("\r\n");

    Revision r;
    CargarRevision(r);
    MostrarRevision(r);
    return 0;
}
