#include <stdio.h>
#include "filosofos.h"

int main(void)
{

    if (ejecutar() == -1)
    {
        printf("\nError al ejecutar el código");
        return -1;
    }

    return 0;
}