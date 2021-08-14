#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct fila{
    int tamanho;
    struct elemento * inicio;
}fila;  

fila * aloca_fila();
elemento * aloca_elemento();
void insert(fila * f, int num);
int remover(fila * f);
int size(fila * f);
int empty(fila * f);
int front(fila * f);

int main()
{
    fila * f;
    f = aloca_fila();

    insert(f, 1);
    insert(f, 3);
    insert(f, 5);
    insert(f, 7);

    printf("\n %d", size(f));


    printf("\n");
    return 0;
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

void insert(fila * f, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(empty(f))
        f->inicio = novo;
    else{
        elemento * aux;
        aux = f->inicio;

        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo;
    }
    f->tamanho += 1;
}

int remover(fila * f)
{
    int retorno = -1;
    elemento * aux;

    if(!empty(f)){
        aux = f->inicio;
        retorno = aux->valor;
        f->inicio = aux->prox;
        free(aux);
    }

    f->tamanho -= 1;
    return retorno;
}

int size(fila * f)
{
    return f->tamanho;
}

int empty(fila * f)
{
    if(f->inicio == NULL)
        return 1;
    return 0;
}

int front(fila * f)
{
    if(!empty(f))
        return f->inicio->valor;
    return -1;
}