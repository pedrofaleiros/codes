#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int llint;

llint * aloca_vetor(llint tamanho);
void mostra_vetor(llint * vet, llint tamanho);
void bubblesort(llint * vet, llint tamanho);

int main()
{
    srand(time(NULL));

    llint * vet;
    llint tam = 10;

    vet = aloca_vetor(tam);

    mostra_vetor(vet, tam);

    printf("\n ----");
    bubblesort(vet, tam);
    mostra_vetor(vet, tam);

    printf("\n");
    return 0;
}


void bubblesort(llint * vet, llint tamanho)
{
    llint i, j, aux, trocou;

    for(i = 0; i < tamanho-1 && trocou; i++){
        trocou = 0;
        for(j = 0; j < tamanho-i-1; j++){
            if(vet[j] > vet[j+1]){
                trocou = 1;
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

void mostra_vetor(llint * vet, llint tamanho)
{
    llint i = 0;

    for(; i < tamanho; i++)
        printf("\n %lld", vet[i]);
}

llint * aloca_vetor(llint tamanho)
{
    llint i = 0, j, aux;
    llint * vetor;

    vetor = malloc(sizeof(llint)*tamanho);

    for(; i < tamanho; i++)
        vetor[i] = i+1;

    for(i = 0; i < tamanho; i++){
        j = rand() % tamanho;
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }

    return vetor;
}