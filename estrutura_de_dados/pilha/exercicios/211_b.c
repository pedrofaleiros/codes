/* 
Definir i com o segundo elemento a partir do topo da pilha, 
deixandoa pilha  inalterada
*/

#include <stdio.h>
#include <stdlib.h>
#include "basico_pilha.h"

int define_i(pilha * p);

int main()
{
    pilha * p;
    int i;
    p = aloca_pilha();

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);

    i = define_i(p);

    (i == -1) ? printf("\n lista pequena") : printf("\n i = %d", i);

    printf("\n");
    return 0;
}

int define_i(pilha * p)
{
    if(empty(p))
        return -1;
    else{
        int aux, ret;
        aux = pop(p);
        ret = stackpop(p);
        push(p, aux);
        return ret;
    }
}

