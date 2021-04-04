#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define True 1
#define False 0

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;    
}

lista * aloca_lista()
{
    lista * nova;
    nova = (lista*)calloc(1, sizeof(lista));
    return nova;    
}

void inclui_no_final(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux->prox)
            aux = aux->prox;
        
        aux->prox = novo;
    }else{
        l->inicio = novo;
    }
    l->qtd++;
}

void inclui_no_inicio(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        novo->prox = l->inicio;
        l->inicio = novo;
    }else{
        l->inicio = novo;
    }
    l->qtd++;
}

void inclui_ordenado(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux, * ant = NULL;
        aux = l->inicio;

        while(aux->prox && aux->valor > num){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->valor > num){
            if(ant){
                ant->prox = novo;
                novo->prox = aux;
            }else{
                l->inicio = novo;
                novo->prox = aux;
            }
        }else{
            aux->prox = novo;
        }

    }else{
        l->inicio = novo;
    }
    l->qtd++;
}

void mostra_lista(lista * l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\n lista vazia");
    }
}
