#include <stdio.h>

#define False 0
#define True 1
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

    if(count == 1)
        return 1;
    else
        return 0;
}