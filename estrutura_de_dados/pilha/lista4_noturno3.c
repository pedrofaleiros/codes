/* 
Dada uma pilha contendo números inteiros quaisquer, 
construir uma função  que  coloca  os  pares  na  base  da  pilha  
e  os  ímpares  no  topo  da pilha. 
Usar duas pilhas como auxiliares.
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
void separa_numeros(pilha * p);


int main()
{
    pilha * p;

    p = aloca_pilha();

    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);
    push(p, 6);
    push(p, 7);

    mostra_pilha(p);

    separa_numeros(p);

    printf("\nseparados:");
    mostra_pilha(p);

    printf("\n");
    return 0;
}

void separa_numeros(pilha * p)
{
    if(empty(p)){
        printf("\nplha vazia");
    }else{
        pilha * par, * impar;
        par = aloca_pilha();
        impar = aloca_pilha();

        while(stackpop(p) != -1){
            if(stackpop(p) % 2 == 0)
                push(par, pop(p));
            else
                push(impar, pop(p));
        }

        while(!empty(par)){
            push(p, pop(par));
        }

        while(!empty(impar)){
            push(p, pop(impar));
        }

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