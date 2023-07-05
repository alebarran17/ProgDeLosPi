#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// Motrar el menu principal
int IniciarMenu();

// Motrar el menu de expedientes
int MostrarMenuExpedientes();

// Motrar el menu de revisiones
int MostrarMenuRevisiones();

// Devolver la opción seleccionada por teclado desde 1 hasta max.
int CargarOpcion(int max);

#endif // MENU_H_INCLUDED
