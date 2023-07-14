#include <stdio.h>
#include "menu.h"
#include "Estudiantes.h"
#include "Previaturas.h"

void ProcesarMenuAsignaturas(Carrera &carrera) {
    int opt = MenuAsignaturas();
    while (opt != 3) {
        switch(opt) {
            case 1:
                {
                     if(Largo(carrera) == CANT_ASIGNATURAS){
                         printf("[E]: Se llego al maximo de asignaturas.\r\n");
                     }else{
                        Asignatura a;
                        CargarAsignatura(a);
                        if(ExisteAsignatura(carrera, a))
                            printf("[E]: El nombre de la asignatura ya existe.\r\n");
                        else{
                            InsBack(carrera, a);
                            int idAsignatura = ObtenerIdAsignatura(a);
                            printf("[I]: Asignatura agregada correctamente con ID: %d.\r\n", idAsignatura);
                            }
                       }
                }
                break;
            case 2:
                {
                    Listar(carrera);
                }
                break;
        }
        printf("\r\n");
        opt = MenuAsignaturas();
    }
}

int ProcesarMenuPrevias(Carrera& carrera, Previaturas& previas) {
    int opt = MenuPrevias();
    while (opt != 3) {
        switch(opt) {
            case 1:
                {
                    printf(">> Ingrese la asignatura para listar:\r\n");
                    int v = CargarOpcion(N + 1);
                    if (v > Largo(carrera)) {
                        printf("[E]: La asignatura %d no existe.\r\n", v);
                        printf("\r\n");
                    } else {
                        ListarPrevias(previas, carrera, v - 1);
                    }
                }
                break;
            case 2:
                {
                    printf(">> Ingrese la asignatura padre:\r\n");
                    int v = CargarOpcion(N + 1);
                    if (v > Largo(carrera)) {
                        printf("[E]: La asignatura %d no existe.\r\n", v);
                        printf("\r\n");
                    } else {
                        printf(">> Ingrese la asignatura hija:\r\n");
                        int u = CargarOpcion(N + 1);
                        if (u > Largo(carrera)) {
                            printf("[E]: La asignatura %d no existe.\r\n", u);
                            printf("\r\n");
                        } else {
                            InsertarArista(previas, v - 1, u - 1);
                        }
                    }
                }
                break;
        }
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
                    if (!Member(estudiantes, dni)) {
                        printf("[E]: El alumno con cédula %d no está registrado.\r\n", dni);
                    } else {
                        printf("\r\n");
                        Alumno a = Find(estudiantes, dni);
                        MostrarAlumno(a);
                    }
                }
                break;
            case 2:
                {
                    Alumno a;
                    CargarAlumno(a);

                    long dni = ObtenerCedulaAlumno(a);
                    if (Member(estudiantes, dni)) {
                        printf("[E]: El alumno con cédula %ld ya está registrado.\r\n", dni);
                    } else {
                        Insert(estudiantes, a);

                        long dni = ObtenerCedulaAlumno(a);
                        printf("[I]: Alumno registrado correctamente con la cédula %d.\r\n", dni);
                    }
                }
                break;
            case 3:
                {
                    Curso c;
                    CargarCurso(c);

                    Fecha finalizadoEn = ObtenerFinalizacionCurso(c);

                    int idAsignatura = ObtenerAsignaturaIDCurso(c);
                    if (idAsignatura - 1 > Largo(carrera)) {
                        printf("[E]: La asignatura %d no existe.\r\n", idAsignatura);
                        printf("\r\n");
                    } else if (!ValidarFormato(finalizadoEn)) {
                        printf("[E]: La fecha ingresada no es válida.\r\n");
                        printf("\r\n");
                    } else {
                        long dni;
                        printf(">> Ingrese la cédula del estudiante:\r\n");
                        printf(">> ");
                        scanf("%ld", &dni);

                        Alumno a = Find(estudiantes, dni);
                        if (!Member(estudiantes, dni)) {
                            printf("[E]: El alumno con cédula %d no está registrado.\r\n", dni);
                        } else {
                            bool fechaValida = true;
                            Escolaridad escolaridad = ObtenerEscolaridadAlumno(a);
                            int aux = Largo(escolaridad);
                            if (aux > 0) {
                                Curso ultimo = Ultimo(escolaridad);
                                if (FechaPosterior(ObtenerFinalizacionCurso(ultimo), finalizadoEn)) {
                                    printf("[E]: La fecha ingresada debe ser posterior a ");
                                    MostrarFecha(ObtenerFinalizacionCurso(ultimo));
                                    printf("\r\n\r\n");

                                    fechaValida = false;
                                }
                            }

                            if (fechaValida) {
                                if (AproboAsignatura(escolaridad, idAsignatura)) {
                                    printf("[E]: La asignatura ingresada ya fue aprobada por el alumno.\r\n");
                                } else if (!AproboPreviasInmediatas(previas, escolaridad, idAsignatura)) {
                                    printf("[E]: El estudiante no aprobó todas las previas del curso.\r\n");
                                } else {
                                    InsBack(escolaridad, c);
                                    SetEscolaridadAlumno(a, escolaridad);
                                    Modify(estudiantes, a);
                                }
                            }
                        }
                    }
                }
                break;
            case 4:
                {
                    long dni;
                    printf(">> Ingrese la cédula del estudiante:\r\n");
                    printf(">> ");
                    scanf("%ld", &dni);

                    Alumno a = Find(estudiantes, dni);
                    if (!Member(estudiantes, dni)) {
                        printf("[E]: El alumno con cédula %d no está registrado.\r\n", dni);
                    } else {
                        Escolaridad escolaridad = ObtenerEscolaridadAlumno(a);
                        ListarOrdenada(escolaridad);
                    }
                }
                break;
        }
        printf("\r\n");
        opt = MenuAlumno();
    }
}

int main()
{
    Carrera carrera;
    Crear(carrera);

    Previaturas previas;
    Crear(previas);

    Estudiantes estudiantes;
    Make(estudiantes);

    Asignatura m1;
    m1.nombre = "M1";
    m1.horas = 20;

    Asignatura m2;
    m2.nombre = "M2";
    m2.horas = 23;

    InsBack(carrera, m1);
    InsBack(carrera, m2);

    Alumno nico;
    nico.cedula = 52526535;
    nico.nombre = "Nicolas";
    nico.apellido = "Villar";
    nico.telefono = "098119968";
    nico.escolaridad = Crear();

    Curso c;
    CargarCurso(c);
    Escolaridad e;
    e = Crear();
    InsBack(e, c);
    SetEscolaridadAlumno(nico, e);
    Insert(estudiantes, nico);

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
