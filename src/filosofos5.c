#include <stdio.h>
#include <pthread.h>
#include <filosofos.h>

void *filosofo(void * arg){
    struct Filosofo * filosofo = (void *) arg;
}

void ejecutar(){

    struct Filosofo filosofos[numeroFilosofos];

    for(int i  = 0; i < numeroFilosofos; i++){
        pthread_cond_init(&condicion_tenedor[i], NULL);
        tenedores[i] = 1;
    }
}