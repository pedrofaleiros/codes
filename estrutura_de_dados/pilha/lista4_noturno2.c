/* 
Construir uma função que troca de lugar 
o elemento que está no topo da pilha 
com o que está na base da pilha. 
Usar apenas uma pilha como auxiliar. 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    struct elemento * topo;
}pilha;

typedef struct elemento{
    int valor;
    struct elemento * abaixo;
}elemento;

int pop(pilha * p);
int stackpop(pilha * p);
void push(pilha * p, int num);
int empty(pilha * p);
pilha * aloca_pilha();
elemento * aloca_elemento();
void mostra_pilha(pilha * p);
void troca_topo_base(pilha * p);

int main()
{
    pilha * p;

    p = aloca_pilha();

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);

    mostra_pilha(p);

    troca_topo_base(p);

    printf("\ntrocado:");
    mostra_pilha(p);

    printf("\n");
    return 0;
}

void troca_topo_base(pilha * p)
{
    int topo, base, num;

    if(empty(p)){
        printf("\n pilha vazia");
    }else{
        pilha * aux;
        aux = aloca_pilha();

        topo = pop(p);

        if(p->topo == NULL){
            push(p, topo);
            return;
        }

        while(p->topo->abaixo != NULL){
            push(aux, pop(p));
        }

        base = pop(p);

        push(p, topo);

        while(aux->topo){
            push(p, pop(aux));
        }
        push(p, base);
    }
}

void mostra_pilha(pilha * p)
{
    if(empty(p))
        printf("\n pilha vazia");
    else{
        elemento * aux;
        aux = p->topo;
        while(aux){
            printf("\n %d", aux->valor);
            aux = aux->abaixo;
        }
    }
}

int pop(pilha * p)
{
    if(empty(p))
        return -1;
    else{
        int num = p->topo->valor;
        elemento * aux;
        aux = p->topo;
        p->topo = p->topo->abaixo;
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

void push(pilha * p, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(empty(p)){
        p->topo = novo;
    }else{
        novo->abaixo = p->topo;
        p->topo = novo;
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