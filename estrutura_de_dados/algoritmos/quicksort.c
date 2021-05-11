#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

//errado
typedef long long int llint;

llint * aloca_vetor(llint tam);
void mostra_vetor(llint * vet, llint tam);
void quicksort(llint * vet, llint inicio, llint final);

int main()
{
    srand(time(NULL));

    llint * vet, tamanho;

    printf("\n> ");
    scanf("%lld", &tamanho);

    vet = aloca_vetor(tamanho);

    /* mostra_vetor(vet, tamanho);
    printf("\n-----"); */

    double tempo = omp_get_wtime();
    quicksort(vet, 0, tamanho-1);
    tempo = omp_get_wtime() - tempo;
    printf("\n tempo: %f", tempo);

    //mostra_vetor(vet, tamanho);


    printf("\n");
    return 0;
}

void quicksort(llint * vet, llint inicio, llint final)
{
    llint pivo, i, aux;

    pivo = inicio;
    i = final;

    if(inicio == final) return;

    while(i != pivo){
        if(pivo < i){
            if(vet[pivo] > vet[i]){
                //troca
                aux = vet[i];
                vet[i] = vet[pivo];
                vet[pivo] = aux;

                aux = i;
                i = pivo;
                pivo = aux;
            }
        }else{
            if(vet[pivo] < vet[i]){
                //troca
                aux = vet[i];
                vet[i] = vet[pivo];
                vet[pivo] = aux;

                aux = i;
                i = pivo;
                pivo = aux;
            }
        }
        if(i < pivo){
            i++;
        }else{
            i--;
        }
    }

    quicksort(vet, 0, pivo);
    quicksort(vet, pivo+1, final);

}

void mostra_vetor(llint * vet, llint tam)
{
    llint i = 0;
    for(i = 0; i < tam; i++)
        printf("\n %lld", vet[i]);
}

llint * aloca_vetor(llint tam)
{
    llint * vet, i, aux, num;
    vet = calloc(1, sizeof(llint));

    for(i = 0; i < tam; i++)
        vet[i] = i+1;

    for(i = 0; i < tam; i++){
        num = rand()%tam;
        aux = vet[i];
        vet[i] = vet[num];
        vet[num] = aux;
    }

    return vet;
}