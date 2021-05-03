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

    preenche_lista(numeros, 10);

    insertionsort(numeros);

    mostra_lista(numeros);

    printf("\n");
    return 0;
}

void insertionsort(lista * l)
{
/*     long long int i, j, aux;

    for(i = 1; i< tam; i++){
        aux = vet[i];
        int sair = 0;
        for(j = i - 1; j>= 0 && !sair; j--){
            if(vet[j] > aux){
                vet[j+1] = vet[j];
                vet[j] = aux;
            }else{
                vet[j+1] = aux;
                sair = 1;
            }
        }
    } */

    elemento * aux, * aux2;
    lint num_aux;

    aux = l->inicio->prox;
    while(aux){
        num_aux = aux->valor;
        int sair = 0;
        aux2 = aux->ant;
        while(aux2 && !sair){
            if(aux2->valor > num_aux){
                aux2->prox->valor = aux2->valor;
                aux2->valor = num_aux;
            }else{
                aux2->prox->valor = num_aux;
                sair = 1;
            }
            aux2 = aux2->ant;
        }
        aux = aux->prox;
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
        
        novo->ant = l->final->ant;
        l->final->prox = novo;
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
