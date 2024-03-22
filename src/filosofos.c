#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "filosofos.h"

#define NUMEROFILOSOFO 5
#define NUMEROITERACIONES 5

pthread_t hilos_Filosofos[NUMEROFILOSOFO];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condicion_palillos[NUMEROFILOSOFO];
int palillos[NUMEROFILOSOFO];

void *filosofo(void * arg){
    struct Filosofo * filosofo = (void *) arg;

    for(int i = 0; i < NUMEROITERACIONES; i++){
        printf("Filósofo %i pensando...\n", (filosofo->id_filosofo+1));
        sleep(2);

        pthread_mutex_lock(&mutex);
        
        while (!palillos[filosofo->palillo_izq] || !palillos[filosofo->palillo_der]) {
            printf("Filósofo %i esperando palillos...\n", (filosofo->id_filosofo+1));
            pthread_cond_wait(&condicion_palillos[filosofo->id_filosofo], &mutex);
        }

        palillos[filosofo->palillo_izq] = 0;
        palillos[filosofo->palillo_der] = 0;

        printf("Filósofo %i tomó los palillos (%i y %i)\n", (filosofo->id_filosofo+1), (filosofo->palillo_izq+1), (filosofo->pallilo_der+1));

        pthread_mutex_unlock(&mutex);

        printf("Filósofo %i comiendo...\n", (filosofo->id_filosofo+1));
        sleep(3);

        pthread_mutex_lock(&mutex);

        palillos[filosofo->palillo_izq] = 1;
        palillos[filosofo->palillo_der] = 1;
        printf("Filósofo %i soltó los palillos (%i y %i)\n", (filosofo->id_filosofo+1), (filosofo->palillo_izq+1), (filosofo->pallilo_der+1));

        pthread_cond_signal(&condicion_palillos[(filosofo->id_filosofo + 1) % NUMEROFILOSOFO]);
        pthread_cond_signal(&condicion_palillos[(filosofo->id_filosofo + NUMEROFILOSOFO - 1) % NUMEROFILOSOFO]);

        pthread_mutex_unlock(&mutex);

    }
}

int ejecutar(){

    struct Filosofo filosofos[NUMEROFILOSOFO];

    for(int i  = 0; i < NUMEROFILOSOFO; i++){
        pthread_cond_init(&condicion_palillos[i], NULL);
        palillos[i] = 1;
    }

    for (int i = 0; i < NUMEROFILOSOFO; i++) {
        filosofos[i].id_filosofo = i;
        filosofos[i].palillo_izq = filosofos[i].id_filosofo;
        filosofos[i].palillo_der = ((filosofos[i].id_filosofo)+1) % NUMEROFILOSOFO;
        

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