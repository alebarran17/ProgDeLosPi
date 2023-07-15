#include "Carrera.h"

/// Operaciones primitivas.

/// Crea una secuencia vacía.
void Crear(Carrera &c){
    c.tope = 0;
}

/// Devuelve la cantidad de elementos de la secuencia.
int Largo(Carrera c){
    return c.tope;
}

/// Devuelve el elemento que ocupa la posición K de la secuencia.
/// Precondición: El largo de la secuencia es mayor o igual a K.
Asignatura KEsimo(Carrera c, int k){
    return c.arr[k];
}

/// Operaciones adicionales.

///Agrega un elemento al final del secuencia.
void InsBack(Carrera &c, Asignatura &a){
    a.idAsignatura = c.tope;
    c.arr[c.tope] = a;
    c.tope++;
}

///Lista por pantalla la secuencia.
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
