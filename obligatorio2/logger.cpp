#include <stdio.h>

#include "logger.h"

void info(char* msg, ...) {
    printf("[I]: ");

    va_list arg;
    va_start (arg, msg);
    vfprintf (stdout, msg, arg);
    va_end (arg);

    printf("\r\n");
}

void error(char* msg, ...) {
    printf("[E]: ");

    va_list arg;
    va_start (arg, msg);
    vfprintf (stdout, msg, arg);
    va_end (arg);

    printf("\r\n");
}
