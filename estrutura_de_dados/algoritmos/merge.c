#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

long long int * aloca_vetor(long long int num);


void junta(long long int * vet, long long int inicio, long long int meio, long long int fim);
void mergesort(long long int * vet, long long int inicio, long long int fim);
int ordenado(long long int * vet, long long int tam);

int main()
{
    srand(time(NULL));

    long long int num, * vet;
    double tempo;

    printf("\n > ");
    scanf("%lld", &num);

    vet = aloca_vetor(num);

    tempo = omp_get_wtime();
    mergesort(vet, 0, num-1);
    tempo = omp_get_wtime() - tempo;

    printf("\n tempo: %f", tempo);

    printf("\n");
    return 0;
}

int ordenado(long long int * vet, long long int tam)
{
    long long int i;
    for(i = 1; i < tam; i++){
        if(vet[i] < vet[i-1]){
            return 0;
        }
    }
    return 1;
}

long long int * aloca_vetor(long long int num)
{
    long long int * vet, i, aux, aleatorio;

    vet = calloc(num, sizeof(long long int));

    for(i = 0; i < num; i++){
        vet[i] = i + 1; 
    }

    for(i = 0; i < num; i++){
        aux = vet[i];
        aleatorio = rand() % num;
        vet[i] = vet[aleatorio];
        vet[aleatorio] = aux;
    }

    return vet;
}

void mergesort(long long int * vet, long long int inicio, long long int fim)
{
    long long int meio;

    if (inicio<fim)
    {
        meio = (inicio+fim) / 2;
        mergesort(vet,inicio,meio);
        mergesort(vet,meio+1,fim);
        junta(vet,inicio,meio,fim);
    }  
}

void junta(long long int * vet, long long int inicio, long long int meio, long long int fim)
{
    long long int i,j,*aux,k;

    aux = (long long int*)calloc(fim-inicio+1,sizeof(long long int));

    i = inicio;
    j = meio+1;
    k=0;

    while(i<=meio && j<=fim)
    {
        if (vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            i++;
            k++;
        }
        else
        {
            aux[k] = vet[j];
            j++;
            k++;
        }
    }

    while(i<=meio)
    {
        aux[k] = vet[i];
        i++;
        k++;
    }

    while(j<=fim)
    {
        aux[k] = vet[j];
        j++;
        k++;
    }

    for(i=0;i<(fim-inicio+1);i++)
    {
        vet[inicio+i] = aux[i];
    }
    free(aux);
    return ;
}