#include "Carrera.h"

void Crear(Carrera &c){
    c.tope = 0;
}

int Largo(Carrera c){
    return c.tope;
}

Asignatura KEsimo(Carrera c, int k){
    return c.arr[k];
}

void InsBack(Carrera &c, Asignatura &a){
    a.idAsignatura = c.tope;
    c.arr[c.tope] = a;
    c.tope++;
}

void Listar(Carrera c){
    int i;
    for(i = 0; i<c.tope; i++){
        MostrarAsignatura(c.arr[i]);
    }
}

bool ExisteAsignatura(Carrera c, Asignatura a){
    bool existe = false;
    int i = 0;
    String aux1, aux2;
    while (!existe && i<c.tope){
        ObtenerNombre(c.arr[i], aux1);
        ObtenerNombre(a, aux2);
        if(streq(aux1, aux2, true))
            existe = true;
        i++;
    }
    return existe;
}
