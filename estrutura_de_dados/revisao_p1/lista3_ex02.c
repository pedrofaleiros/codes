/* 
2) Construa uma pilha utilizando uma lista ligada.
Obs. Implemente as operações Push, pop, stackpop e empty. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct pilha{
    struct elemento * topo;
}pilha;

elemento * aloca_elemento();
pilha * aloca_pilha();
int empty(pilha * p);
int pop(pilha * p);
int stackpop(pilha * p);
void push(pilha * p, int num);

int main()
{
    pilha * p;

    p = aloca_pilha();

    push(p, 1);
    printf("\n topo = %d", stackpop(p));
    push(p, 2);
    printf("\n topo = %d", stackpop(p));
    printf("\n removido = %d", pop(p));
    push(p, 3);
    printf("\n removido = %d", pop(p));
    push(p, 4);
    printf("\n topo = %d", stackpop(p));
    pop(p);
    pop(p);
    pop(p);
    printf("\n topo = %d", stackpop(p));

    printf("\n");
    return 0;
}

void push(pilha * p, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(empty(p))
        p->topo = novo;
    else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}

int stackpop(pilha * p)
{
    if(empty(p))
        return -1;
    else
        return p->topo->valor;
}

int pop(pilha * p)
{
    if(empty(p))
        return -1;
    else{
        int num;
        elemento * aux;

        aux = p->topo;
        num = p->topo->valor;

        p->topo = p->topo->prox;

        free(aux);
        return num;
    }
}

int empty(pilha * p)
{
    if(p->topo == NULL)
        return 1;
    else
        return 0;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;
}

pilha * aloca_pilha()
{
    pilha * nova;
    nova = (pilha*)calloc(1, sizeof(pilha));
    return nova;
}   