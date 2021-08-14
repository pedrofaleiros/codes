#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct pilha{
    int tamanho;
    struct elemento * topo;
}pilha;

pilha * aloca_pilha();
elemento * aloca_elemento();
int pop(pilha * p);
void push(pilha * p, int num);
int stackpop(pilha * p);
int empty(pilha * p);

int main()
{
    pilha * p;

    p = aloca_pilha();

    push(p, 2);
    push(p, 4);
    push(p, 6);
    push(p, 8);

    printf("\n %d", pop(p));
    printf("\n %d", pop(p));
    printf("\n %d", pop(p));
    printf("\n %d", pop(p));
    printf("\n %d", pop(p));

    printf("\n");
    return 0;
}

int stackpop(pilha * p)
{
    if(!empty(p))
        return p->topo->valor;
    return -1;
}

int pop(pilha * p)
{
    elemento * aux;
    int retorno = -1;

    if(!empty(p)){
        aux = p->topo;
        p->topo = aux->prox;
        p->tamanho -= 1;
        retorno = aux->valor;
        free(aux);
    }

    return retorno;
}

void push(pilha * p, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho += 1;
}

int empty(pilha * p)
{
    if(p->topo == NULL)
        return 1;
    return 0;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = calloc(1, sizeof(elemento));
    return novo;
}

pilha * aloca_pilha()
{
    pilha * nova;
    nova = calloc(1, sizeof(pilha));
    return nova;
}