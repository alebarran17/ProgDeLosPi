#include "listaRevisiones.h"

void CrearListaRevision(Lista &L){
                L = NULL;
}

void MostrarLista(Lista root) {
    if (root != NULL) {
        MostrarRevision(root->infoRev);
        MostrarLista(root->sigRev);
    }
}

boolean VaciaListaRevision(Lista L){
                boolean esVacio = FALSE;
                if (L == NULL)
                esVacio = TRUE;
                return esVacio;
}

/* Precondici�n: lista NO vac�a */
Revision Primero (Lista L){
                return L->infoRev;
}

/* Precondici�n: lista NO vac�a */
void Resto (Lista & L){
                Lista aux = L;
                L = L -> sigRev;
                delete aux;
}

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

//Precondicion: El archivo debe venir abierto para escritura
void GuardarListaRevisiones(Lista L, FILE * f){
    while(L != NULL){
        GuardarRevision(L->infoRev, f);
        L = L->sigRev;
    }
}

//Precondicion: El archivo debe venir abierto para leectura
void LeerListaRevisiones(Lista &root, FILE * f){
    Revision buffer;
    root = NULL;
    CargarRevision (buffer, f);

    while (!feof(f)) {
        InsertarRevision(root, buffer);
        CargarRevision (buffer, f);
    }
}

void ListarRPorExpediente(Lista L, int ID){

}
