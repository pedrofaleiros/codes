#include <stdio.h>

#define False 0
#define True 1
#define and &&
#define or ||
typedef int bool;

typedef struct coordenada{
    int x;
    int y;
}coordenada;

int somar(int n1, int n2)
{
    return n1 + n2;
}

int subtrair(int n1, int n2)
{
    return n1 - n2;
}

int verifica_primo(int num)
{
    int count = 0, i = 2;
    
    for(;i <= num; i++)
        if(num % i == 0)
            count++;

    int ret;
    ret = count == 1 ? 1: 0;

    return ret;
}