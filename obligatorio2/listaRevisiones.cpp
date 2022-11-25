#include "listaRevisiones.h"

//Procedimiento: Crea una lista vacia.
void CrearListaRevision(Lista &L){
    L = NULL;
}

//Procedimiento: Imprime la lista.
void MostrarLista(Lista root) {
    if (root != NULL) {
        MostrarRevision(root->infoRev);
        MostrarLista(root->sigRev);
    }
}

//Procedimiento: Muestra las revisiones con el id que le pasa.
void MostrarLista(Lista root, int expedienteId) {
    if (root != NULL) {
        if (ObtenerExpedienteIdRevision(root->infoRev) == expedienteId) {
            MostrarRevision(root->infoRev);
        }
        MostrarLista(root->sigRev, expedienteId);
    }
}

//Funcion: Devuelve TRUE si la lista esta vacia, FALSE en caso contrario.
boolean VaciaListaRevision(Lista L){
    boolean esVacio = FALSE;
    if (L == NULL)
    esVacio = TRUE;
    return esVacio;
}

//Funcion: Devuelve la primer revision.
/* Precondición: lista NO vacía */
Revision Primero (Lista L){
    return L->infoRev;
}

//Procedimiento: Devuelve del segundo en adelante.
/* Precondición: lista NO vacía */
void Resto (Lista & L){
    Lista aux = L;
    L = L -> sigRev;
    delete aux;
}

//Procedimiento: Inserta una revision en la lista.
void InsertarRevision (Lista & L, Revision R){
    Lista aux = new ListaRevision;
    if(L == NULL) {
        aux -> infoRev = R;
        aux -> sigRev = L;
        L = aux;
    } else if(FechaMasReciente(ObtenerFechaRevision(R), ObtenerFechaRevision(L -> infoRev))) {
        aux -> infoRev = R;
        aux -> sigRev = L;
        L = aux;
    } else {
        InsertarRevision(L -> sigRev, R);
    }
}

//Procedimiento: Guarda la lista en un archivo.
//Precondicion: El archivo debe venir abierto para escritura
void GuardarListaRevisiones(Lista L, FILE * f){
    while(L != NULL){
        GuardarRevision(L->infoRev, f);
        L = L->sigRev;
    }
}

//Procedimiento: Lee una lista desde un archivo.
//Precondicion: El archivo debe venir abierto para lectura
void LeerListaRevisiones(Lista &root, FILE * f){
    Revision buffer;
    root = NULL;
    CargarRevision (buffer, f);

    while (!feof(f)) {
        InsertarRevision(root, buffer);
        CargarRevision (buffer, f);
    }
}

//Funcion: Cuenta la cantidad de revisiones.
int ContarRevisiones(Lista root) {
    if (root != NULL) {
        return 1 + ContarRevisiones(root->sigRev);
    } else {
        return 0;
    }
}

//Funcion: Cuenta la cantidad de revisiones con el ID de expediente ingresado.
int ContarRevisiones(Lista root, int expedienteId) {
    if (root != NULL) {
        if (ObtenerExpedienteIdRevision(root->infoRev) == expedienteId) {
            return 1 + ContarRevisiones(root->sigRev, expedienteId);
        } else {
            return ContarRevisiones(root->sigRev, expedienteId);
        }
    } else {
        return 0;
    }
}

//Procedimiento: Devuelve la cantidad de revisiones satisfactorias, incompletas, y pendientes.
void ContarRevisiones(Lista root, int& s, int& i, int& p) {
    s = i = p = 0;
    while (root != NULL) {
        ResultadoRevision r = ObtenerResultadoRevision(root->infoRev);
        switch (r) {
            case SATISFACTORIA:
                s++;
                break;
            case INCOMPLETA:
                i++;
                break;
            case PENDIENTE:
                p++;
                break;

        }

        root = root->sigRev;
    }
}

//Funcion: Cuenta la cantidad de revisiones entre dos fechas.
int ContarRevisiones(Lista root, Fecha desde, Fecha hasta) {
    int total = 0;
    while (root != NULL) {
        Fecha fechaRev = ObtenerFechaRevision(root->infoRev);
        if (FechaMayorIgual(hasta, fechaRev) == TRUE && FechaMayorIgual(fechaRev, desde) == TRUE) {
            total++;
        }
        root = FechaMayorIgual(fechaRev, desde) == TRUE ? root->sigRev : NULL;
    }
    return total;
}

//Procedimiento: Borra una revision de la lista.
void BorrarRevisiones (Lista &root, int expedienteId) {
    if (root != NULL) {
        if (ObtenerExpedienteIdRevision(root->infoRev) == expedienteId) {
            Lista aux = root;
            root = root->sigRev;
            delete aux;
            BorrarRevisiones(root, expedienteId);
        } else {
            BorrarRevisiones(root->sigRev, expedienteId);
        }
    }
}
