#include <stdio.h>
#include "menu.h"
#include "Estudiantes.h"
#include "Previaturas.h"

void ProcesarMenuAsignaturas(Carrera &carrera) {
    int opt = MenuAsignaturas();
    while (opt != 3) {
        switch(opt) {
            case 1:
                if (Largo(carrera) == CANT_ASIGNATURAS) {
                    printf("[E]: Se llegó al máximo de asignaturas.\r\n");
                } else {
                    String nombre;
                    printf("Ingrese un nombre de asignatura: ");
                    scan(nombre);
                    Trim(nombre);
                    if (strlar(nombre) == 0) {
                        printf("\r\n");
                        printf("[E]: El nombre de la asignatura no puede ser vacío.\r\n");
                        break;
                    }

                    int horas;
                    printf("Ingrese la cantidad de horas: ");
                    scanf("%d", &horas);
                    if (horas < 1) {
                        printf("[E]: Las horas de la asignatura debe ser mayor a uno.\r\n");
                        break;
                    }

                    Asignatura a;
                    CargarAsignaturaNombre(a, nombre);
                    CargarAsignaturaHoras(a, horas);
                    LiberarString(nombre);

                    if (ExisteAsignatura(carrera, a)) {
                        printf("\r\n");
                        printf("[E]: El nombre de la asignatura ya existe.\r\n");
                    } else {
                        InsBack(carrera, a);

                        printf("\r\n");
                        printf("[I]: Asignatura agregada correctamente con ID: %d.\r\n", ObtenerIdAsignatura(a));
                    }
                }
                break;
            case 2:
                if (Largo(carrera) == 0) {
                    printf("[E]: Aún no se ha agregado ninguna asignatura.\r\n");
                } else {
                    Listar(carrera);
                }
                break;
        }
        printf("\r\n");
        opt = MenuAsignaturas();
    }
}

void ProcesarMenuPrevias(Carrera& carrera, Previaturas& previas) {
    int opt = MenuPrevias();
    while (opt != 3) {
        switch(opt) {
            case 1:
                {
                    printf(">> Ingrese la asignatura para listar:\r\n");
                    int v = CargarOpcion(0, CANT_ASIGNATURAS);

                    if (v > Largo(carrera) - 1) {
                        printf("[E]: La asignatura %d no existe.\r\n", v);
                    } else if (CantidadPrevias(previas, carrera, v) == 0) {
                        printf("[I]: La asignatura %d no tiene ninguna previa.\r\n", v);
                    } else {
                        ListarPrevias(previas, carrera, v);
                    }
                }
                break;
            case 2:
                {
                    printf(">> Ingrese la asignatura a agregar previas:\r\n");
                    int v = CargarOpcion(0, CANT_ASIGNATURAS);

                    int asignaturasCount = Largo(carrera);
                    if (v > asignaturasCount - 1) {
                        printf("[E]: La asignatura %d no existe.\r\n", v);
                    } else {
                        printf(">> Ingrese la asignatura previa:\r\n");
                        int u = CargarOpcion(0, CANT_ASIGNATURAS);
                        if (u == v) {
                            printf("[E]: Una asignatura no puede ser previa de sí misma.\r\n");
                        } else if (u > asignaturasCount - 1) {
                            printf("[E]: La asignatura %d no existe.\r\n", u);
                        } else {
                            InsertarArista(previas, v, u);
                        }
                    }
                }
                break;
        }
        printf("\r\n");
        opt = MenuPrevias();
    }
}

void ProcesarMenuAlumno(Estudiantes& estudiantes, Carrera carrera, Previaturas previas) {
    int opt = MenuAlumno();
    while (opt != 5) {
        switch(opt) {
            case 1:
                {
                    long dni;
                    printf(">> Ingrese la cédula del estudiante:\r\n");
                    printf(">> ");
                    scanf("%ld", &dni);
                    printf("\r\n");

                    if (!Member(estudiantes, dni)) {
                        printf("[E]: El alumno con cédula %ld no está registrado.\r\n", dni);
                    } else {
                        Alumno a = Find(estudiantes, dni);
                        MostrarAlumno(a);
                    }
                }
                break;
            case 2:
                {
                    Alumno a;
                    CargarAlumno(a);
                    printf("\r\n");

                    long dni = ObtenerCedulaAlumno(a);
                    if (Member(estudiantes, dni)) {
                        printf("[E]: El alumno con cédula %ld ya está registrado.\r\n", dni);
                    } else {
                        Insert(estudiantes, a);

                        long dni = ObtenerCedulaAlumno(a);
                        printf("[I]: Alumno registrado correctamente con la cédula %ld.\r\n", dni);
                    }
                }
                break;
            case 3:
                {
                    Curso c;
                    CargarCurso(c);
                    printf("\r\n");

                    Fecha finalizadoEn = ObtenerFinalizacionCurso(c);

                    int idAsignatura = ObtenerAsignaturaIDCurso(c);
                    if (idAsignatura >= Largo(carrera)) {
                        printf("[E]: La asignatura %d no existe.\r\n", idAsignatura);
                        break;
                    }

                    if (!ValidarFormato(finalizadoEn)) {
                        printf("[E]: La fecha ingresada no es válida.\r\n");
                        break;
                    }

                    long dni;
                    printf(">> Ingrese la cédula del estudiante:\r\n");
                    printf(">> ");
                    scanf("%ld", &dni);

                    if (!Member(estudiantes, dni)) {
                        printf("[E]: El alumno con cédula %ld no está registrado.\r\n", dni);
                        break;
                    }

                    Alumno a = Find(estudiantes, dni);
                    Escolaridad escolaridad = ObtenerEscolaridadAlumno(a);
                    if (Largo(escolaridad) > 0) {
                        Curso ultimo = Ultimo(escolaridad);
                        if (FechaPosterior(ObtenerFinalizacionCurso(ultimo), finalizadoEn)) {
                            printf("[E]: La fecha ingresada debe ser posterior a ");
                            MostrarFecha(ObtenerFinalizacionCurso(ultimo));
                            printf("\r\n");
                            break;
                        }
                    }

                    if (AproboAsignatura(escolaridad, idAsignatura)) {
                        printf("[E]: La asignatura ingresada ya fue aprobada por el alumno.\r\n");
                        break;
                    }

                    if (!AproboPreviasInmediatas(previas, escolaridad, idAsignatura)) {
                        printf("[E]: El estudiante no aprobó todas las previas del curso.\r\n");
                        break;
                    }

                    InsBack(escolaridad, c);
                    SetEscolaridadAlumno(a, escolaridad);
                    Modify(estudiantes, a);
                }
                break;
            case 4:
                {
                    long dni;
                    printf(">> Ingrese la cédula del estudiante:\r\n");
                    printf(">> ");
                    scanf("%ld", &dni);
                    printf("\r\n");

                    if (!Member(estudiantes, dni)) {
                        printf("[E]: El alumno con cédula %ld no está registrado.\r\n", dni);
                        break;
                    }

                    Alumno a = Find(estudiantes, dni);
                    Escolaridad escolaridad = ObtenerEscolaridadAlumno(a);
                    if (Largo(escolaridad) == 0) {
                        printf("[I]: La escolaridad del alumno seleccionado está vacía.\r\n");
                    } else {
                        ListarOrdenada(escolaridad, carrera);
                    }
                }
                break;
        }
        printf("\r\n");
        opt = MenuAlumno();
    }
}

int main() {
    Carrera carrera;
    Crear(carrera);

    Previaturas previas;
    Crear(previas);

    Estudiantes estudiantes;
    Make(estudiantes);

    int opt = MenuPrincipal();
    while (opt != 4) {
        switch(opt) {
            case 1:
                ProcesarMenuAsignaturas(carrera);
                break;
            case 2:
                ProcesarMenuPrevias(carrera, previas);
                break;
            case 3:
                ProcesarMenuAlumno(estudiantes, carrera, previas);
                break;
        }
        opt = MenuPrincipal();
    }
    return 0;
}
