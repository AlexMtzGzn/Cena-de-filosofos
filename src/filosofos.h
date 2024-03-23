#ifndef FILOSOFOS_H
#define FILOSOFOS_H

struct Filosofo{
    int id_filosofo;
    int palillo_izq;
    int palillo_der;
};

void * filosofo(void *args);
int ejecutar();

#endif /*filosofos.c*/