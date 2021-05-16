#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

llint * aloca_vetor(llint tam);
void mostra_vetor(llint * vet, llint tam);
void merge(llint * vet, llint inicio, llint meio, llint final);
void mergesort(llint * vet, llint inicio, llint final);
int ordenado(llint * vet, llint tam);


int main()
{
    llint * vet, num;
    double t1;

    printf("\n> ");
    scanf("%lld", &num);

    vet = aloca_vetor(num);

    t1 = omp_get_wtime();
    mergesort(vet, 0, num-1);
    t1 = omp_get_wtime() - t1;

    if(ordenado(vet, num))
        printf("\n tempo: %f", t1);

    printf("\n");
    return 0;
}

int ordenado(llint * vet, llint tam)
{
    llint i;
    for(i = 1; i < tam; i++){
        if(vet[i] < vet[i-1]){
            return 0;
        }
    }
    return 1;
}

void mergesort(llint * vet, llint inicio, llint final)
{
    llint meio;
    if(inicio < final){
        meio = (final+inicio)/2;
        mergesort(vet, inicio, meio);
        mergesort(vet, meio+1, final);
        merge(vet, inicio, meio, final);
    }
}

void merge(llint * vet, llint inicio, llint meio, llint final)
{
    llint * aux, i, j, k;
    aux = calloc(final-inicio+1, sizeof(llint));

    k = 0;
    i = inicio;
    j = meio+1;

    while(i <= meio && j <= final){
        if(vet[i] <= vet[j]){
            aux[k] = vet[i];
            i++;
            k++;
        }else{
            aux[k] = vet[j];
            j++;
            k++;
        }
    }

    while(i <= meio){
        aux[k] = vet[i];
        k++;
        i++;
    }

    while(j <= final){
        aux[k] = vet[j];
        k++;
        j++;
    }

    for(i = 0; i < (final-inicio+1); i++){
        vet[inicio+i] = aux[i];
    }

    free(aux);
}

void mostra_vetor(llint * vet, llint tam)
{
    llint i = 0;
    for(; i < tam; i++) printf("\n %lld", vet[i]);
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