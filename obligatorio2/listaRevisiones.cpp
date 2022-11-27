#include "listaRevisiones.h"

// Mostrar en pantalla todas las revisiones.
void MostrarLista(Lista root) {
    if (root != NULL) {
        MostrarRevision(root->infoRev);
        MostrarLista(root->sigRev);
    }
}

// Mostrar en pantalla todas las revisiones cuya relación con
// el expediente sea igual al ingresado.
void MostrarLista(Lista root, int expedienteId) {
    if (root != NULL) {
        if (ObtenerExpedienteIdRevision(root->infoRev) == expedienteId) {
            MostrarRevision(root->infoRev);
        }
        MostrarLista(root->sigRev, expedienteId);
    }
}

// Devolver TRUE si la lista esta vacia, FALSE en caso contrario.
boolean VaciaListaRevision(Lista L){
    boolean esVacio = FALSE;
    if (L == NULL)
    esVacio = TRUE;
    return esVacio;
}

// Agregar una revision a la lista.
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

// Guardar la información de todas las revisiones en un archivo.
// Precondicion: El archivo debe venir abierto para escritura.
void GuardarListaRevisiones(Lista L, FILE * f){
    while(L != NULL){
        GuardarRevision(L->infoRev, f);
        L = L->sigRev;
    }
}

// Cargar la información de todas las revisiones desde un archivo.
// Precondicion: El archivo debe venir abierto para lectura.
void LeerListaRevisiones(Lista &root, FILE * f){
    Revision buffer;
    root = NULL;
    CargarRevision (buffer, f);

    while (!feof(f)) {
        InsertarRevision(root, buffer);
        CargarRevision (buffer, f);
    }
}

// Devolver la cantidad total de revisiones en la lista.
int ContarRevisiones(Lista root) {
    if (root != NULL) {
        return 1 + ContarRevisiones(root->sigRev);
    } else {
        return 0;
    }
}

// Devolver la cantidad total de revisiones cuyo codigo de
// identificacion del expediente sea igual al ingresado.
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

// Devolver la cantidad total de revisiones en la lista por resultado.
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

// Devolver la cantidad total de revisiones en la lista dentro de un
// rango de fechas.
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

// Eliminar las revisiones de la lista con el codigo de
// identificacion del expediente ingresado.
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
