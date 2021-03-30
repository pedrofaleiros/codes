/* 
Dada uma pilha P, construir uma função que inverte a ordem dos elementos dessa pilha, 
utilizando apenas uma estrutura auxiliar.
Definir adequadamente a estrutura auxiliar e prever a possibilidade da pilha
estar vazia.  
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


int main()
{
    pilha * p1;
    int num;

    p1 = aloca_pilha();

    push(p1, 1);
    push(p1, 2);
    push(p1, 3);
    push(p1, 4);
    num = stackpop(p1) == -1 ? 0 : pop(p1);
    printf("\n %d", num);
    pop(p1);
    num = stackpop(p1) == -1 ? 0 : pop(p1);
    printf("\n %d", num);
    pop(p1);
    pop(p1);
    num = stackpop(p1) == -1 ? 0 : pop(p1);
    printf("\n %d", num);
    

    printf("\n");
    return 0;
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