#include "ABBExpediente.h"

//Procedimiento: Agrega un expediente.
void AgregarExpediente(Arbol& root, Expediente e) {
    if (root == NULL) {
        root = new ABBExpediente;
        root->izq = NULL;
        root->der = NULL;
        root->info = e;
    } else if (ObtenerIdExpediente(root->info) > ObtenerIdExpediente(e)) {
        AgregarExpediente(root->izq, e);
    } else {
        AgregarExpediente(root->der, e);
    }
}

//Procedimiento: Muestra los expedientes.
void MostrarArbol(Arbol root) {
    if (root != NULL) {
        MostrarArbol(root->izq);
        MostrarExpediente(root->info);
        MostrarArbol(root->der);
    }
}

//Funcion: Devuelve el primer expediente.
Expediente PrimerExpediente(Arbol root) {
    return root->izq == NULL ? root->info : PrimerExpediente(root->izq);
}

//Funcion: devuelve el ultimo expediente.
Expediente UltimoExpediente(Arbol root) {
    return root->der == NULL ? root->info : PrimerExpediente(root->der);
}

//Funcion: Devuelve un expediente con el numero de id ingresado.
Expediente* BuscarExpediente(Arbol root, int id) {
    if (root == NULL) {
        return NULL;
    } else if (ObtenerIdExpediente(root->info) == id) {
        return &root->info;
    } else if (ObtenerIdExpediente(root->info) > id) {
        return BuscarExpediente(root->izq, id);
    } else {
        return BuscarExpediente(root->der, id);
    }
}
//Procedimiento: Borra el expediente del id ingresado. 
//Precondicion: El expediente deber existir.
void BorrarExpediente(Arbol& root, int id) {
    if (ObtenerIdExpediente(root->info) == id) {
        Arbol aux;
        if (root->der == NULL) {
            aux = root->izq;
            delete root;
            root = aux;
        } else if (root->izq == NULL) {
            aux = root->der;
            delete root;
            root = aux;
        } else {
            root->info = BuscarExpedienteMinimo(root)->info;
            BorrarExpediente(root->der, ObtenerIdExpediente(root->info));
        }
    } else if (ObtenerIdExpediente(root->info) > id) {
        BorrarExpediente(root->izq, id);
    } else {
        BorrarExpediente(root->der, id);
    }
}

//Funcion: Busca el expediente con menor id.
Arbol BuscarExpedienteMinimo(Arbol root) {
    return root->der != NULL ? root->der : root;
}

//Procedimiento: Lee el arbol de un archivo.
//Precondicion: El archivo debe venir abierto para lectura.
void LeerArbolExpedientes(FILE* f, Arbol &root) {
    Expediente e;
    root = NULL;
    LeerExpediente(f, e);

    while (!feof(f)) {
        AgregarExpediente(root, e);
        LeerExpediente(f, e);
    }
}

//Procedimiento: Guarda el expediente en un archivo.
//Precondicion: El archivo debe venir abierto para escritura.
void GuardarArbolExpedientes(FILE* f, Arbol root) {
    if (root != NULL) {
        GuardarArbolExpedientes(f, root->izq);
        GuardarArbolExpedientes(f, root->der);
        GuardarExpediente(f, root->info);
    }
}

//Funcion: Cuenta los expedientes.
int ContarExpedientes(Arbol root) {
    if (root != NULL) {
        return 1 + ContarExpedientes(root->izq) + ContarExpedientes(root->der);
    } else {
        return 0;
    }
}

//Funcion: Cuenta la cantidad de expedientes con el apellido ingresado.
int ContarExpedientes(Arbol root, string apellido) {
    if (root != NULL) {
        int total = 0;
        total += ContarExpedientes(root->izq, apellido);
        total += ContarExpedientes(root->der, apellido);

        Escribano e;
        ObtenerEscribano(root->info, e);
        string aux;
        ObtenerApellidoEscribano(e, aux);
        if (streq(apellido, aux)) {
            total += 1;
        }

        return total;
    } else {
        return 0;
    }
}

//Procedimiento: Devuelve el expediente con mas revisiones. 
void ExpedienteConMasRevisiones(Arbol root, Lista revisiones, int &rev, int &eid) {
    if (root != NULL) {
        int id = ObtenerIdExpediente(root->info);
        int c = ContarRevisiones(revisiones, id);

        if (rev < c) {
            rev = c;
            eid = id;
        } else if (rev == c && eid > id) {
            eid = id;
        }

        ExpedienteConMasRevisiones(root->izq, revisiones, rev, eid);
        ExpedienteConMasRevisiones(root->der, revisiones, rev, eid);
    }
}
