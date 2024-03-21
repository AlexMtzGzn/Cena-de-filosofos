#ifndef FILOSOFOS_H
#define FILOSOFOS_H
#include <pthread.h>

#define NUMEROFILOSOFO 5
#define NUMEROiTERACIONES 30

pthread_t hilos_Filosofos [NUMEROFILOSOFO];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condicion_tenedor[NUMEROFILOSOFO];
int tenedores[NUMEROFILOSOFO];

struct Filosofo{
    int id_filosofo;
    int tenedor_izq;
    int tenedor_der;
    char status;
};

void * filosofo(void *args);
int ejecutar();

#endif /*filosofos.c*/