#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int lint;

typedef struct elemento{
    lint valor;
    struct elemento * ant;
    struct elemento * prox;
}elemento;

typedef struct lista{
    struct elemento * inicio;
    struct elemento * final;
}lista;

elemento * aloca_elemento();
lista * aloca_lista();
void inclui_no_final(lista * l, lint num);
void mostra_lista(lista * l);
void inclui_ordenado(lista * l, lint num);


int main()
{
    srand(time(NULL));

    lista * des, * ord;
    des = aloca_lista();
    ord = aloca_lista();

    lint limite = 10, i;

    for(i = limite; i > 0; i--){
        inclui_ordenado(ord, rand()%limite);
        inclui_no_final(des, rand()%limite);
    }

    mostra_lista(des);
    printf("\n ----");
    mostra_lista(ord);

    printf("\n");
    return 0;
}



void mostra_lista(lista * l)
{
    if(l->inicio != NULL){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n %lld", aux->valor);
            aux = aux->prox;
        }
    }
}

void inclui_ordenado(lista * l, lint num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio != NULL){
        elemento * aux;
        aux = l->inicio;

        while(aux->prox != NULL && aux->valor < num)
            aux = aux->prox;

        if(aux->valor >= num){
            novo->prox = aux;
            if(aux == l->inicio){
                l->inicio = novo;
            }else{
                novo->ant = aux->ant;
                aux->ant->prox = novo;
            }
            aux->ant = novo;
        }else{
            aux->prox = novo;
            novo->ant = aux;
            l->final = novo;
        }

    }else{
        l->inicio = novo;
        l->final = novo;
    }
}

void inclui_no_final(lista * l, lint num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio != NULL){
        novo->ant = l->final;
        l->final->prox = novo;
    }else
        l->inicio = novo;
    l->final = novo;
}

lista * aloca_lista()
{
    lista * nova;
    nova = calloc(1, sizeof(lista));
    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = calloc(1, sizeof(elemento));
    return novo;
}
