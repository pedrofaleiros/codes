#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

void mostra_vetor(llint * vet, llint tam);
llint * aloca_vetor(llint tam);
void bubblesort(long long int * vet, long long int tam);
void insertionsort(llint * vet, llint tam);
void mergesort(llint * vet, llint inicio, llint final);
void merge(llint * vet, llint inicio, llint meio, llint final);
void quicksort(llint * vet, llint inicio, llint final);
int ordenado(llint * vet, llint tam);
void selectionsort(llint * vet, llint tam);

int main()
{
    llint * vet, num;
    double t1;

    printf("\n> ");
    scanf("%lld", &num);
    
    //bubble sort
    vet = aloca_vetor(num);
    t1 = omp_get_wtime();
    bubblesort(vet, num);
    t1 = omp_get_wtime() - t1;
    if(ordenado(vet, num))
        printf("\n tempo bubble sort    : %f", t1);
    free(vet);
    
    //insertion sort
    vet = aloca_vetor(num);
    t1 = omp_get_wtime();
    insertionsort(vet, num);
    t1 = omp_get_wtime() - t1;
    if(ordenado(vet, num))
        printf("\n tempo insertion sort : %f", t1);
    free(vet);
    
    //selectiontion sort
    vet = aloca_vetor(num);
    t1 = omp_get_wtime();
    selectionsort(vet, num);
    t1 = omp_get_wtime() - t1;
    if(ordenado(vet, num))
        printf("\n tempo selection sort : %f", t1);
    free(vet);

    //merge sort
    vet = aloca_vetor(num);
    t1 = omp_get_wtime();
    mergesort(vet, 0, num - 1);
    t1 = omp_get_wtime() - t1;
    if(ordenado(vet, num))
        printf("\n tempo merge sort     : %f", t1);
    free(vet);

    //quick sort
    vet = aloca_vetor(num);
    t1 = omp_get_wtime();
    quicksort(vet, 0, num - 1);
    t1 = omp_get_wtime() - t1;
    if(ordenado(vet, num))
        printf("\n tempo quick sort     : %f", t1);
    free(vet);

    printf("\n");
    return 0;
}

void selectionsort(llint * vet, llint tam)
{
    llint i, j, aux, ind_menor;

    for(i = 0; i< tam-1; i++){
        ind_menor = i;
        for(j = i+1; j < tam; j++){
            if(vet[ind_menor] > vet[j]){
                ind_menor = j;
            }
        }
        aux = vet[ind_menor];
        vet[ind_menor] = vet[i];
        vet[i] = aux;
    }
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

    i = inicio;
    pivo = vet[i];
    j = final;

    while(j != i){
        if(i > j){
            if(vet[j] > pivo){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

                aux = i;
                i = j; 
                j = aux;

                j--;
            }else{
                j++;
            }
        }else{
            if(vet[j] < pivo){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

                aux = i;
                i = j; 
                j = aux;
                
                j++;
            }else{
                j--;
            }
        }
    }

    quicksort(vet, inicio, i-1);
    quicksort(vet, i+1, final);

}
void mostra_vetor(llint * vet, llint tam)
{
    llint i = 0;
    for(i = 0; i < tam; i++){
        printf("\n %lld", vet[i]);
    }
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

void bubblesort(long long int * vet, long long int tam)
{
    long long int aux, i, j;
    int trocou = 1;

    for(i = 0; i < tam-1 && trocou; i++){
        trocou = 0;
        for(j = 0; j < tam-i-1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                trocou = 1;
            }
        }
    }
}

void insertionsort(llint * vet, llint tam)
{
    llint i, j, aux;

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
        if(sair == 0)
            vet[0] = aux;
    }

    /* llint i, j, aux;

    for(i = 1; i< tam; i++){
        aux = vet[i];
        int sair = 0;
        for(j = i - 1; j>= 0 && vet[j] > aux; j--){
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    } */
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
