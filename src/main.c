#include <stdio.h>
#include "filosofos.h"

int main (void){

    if(ejecutar() == -1){
        printf("./Error al ejecutarse el codigo");
        return -1;
    }
        
    return 0;
}