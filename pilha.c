#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
typedef int bool;

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct Pilha{
    struct elemento * topo;
    void (*push)(struct Pilha *, int);
    int (*pop)(struct Pilha *);
    int (*stackpop)(struct Pilha *);
    bool (*empty)(struct Pilha *);
}Pilha;

void construtora(Pilha * p);
void Push(Pilha * p, int num);
int Pop(Pilha * p);
int Stackpop(Pilha * p);
bool Empty(Pilha * p);
Pilha * aloca_pilha();

int main()
{
    Pilha * pilha;
    pilha = aloca_pilha();
    construtora(pilha);

    pilha->push(pilha, 1);
    pilha->push(pilha, 2);
    pilha->push(pilha, 3);
    pilha->push(pilha, 4);
    pilha->push(pilha, 5);
    printf("\n stackpop: %d", pilha->stackpop(pilha));
    printf("\n pop = %d", pilha->pop(pilha));
    printf("\n stackpop: %d", pilha->stackpop(pilha));

    printf("\n");
    return 0;
}

Pilha * aloca_pilha()
{
    Pilha * nova;
    nova = (Pilha*)calloc(1, sizeof(Pilha));
    return nova;
}

void construtora(Pilha * p)
{
    p->topo = NULL;
    p->push = Push;
    p->pop = Pop;
    p->stackpop = Stackpop;
    p->empty = Empty;
}

bool Empty(Pilha * p)
{
    if(p->topo == NULL)
        return True;
    else
        return False;
}

int Stackpop(Pilha * p)
{
    if(p->topo == NULL)
        return -1;
    else
        return p->topo->valor;
}

int Pop(Pilha * p)
{
    if(p->topo == NULL) 
        return -1;
    else{
        elemento * aux;
        int num;

        num = p->topo->valor;
        aux = p->topo;

        p->topo = p->topo->prox;

        free(aux);
        return num;
    }
}

void Push(Pilha * p, int num)
{   
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    novo->valor = num;

    novo->prox = p->topo;
    p->topo = novo;
}
