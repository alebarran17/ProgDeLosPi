#include "listaRevisiones.h"

void CrearListaRevision(Lista &L){
                L = NULL;
}

boolean VaciaListaRevision(Lista L){
                boolean esVacio = FALSE;
                if (L == NULL)
                esVacio = TRUE;
                return esVacio;
}

/* Precondición: lista NO vacía */
Revision Primero (Lista L){
                return L->infoRev;
}

/* Precondición: lista NO vacía */
void Resto (Lista & L){
                Lista aux = L;
                L = L -> sigRev;
                delete aux;
}

void InsertarRevision (Lista & L, Revision R){
                Lista aux = new ListaRevision;
                if(L == NULL){
                                aux -> infoRev = R;
                                aux -> sigRev = L;
                                L = aux;
                }else{
                                if(ObtenerFechaRevision(R) < ObtenerFechaRevision(L -> infoRev)){
                                                aux -> infoRev = R;
                                                aux -> sigRev = L;
                                                L = aux;
                                } else {
                                InsertarRevision(L -> sigRev, R);
                                }
                }
}

void GuardarListaRevisiones(Lista L, string nomArch){
                FILE * f = fopen("Revisones.dat", "ab");
                while(L != NULL){
                                GuardarRevision(L->infoRev, "Revisiones.dat");
                                L = L->sigRev;
                }
                fclose(f);
}

void LevantarListaRevisiones(Lista &L, string NomArch){
                FILE * f = fopen (NomArch, "rb");
                Revision buffer;
                CrearListaRevision (L);
                CargarRevision (buffer, f);
                while (!feof(f))
                {
                InsertarRevision(L, buffer);
                CargarRevision (buffer, f);
                }
                fclose (f);
}

void ListarRPorExpediente(Lista L, int ID){

}
