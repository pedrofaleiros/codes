#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

//errado
long long int * aloca_vetor(long long int tam);
void mostra_vetor(long long int * vet, long long int tam);
void quicksort(long long int * vet, long long int inicio, long long int final);
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
    quicksort(vet, 0, num-1);
    tempo = omp_get_wtime() - tempo;

/*     mostra_vetor(vet, num); */
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

void quicksort(long long int * vet, long long int inicio, long long int final)
{
    long long int pivo, i, aux;

    pivo = inicio;
    i = final;

    while(pivo != i){
        if(pivo > i){
            if(vet[pivo] < vet[i]){
                aux = vet[pivo];
                vet[pivo] = vet[i];
                vet[i] = aux;

                aux = pivo;
                pivo = i;
                i = aux;
            }
        }else{
            if(vet[pivo] > vet[i]){
                aux = vet[pivo];
                vet[pivo] = vet[i];
                vet[i] = aux;

                aux = pivo;
                pivo = i;
                i = aux;
            }
        }

        if(i > pivo){
            i--;
        }else{
            i++;
        }
    }

    if(inicio < pivo-1){
        quicksort(vet, inicio, pivo-1);
    }
    if(pivo+1 < final){
        quicksort(vet, pivo+1, final);
    }
}



void mostra_vetor(long long int * vet, long long int tam)
{
    long long int i = 0;
    for(i = 0; i < tam; i++){
        printf("\n %lld", vet[i]);
    }
}

long long int * aloca_vetor(long long int tam)
{
    long long int * vet, i, j;

    vet = (long long int*)malloc(sizeof(long long int)*tam);

    j = 0;
    for(i = tam; i > 0; i--){
        vet[j] = i;
        j++;
    }

    return vet;
}