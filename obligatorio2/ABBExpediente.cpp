#include "ABBExpediente.h"

void AgregarExpediente(Arbol& root, Expediente e) {
    if (root == NULL) {
        root = new ABBExpediente;
        root->izq = NULL;
        root->der = NULL;
        root->info = e;
    } else if (root->info.id > e.id) {
        AgregarExpediente(root->izq, e);
    } else {
        AgregarExpediente(root->der, e);
    }
}

void MostrarArbol(Arbol root, Expediente e) {
    if (root != NULL) {
        MostrarArbol(root->izq, e);
        MostrarExpediente(e);
        MostrarArbol(root->der, e);
    }
}

Expediente* BuscarExpediente(Arbol root, int id) {
    if (root == NULL) {
        return NULL;
    } else if (root->info.id == id) {
        return &root->info;
    } else if (root->info.id > id) {
        return BuscarExpediente(root->izq, id);
    } else {
        return BuscarExpediente(root->der, id);
    }
}

void ListarExpedientes(Arbol root) {
    if (root != NULL) {
        ListarExpedientes(root->izq);
        MostrarExpediente(root->info);
        ListarExpedientes(root->der);
    }
}

void BorrarExpediente(Arbol& root, int id) {
    if (root->info.id == id) {
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
            BorrarExpediente(root->der, root->info.id);
        }
    } else if (root->info.id > id) {
        BorrarExpediente(root->izq, id);
    } else {
        BorrarExpediente(root->der, id);
    }
}

Arbol BuscarExpedienteMinimo(Arbol root) {
    return root->der != NULL ? root->der : root;
}
