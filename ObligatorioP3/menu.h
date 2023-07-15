#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/// Muestra en pantalla el men� principal y sus opciones.
int MenuPrincipal();

/// Muestra en pantalla el men� de asignaturas y sus opciones.
int MenuAsignaturas();

/// Muestra en pantalla el men� de previas y sus opciones.
int MenuPrevias();

/// Muestra en pantalla el men� de alumnos y sus opciones.
int MenuAlumno();

/// Carga por teclado un n�mero entre min y max.
int CargarOpcion(int min, int max);

#endif // MENU_H_INCLUDED
