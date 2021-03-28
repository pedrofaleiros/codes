#include <stdio.h>

#define False 0
#define True 1
#define and &&
#define or ||
typedef int bool;

int potencia(int num, int pot)
{
    int n = 1;
    for(int i = 0; i < pot; i++){
        n *= num;
    }
    return n;
}

int fatorial(int num)
{
    if(num > 0){
        if(num == 1)
            return 1;
        else
            return num * fatorial(num -1);
    }else   
        return 0;
}

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