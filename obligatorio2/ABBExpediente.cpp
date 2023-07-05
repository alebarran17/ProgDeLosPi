#include "ABBExpediente.h"

// Agregar un expediente al arbol.
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

// Mostrar en pantalla todos los expedientes.
void MostrarArbol(Arbol root) {
    if (root != NULL) {
        MostrarArbol(root->izq);
        MostrarExpediente(root->info);
        MostrarArbol(root->der);
    }
}

// Obtener el expediente con el codigo de identificacion menor.
Expediente PrimerExpediente(Arbol root) {
    return root->izq == NULL ? root->info : PrimerExpediente(root->izq);
}

// Obtener el expediente con el codigo de identificacion mayor.
Expediente UltimoExpediente(Arbol root) {
    return root->der == NULL ? root->info : UltimoExpediente(root->der);
}

// Obtener un expediente con el codigo de identificacion ingresado,
// o NULL si no existe en el arbol.
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

// Eliminar el expediente del arbol con el codigo de
// identificacion ingresado.
// Precondicion: El expediente debe existir.
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

// Devolver el nodo del arbol cuyo numero de identificacion
// es el menor de todos.
Arbol BuscarExpedienteMinimo(Arbol root) {
    return root->der != NULL ? root->der : root;
}

// Cargar la información de todos los expedientes desde un archivo.
// Precondicion: El archivo debe venir abierto para lectura.
void LeerArbolExpedientes(FILE* f, Arbol &root) {
    Expediente e;
    root = NULL;
    LeerExpediente(f, e);

    while (!feof(f)) {
        AgregarExpediente(root, e);
        LeerExpediente(f, e);
    }
}

// Guardar la información de todos los expedientes en un archivo.
// Precondicion: El archivo debe venir abierto para escritura.
void GuardarArbolExpedientes(FILE* f, Arbol root) {
    if (root != NULL) {
        GuardarArbolExpedientes(f, root->izq);
        GuardarArbolExpedientes(f, root->der);
        GuardarExpediente(f, root->info);
    }
}

// Devolver la cantidad total de expedientes en el arbol.
int ContarExpedientes(Arbol root) {
    if (root != NULL) {
        return 1 + ContarExpedientes(root->izq) + ContarExpedientes(root->der);
    } else {
        return 0;
    }
}

// Devolver la cantidad de expedientes cuyo apellido del escribano
// coincide con el ingresado.
int ContarExpedientes(Arbol root, string apellido) {
    if (root != NULL) {
        int total = 0;
        total += ContarExpedientes(root->izq, apellido);
        total += ContarExpedientes(root->der, apellido);

        Escribano e;
        ObtenerEscribano(root->info, e);
        string aux;
        ObtenerApellidoEscribano(e, aux);
        if (streq(apellido, aux, TRUE)) {
            total += 1;
        }

        return total;
    } else {
        return 0;
    }
}

// Devolver el codigo de identificacion y la cantidad de revisiones
// del expediente con mas revisiones.
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
