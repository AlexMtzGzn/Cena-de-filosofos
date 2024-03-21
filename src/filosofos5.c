#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <filosofos.h>

void *filosofo(void * arg){
    struct Filosofo * filosofo = (void *) arg;

    for(int i = 0; i < NUMEROiTERACIONES; i++){
        printf("Filósofo %i pensando...\n", filosofo->id_filosofo);
        sleep(1);

    pthread_mutex_lock(&mutex);

        while (!tenedores[filosofo->tenedor_izq] || !tenedores[filosofo->tenedor_der]) {
            printf("Filósofo %d esperando tenedores...\n", filosofo->id_filosofo);
            pthread_cond_wait(&condicion_tenedor[filosofo->id_filosofo], &mutex);
        }

        tenedores[filosofo->tenedor_izq] = 0;
        tenedores[filosofo->tenedor_der] = 0;

        printf("Filósofo %d tomó los tenedores (%d y %d)\n", filosofo->id_filosofo, filosofo->tenedor_izq, filosofo->tenedor_der);

        pthread_mutex_unlock(&mutex);

    }
}

int ejecutar(){

    struct Filosofo filosofos[NUMEROFILOSOFO];

    for(int i  = 0; i < NUMEROFILOSOFO; i++){
        pthread_cond_init(&condicion_tenedor[i], NULL);
        tenedores[i] = 1;
    }

    for (int i = 0; i < NUMEROFILOSOFO; i++) {
        filosofos[i].id_filosofo = i+1;
        filosofos[i].tenedor_izq = filosofos[i].id_filosofo;
        filosofos[i].tenedor_izq = ((filosofos[i].id_filosofo)+1) % NUMEROFILOSOFO;

        if(pthread_create(&hilos_Filosofos[i],NULL,filosofo,(void *)&filosofos[i]) != 0){
            printf("Error al crear el hilo %i",i);
            return -1;
        }
    }
     
    for (int i = 0; i < NUMEROFILOSOFO; i++) {
        pthread_join(hilos_Filosofos[i], NULL);
    }

    return 0;
}