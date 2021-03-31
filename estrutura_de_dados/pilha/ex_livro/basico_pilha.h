#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct pilha{
    struct elemento * topo;
}pilha;

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

int empty(pilha * p)
{
    if(p->topo == NULL)
        return 1;
    else
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

int pop(pilha * p)
{
    if(empty(p))
        return -1;
    else{
        elemento * aux;
        int num;

        aux = p->topo;
        num = aux->valor;
        p->topo = p->topo->prox;
        free(aux);
        return num;
    }
}

int stackpop(pilha * p)
{
    if(empty(p))
        return -1;
    else
        return p->topo->valor;
}

void mostra_pilha(pilha * p)
{
    if(empty(p))
        printf("\n lista vazia");
    else{
        elemento * aux;
        aux = p->topo;
        while(aux){
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }
}