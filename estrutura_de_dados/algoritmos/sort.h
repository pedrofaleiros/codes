#include <stdio.h>
#include <stdlib.h>

typedef long long int llint;

void quick_sort(llint * vet, llint inicio, llint final);
void merge_sort(llint * vet, llint inicio, llint final);
void bubble_sort(llint * vet, llint tamanho);
void insertion_sort(llint * vet, llint tamanho);
void selection_sort(llint * vet, llint tamanho);

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
    llint i, j, aux;

    for(i = 1; i < tamanho; i++){
        aux = vet[i];
        for(j = i - 1; j >= 0 && vet[j] > aux; j--){
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
}

void selection_sort(llint * vet, llint tamanho);


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

void merge_sort(llint * vet, llint inicio, llint final)
{
    llint meio;
    if(inicio < final){
        meio = (final+inicio)/2;
        merge_sort(vet, inicio, meio);
        merge_sort(vet, meio+1, final);
        merge(vet, inicio, meio, final);
    }
}

void quick_sort(llint * vet, llint inicio, llint final)
{
    llint i, pivo, aux;

    if(inicio >= final) return;

    i = final;
    pivo = inicio;

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

        if(i < pivo)
            i++;
        else
            i--;
    }

    quick_sort(vet, inicio, pivo-1);
    quick_sort(vet, pivo+1, final);
}