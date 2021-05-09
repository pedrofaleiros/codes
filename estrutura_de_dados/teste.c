#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

typedef struct elemento{
    llint valor;
    struct elemento * ant;
    struct elemento * prox;
}elemento;

typedef struct lista{
    llint qtd;
    struct elemento * inicio;
    struct elemento * final;
}lista;

elemento * aloca_elemento();
lista * aloca_lista();
void inclui_no_final(lista * l, llint num);
void mostra_lista(lista * l);
void bubble_sort(lista * l);
void insertion_sort(lista * l);
int verifica_ordenacao(lista * l);
lista * apaga(lista * l);

int main()
{
    srand(time(NULL));

    lista * l;
    llint i, num;
    double tempo;

    l = aloca_lista();

    printf("\n> ");
    scanf("%lld", &num);

    for(i = num; i > 0; i--)
        inclui_no_final(l, i);

    tempo = omp_get_wtime();
    bubble_sort(l);
    tempo = omp_get_wtime() - tempo;

    printf("\n tempo bubble sort: %f", tempo);


    l = apaga(l);


    for(i = num; i > 0; i--)
        inclui_no_final(l, i);

    tempo = omp_get_wtime();
    insertion_sort(l);
    tempo = omp_get_wtime() - tempo;

    printf("\n tempo insertion  : %f", tempo);

    printf("\n");
    return 0;
}


void insertion_sort(lista * l)
{
    elemento * aux1, * aux2;
    llint num_aux;

    aux1 = l->inicio->prox;

    while(aux1 != NULL){
        num_aux = aux1->valor;
        aux2 = aux1->ant;
        while(aux2 != NULL){
            if(aux2->valor > num_aux){
                aux2->prox->valor = aux2->valor;
            }else{
                aux2->prox->valor = num_aux;
                break;
            }
            aux2 = aux2->ant;
        }
        if(aux2 == NULL){
            l->inicio->valor = num_aux;
        }
        aux1 = aux1->prox;
    }
}

void bubble_sort(lista * l)
{
    llint i, j, num;
    int trocou = 1;

    elemento * auxi, * auxj;
    
    auxi = l->inicio;

    for(i = 0; i < l->qtd - 1 && trocou; i++){
        trocou = 0;
        auxj = l->inicio;
        for(j = 0; j < l->qtd -1 -i; j++){
            if(auxj->valor > auxj->prox->valor){
                num = auxj->valor;
                auxj->valor = auxj->prox->valor;
                auxj->prox->valor = num;

                trocou = 1;
            }
            auxj = auxj->prox;
        }
        auxi = auxi->prox;
    }
}

lista * apaga(lista * l)
{
    elemento * aux;
    aux = l->inicio->prox;

    while(aux){
        free(aux->ant);
        aux = aux->prox;
    }

    free(aux);

    l = calloc(1, sizeof(lista));
    return l;
}

int verifica_ordenacao(lista * l)
{
    int ord = 1;
    elemento * aux;

    aux = l->inicio;

    while(aux->prox){
        if(aux->valor > aux->prox->valor)
            return 0;
        aux = aux->prox;
    }

    return ord;
}

void mostra_lista(lista * l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n %lld", aux->valor);
            aux = aux->prox;
        }
    }
}

void inclui_no_final(lista * l, llint num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        l->final->prox = novo;
        novo->ant = l->final;
    }else{
        l->inicio = novo;
    }
    l->final = novo;

    l->qtd++;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = calloc(1, sizeof(elemento));
    return novo;
}

lista * aloca_lista()
{
    lista * nova;
    nova = calloc(1, sizeof(lista));
    return nova;
}