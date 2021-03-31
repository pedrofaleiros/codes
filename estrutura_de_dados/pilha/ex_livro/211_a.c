/* 
Definir i com o segundo elemento a partir do topo da pilha, 
deixandoa pilha sem seus dois elementos superiores.
*/
#include <stdio.h>
#include <stdlib.h>
#include "basico_pilha.h"

int define_i(pilha * p);

int main()
{
    pilha * p;

    p = aloca_pilha();
    int i;

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);
    push(p, 8);
    push(p, 9);

    i = define_i(p);

    (i == -1) ? printf("\n lista pequena") : printf("\n i = %d", i);

    mostra_pilha(p);

    printf("\n");
    return 0;
}

int define_i(pilha * p)
{
    if(! empty(p)){
        pop(p);
        return pop(p);
    }else
        return -1;
}