/*
Similar ao código bubblesort.c, leia um valor N do usuário,  
aloque um vetor de tamanho N, preencha esse vetor com N
números aleatórios e utilizando o algorítmo insertionsort 
calcule o tempo para ordenar um vetor de tamanho N.

Monte um gráfico da curva do aumento de tempo de execução conforme se aumenta o valor de N.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int * aloca_vetor(long long int n);

int main()
{
    long long int *vet;
    long long int tam;

    srand(time(NULL));
    double t1,t2;
    FILE * arq;

    arq = fopen("tempos.csv","a+");
    if(arq==NULL)
        return 0;

    for(tam = 10000; tam <= 200000; tam = tam + 10000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        t1 = omp_get_wtime();
        bubblesort(vet, tam);
        t2 = omp_get_wtime();
        printf("\n Tempo para ordenar: %f",t2-t1);
        fprintf(arq,"%lld;%f\n",tam,t2-t1);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}

long long int * aloca_vetor(long long int n)
{
    long long int *vet, i;
    vet = (long long int *)calloc(n, sizeof(long long int));

    for(i = 0; i < n; i++){
        vet[i] = i + 1;
    }

    for(i = 0; i < n; i++){
        vet[i] = rand() % n;
    }

    return vet;
}



