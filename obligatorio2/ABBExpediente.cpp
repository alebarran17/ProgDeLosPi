#include "ABBExpediente.h"

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

void MostrarArbol(Arbol root) {
    if (root != NULL) {
        MostrarArbol(root->izq);
        MostrarExpediente(root->info);
        MostrarArbol(root->der);
    }
}

Expediente PrimerExpediente(Arbol root) {
    return root->izq == NULL ? root->info : PrimerExpediente(root->izq);
}

Expediente UltimoExpediente(Arbol root) {
    return root->der == NULL ? root->info : PrimerExpediente(root->der);
}

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

Arbol BuscarExpedienteMinimo(Arbol root) {
    return root->der != NULL ? root->der : root;
}

void LeerArbolExpedientes(FILE* f, Arbol &root) {
    Expediente e;
    root = NULL;
    LeerExpediente(f, e);

    while (!feof(f)) {
        AgregarExpediente(root, e);
        LeerExpediente(f, e);
    }
}

void GuardarArbolExpedientes(FILE* f, Arbol root) {
    if (root != NULL) {
        GuardarArbolExpedientes(f, root->izq);
        GuardarArbolExpedientes(f, root->der);
        GuardarExpediente(f, root->info);
    }
}

int ContarExpedientes(Arbol root) {
    if (root != NULL) {
        return 1 + ContarExpedientes(root->izq) + ContarExpedientes(root->der);
    } else {
        return 0;
    }
}

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

void ExpedienteConMasRevisiones(Arbol root, Lista revisiones, int& rev, int &eid) {
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
