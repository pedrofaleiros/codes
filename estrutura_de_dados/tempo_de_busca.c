/* 
comparando tempo de execucao do balance line 
com uma busca comum
com lista iguais
 */
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
void compara_listas(lista * l1, lista * l2);
void balance_line(lista * l1, lista * l2);

int main()
{
    srand(time(NULL));

    lint limite, i, num, aux;
    lista * des, * ord, *des2, *ord2;
    double t1, t2;   

    des = aloca_lista();
    des2 = aloca_lista();
    ord = aloca_lista();
    ord2 = aloca_lista();

    printf("\n limite: ");
    scanf("%lld", &limite);
    
    lint * vet, * vet2;
    vet = calloc(2*limite, sizeof(lint));
    vet2 = calloc(2*limite, sizeof(lint));

    for(i = 0; i < 2*limite; i++){ // preenche listas
        vet[i] = i+1;
        vet2[i] = i+1;
    }

    for(i = 0; i < 2*limite; i++){ // embaralha listas
        num = rand()%(2*limite);
        aux = vet[i];
        vet[i] = vet[num];
        vet[num] = aux;
        
        num = rand()%(2*limite);
        aux = vet2[i];
        vet2[i] = vet2[num];
        vet2[num] = aux;
    }
    
    for(i = 0; i < limite; i++){// inclui numeros nas listas
        inclui_ordenado(ord, vet[i]);
        inclui_ordenado(ord2, vet2[i]);
        inclui_no_final(des, vet[i]);
        inclui_no_final(des2, vet2[i]);
    }

    free(vet);
    free(vet2);

    t1 = omp_get_wtime();
    compara_listas(des, des2);
    t1 = omp_get_wtime() - t1;

    printf("\n---");
    t2 = omp_get_wtime();
    balance_line(ord, ord2);    
    t2 = omp_get_wtime() - t2;

    printf("\n tempo comparacao: %f", t1);
    printf("\n tempo balance   : %f", t2);

    printf("\n");
    return 0;
}

void balance_line(lista * l1, lista * l2)
{
    if(l1->inicio && l2->inicio){
        elemento * a1, * a2;
        a1 = l1->inicio;
        a2 = l2->inicio;

        while(a1 && a2){
            if(a1->valor == a2->valor){
                printf("\n %lld", a1->valor);
                a1 = a1->prox;
                a2 = a2->prox;
            }else if(a1->valor > a2->valor){
                a2 = a2->prox;
            }else{
                a1 = a1->prox;
            }
        }
    }
}

void compara_listas(lista * l1, lista * l2)
{
    if(l1->inicio && l2->inicio){
        elemento * a1, * a2;
        a1 = l1->inicio;

        while(a1 != NULL){
            a2 = l2->inicio;
            while(a2 && a1){
                if(a1->valor == a2->valor){
                    printf("\n %lld", a1->valor);
                }
                a2 = a2->prox;
            }
            a1 = a1->prox;
        }
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
