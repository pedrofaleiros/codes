/* 
Definir i  como o terceiro elemento a partir do final da pilha.
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

    i = define_i(p);

    (i == -1) ? printf("\n tamanho da pilha insuficiente") : printf("\n terceiro elemento: %d", i);

    printf("\n");
    return 0;
}

int define_i(pilha * p)
{
    int i;

    pilha * aux;
    aux = aloca_pilha();

    while(p->topo && stackpop(p) != -1){
        push(aux, pop(p));
    }

    i = pop(aux);
    push(p, i);

    i = pop(aux);
    push(p, i);
    
    i = pop(aux);
    push(p, i);

    while(aux->topo){
        if(stackpop(aux) != -1){
            push(p, pop(aux));
        }
    }

    return i;
}