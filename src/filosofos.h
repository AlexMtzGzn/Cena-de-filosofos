#ifndef FILOSOFOS_H
#define FILOSOFOS_H
#include <pthread.h>

#define numeroFilosofos 5
#define numeroInteracciones 30

pthread_t hilos_Filosofos [numeroFilosofos];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condicion_tenedor[numeroFilosofos];
int tenedores[numeroFilosofos];

struct Filosofo{
    int id_filosofo;
    int tenedor_izq;
    int tenedor_der;
    char status;
};

void * filosofo(void *args);
int ejecutar();

#endif /*filosofos.c*/