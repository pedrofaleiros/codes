#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

llint * aloca_vetor(llint tam);
void mostra_vetor(llint * vet, llint tam);
void quicksort(llint * vet, llint inicio, llint final);
int ordenado(llint * vet, llint tam);

int main()
{
    srand(time(NULL));

    llint num, * vet;
    double tempo;

    printf("\n > ");
    scanf("%lld", &num);

    vet = aloca_vetor(num);

    tempo = omp_get_wtime();
    quicksort(vet, 0, num-1);
    tempo = omp_get_wtime() - tempo;

    /* mostra_vetor(vet, num); */
    printf("\n tempo: %f", tempo);

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

void quicksort(llint * vet, llint inicio, llint final)
{
    llint pivo, i, j, aux;

    if(inicio >= final) return;

    pivo = vet[inicio];
    j = final;
    i = inicio;

    while(j != i){
        if(i > j){
            if(vet[j] > pivo){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

                aux = i;
                i = j; 
                j = aux;
            }
        }else{
            if(vet[j] < pivo){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

                aux = i;
                i = j; 
                j = aux;
            }
        }

        if(i > j){
            j++;
        }else{
            j--;
        }
    }

    quicksort(vet, inicio, i);
    quicksort(vet, i+1, final);
}

void mostra_vetor(llint * vet, llint tam)
{
    llint i = 0;
    for(i = 0; i < tam; i++){
        printf("\n %lld", vet[i]);
    }
}

llint * aloca_vetor(llint tam)
{
    llint * vet, i, j;

    vet = (llint*)malloc(sizeof(llint)*tam);

    j = 0;
    for(i = tam; i > 0; i--){
        vet[j] = i;
        j++;
    }

    return vet;
}