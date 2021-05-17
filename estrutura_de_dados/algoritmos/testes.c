#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

typedef struct elemento{
    llint valor;
    struct elemento * prox;
}elemento;

typedef struct lista{
    llint qtd;
    struct elemento * inicio;
}lista;

void mostra_lista(llint * vet, llint tam);
elemento * aloca_elemento();
lista * aloca_lista();
llint * aloca_vetor(llint tam);
void inclui_ordenado(lista * l, llint num);
void ordena(llint * vet, llint num);


int main()
{
    llint * vet, num;

    printf("\n > ");
    scanf("%lld", &num);

    vet = aloca_vetor(num);

    double t1;

    t1 = omp_get_wtime();
    ordena(vet, num);
    t1 = omp_get_wtime() - t1;

    printf("\n tempo: %f", t1);

    printf("\n");
    return 0;
}

void ordena(llint * vet, llint num)
{
    llint i;

    lista * l;
    l = aloca_lista();

    for(i = 0; i < num; i++){
        inclui_ordenado(l, vet[i]);
    }

    elemento * aux;

    aux = l->inicio;

    i = 0;
    while(aux){
        vet[i] = aux->valor;
        aux = aux->prox;
        i++;
    }

}

llint * aloca_vetor(llint tam)
{
    llint * vet, i, aux, aleatorio;

    vet = (llint*)malloc(sizeof(llint)*tam);

    for(i = 0; i < tam; i++){
        vet[i] = i+1;
    }

    for(i = 0; i < tam; i++){
        aleatorio = rand()%tam;

        aux = vet[i];
        vet[i] = vet[aleatorio];
        vet[aleatorio] = aux;
    }

    return vet;
}

void inclui_ordenado(lista * l, llint num)
{
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio != NULL)
    {
        elemento * aux, * ant = NULL;

        aux = l->inicio;

        while(aux->prox && aux->valor < num){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->valor >= num){
            if(ant != NULL)
                ant->prox = novo;
            else
                l->inicio = novo;

            novo->prox = aux;   
        }else{
            aux->prox = novo;
        }

    }else{
        l->inicio = novo;
    }
    l->qtd++;
}

void mostra_lista(llint * vet, llint tam)
{
    llint i = 0;
    printf("\n ");
    for(;i<tam;i++){
        printf(" %lld", vet[i]);
    }
}

lista * aloca_lista()
{
    lista * nova_lista;

    nova_lista = (lista*)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;

    return nova_lista;
}

elemento * aloca_elemento()
{
    elemento * novo_elemento;

    novo_elemento = (elemento*)malloc(sizeof(elemento));
    novo_elemento->valor = 0;
    novo_elemento->prox = NULL;

    return novo_elemento;
}