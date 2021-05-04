#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int lint;

void insertionsort(long long int * vet, long long int tam);
void insertionsort_2(long long int * vet, long long int tam);
void mostra_lista(lint * vet, lint tam);

int main()
{
    lint * vet, tam, i, *vet2;

    printf("\n tamanho: ");
    scanf("%lld", &tam);

    vet = calloc(tam, sizeof(lint));
    vet2 = calloc(tam, sizeof(lint));

    lint j = tam;
    for(i = 0; i < tam; i++){
        vet[i] = j;
        vet2[i] = j;
        j--;
    }

    double t1, t2;

    t1 = omp_get_wtime();
    insertionsort(vet, tam);
    t2 = omp_get_wtime();

    printf("\n tempo 1: %f", t2-t1);
    
    t1 = omp_get_wtime();
    insertionsort_2(vet2, tam);
    t2 = omp_get_wtime();

    printf("\n tempo 2: %f", t2-t1);

    printf("\n");
    return 0;
}

void mostra_lista(lint * vet, lint tam)
{
    printf("\n ---------");
    lint i = 0;
    for(;i<tam;i++){
        printf("\n %lld", vet[i]);
    }
}

void insertionsort(long long int * vet, long long int tam) 
{
    // mais rapido
    long long int i, j, aux;

    for(i = 1; i< tam; i++){
        aux = vet[i];
        int sair = 0;
        for(j = i - 1; j>= 0 && !sair; j--){
            if(vet[j] > aux){
                vet[j+1] = vet[j];
            }else{
                vet[j+1] = aux;
                sair = 1;
            }
        }
        if(sair == 0){
            vet[0] = aux;
        }
    }
}

void insertionsort_2(long long int * vet, long long int tam)
{
    long long int i, j, aux;

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
    }
}
