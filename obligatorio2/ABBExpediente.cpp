#include "ABBExpediente.h"

void AgregarExpediente(ABBExpediente*& root, Expediente e) {
    if (root == NULL) {
        root = new ABBExpediente;
        root->izq = NULL;
        root->der = NULL;
        root->info = e;
    } else {
        ABBExpediente* sig = SiguienteNodo(root, e.id);
        AgregarExpediente(sig, e);
    }
}

void MostrarArbol(ABBExpediente* root, Expediente e) {
    if (root != NULL) {
        MostrarArbol(root->izq, e);
        MostrarExpediente(e);
        MostrarArbol(root->der, e);
    }
}

Expediente* BuscarExpediente(ABBExpediente* root, int id) {
    if (root == NULL) {
        return NULL;
    } else if (root->info.id == id) {
        return &root->info;
    } else {
        ABBExpediente* sig = SiguienteNodo(root, id);
        return BuscarExpediente(sig, id);
    }
}

ABBExpediente* SiguienteNodo(ABBExpediente* root, int id) {
    return root->info.id > id ? root->izq : root->der;
}
