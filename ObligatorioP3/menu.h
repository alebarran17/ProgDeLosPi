#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/// Muestra en pantalla el menú principal y sus opciones.
int MenuPrincipal();

/// Muestra en pantalla el menú de asignaturas y sus opciones.
int MenuAsignaturas();

/// Muestra en pantalla el menú de previas y sus opciones.
int MenuPrevias();

/// Muestra en pantalla el menú de alumnos y sus opciones.
int MenuAlumno();

/// Carga por teclado un número entre min y max.
int CargarOpcion(int min, int max);

#endif // MENU_H_INCLUDED
