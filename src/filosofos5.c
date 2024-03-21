#include <stdio.h>
#include <pthread.h>
#include <filosofos.h>

void *filosofo(void * arg){
    struct Filosofo * filosofo = (void *) arg;
}

int ejecutar(){

    struct Filosofo filosofos[numeroFilosofos];

    for(int i  = 0; i < numeroFilosofos; i++){
        pthread_cond_init(&condicion_tenedor[i], NULL);
        tenedores[i] = 1;
    }

    for (int i = 0; i < numeroFilosofos; i++) {
        filosofos[i].id_filosofo = i+1;
        filosofos[i].tenedor_izq = filosofos[i].id_filosofo;
        filosofos[i].tenedor_izq = ((filosofos[i].id_filosofo)+1) % numeroFilosofos;

        if(pthread_create(&hilos_Filosofos[i],NULL,filosofo,(void *)&filosofos[i]) != 0){
            printf("Error al crear el hilo %i",i);
            return -1;
        }
    }
     
    for (int i = 0; i < numeroFilosofos; i++) {
        pthread_join(hilos_Filosofos[i], NULL);
    }

    return 0;
}