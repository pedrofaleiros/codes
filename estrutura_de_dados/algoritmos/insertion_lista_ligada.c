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

lista * aloca_lista();
elemento * aloca_elemento();
void preenche_lista(lista * l, lint num);
void mostra_lista(lista * l);
void inclui_no_final(lista * l, lint num);
void insertionsort(lista * l);

int main()
{
    srand(time(NULL));

    lista * numeros;

    numeros = aloca_lista();

    lint sim;

    printf("\n> ");
    scanf("%lld", &sim);

    preenche_lista(numeros, sim);

    double t1, t2;

    t1 = omp_get_wtime();
    insertionsort(numeros);
    t2 = omp_get_wtime();

    printf("\n tempo: %f", t2-t1);

    printf("\n");
    return 0;
}

void insertionsort(lista * l)
{
    elemento * aux1, * aux2;
    lint num_aux;


    aux1 = l->inicio->prox;

    while(aux1 != NULL){
        num_aux = aux1->valor;
        int sair = 0;
        aux2 = aux1->ant;
        while(aux2 != NULL && sair == 0){
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

void inclui_no_final(lista * l, lint num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->final = novo;
    }else{
        
        l->final->prox = novo;
        novo->ant = l->final;
        l->final = novo;
    }
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

void preenche_lista(lista * l, lint num)
{
    lint * vet, i, random, aux;
    vet = calloc(num, sizeof(lint));

    for(i = 0; i < num; i++)
        vet[i] = i+1;

    for(i = 0; i < num; i++){
        random = rand()%num;
        aux = vet[i];
        vet[i] = vet[random];
        vet[random] = aux;
    }

    for(i = 0; i < num; i++)
        inclui_no_final(l, vet[i]);

    free(vet);
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
