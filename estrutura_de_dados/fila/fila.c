/*
Utilizando as seguintes estruturas, construa um programa que implemente as seguintes funções:
insert ou enqueue - insere itens numa fila (ao final).
remove ou dequeue - retira itens de uma fila (primeiro item).
empty - veriica se a fila está vazia.
size - retorna o tamanho da fila.
front - retorna o próximo item da fila sem retirar o mesmo da fila
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int tamanho;
    struct elemento * inicio;
    struct elemento * final;
}fila;

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

void insert(fila * f, int num);
int remover(fila * f);
int empty(fila * f);
int size(fila * f);
int front(fila * f);

fila * aloca_fila();
elemento * aloca_elemento();

int main()
{
    fila * f;
    f = aloca_fila();

    insert(f, 1);
    insert(f, 2);
    insert(f, 3);
    insert(f, 4);
    printf("\n primeiro: %d", remover(f));
    printf("\n primeiro: %d", remover(f));
    printf("\n primeiro: %d", remover(f));
    printf("\n primeiro: %d", remover(f));


    printf("\n");
    return 0;
}

void insert(fila * f, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(empty(f)){
        f->inicio = novo;
        f->final = novo;
    }else{
        f->final->prox = novo;
        f->final = novo;
    }

    f->tamanho++;
}

int remover(fila * f)
{
    if(empty(f))
        return -1;
    else{
        int num;
        elemento * aux;

        aux = f->inicio;
        num = aux->valor;

        f->inicio = f->inicio->prox;
        f->tamanho -= 1;

        if(f->inicio == NULL)
            f->final = NULL;

        free(aux);
        return num;
    }
}

int empty(fila * f)
{
    if(f->inicio == NULL)
        return 1;
    else
        return 0;
}

int size(fila * f)
{
    return f->tamanho;
}

int front(fila * f)
{
    if(!empty(f)) 
        return f->inicio->valor;
    else
        return -1;
}

fila * aloca_fila()
{
    fila * nova;
    nova = calloc(1, sizeof(fila));
    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = calloc(1, sizeof(elemento));
    return novo;
}