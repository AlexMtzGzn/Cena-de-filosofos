#ifndef FILOSOFOS_H
#define FILOSOFOS_H
#include <pthread.h>

struct Filosofo{
    int id_filosofo;
    int tenedor_izq;
    int tenedor_der;
    char status;
};

void * filosofo(void *args);
int ejecutar();

#endif /*filosofos.c*/