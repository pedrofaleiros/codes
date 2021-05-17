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

    llint * vet, num;
    double tempo;

    FILE * fl;

    fl = fopen("tempos.csv", "w");

    if(fl == NULL) return 0;

    for(num = 1000000; num <= 50000000; num = num + 1000000){

        vet = aloca_vetor(num);

        tempo = omp_get_wtime();
        quicksort(vet, 0, num-1);
        tempo = omp_get_wtime() - tempo;

        printf("\n numeros: %lld", num);
        printf("\n tempo: %f", tempo);
        fprintf(fl, "%lld;%f\n", num, tempo);
    }

    fclose(fl);

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

        /* if(i > j){
            j++;
        }else{
            j--;
        } */
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