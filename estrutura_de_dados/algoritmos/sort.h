#include <stdio.h>
#include <stdlib.h>

typedef long long int llint;

void bubble_sort(llint * vet, llint tamanho)
{
    llint i, j, aux;
    int trocou = 1;

    for(i = 0; i < tamanho-1 && trocou; i++){
        trocou = 0;
        for(j = 0; j < tamanho-1-i; j++){
            if(vet[j] > vet[j+1]){
                trocou = 1;

                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

void insertion_sort(llint * vet, llint tamanho)
{
    
}

void selection_sort(llint * vet, llint tamanho);

void merge_sort(llint * vet, llint inicio, llint final);

void quick_sort(llint * vet, llint inicio, llint final);