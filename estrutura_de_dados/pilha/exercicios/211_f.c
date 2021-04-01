/* 
Definir i  como o último elemento da pilha, 
deixando a pilha inalterada.
*/
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
    push(p, 8);

    i = define_i(p);

    (i == -1) ? printf("\n pilha vazia") : printf("\n ultimo elemento: %d", i);

    printf("\n");
    return 0;
}

int define_i(pilha * p)
{
    int num;
    pilha * aux;

    aux = aloca_pilha();

    while(p->topo){
        num = pop(p);
        push(aux, num);
    }

    while(aux->topo)
        push(p, pop(aux));

    return num;
}