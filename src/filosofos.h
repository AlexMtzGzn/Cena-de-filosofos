#ifndef FILOSOFOS_H
#define FILOSOFOS_H

#define numeroFilosofos 5

int tenedores[numeroFilosofos];

struct Filosofo{
    int id_filosofo;
    int tenedor_izq;
    int tenedor_der;
    char status;
};

void * filosofo(void *args);
void ejecutar ();

#endif /*filosofos.c*/