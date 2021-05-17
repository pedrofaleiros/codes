#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

llint * aloca_vetor(llint num);
void selectionsort(llint * vet, llint tam);
void mostra_vetor(llint * vet, llint tam);

int main()
{
    srand(time(NULL));

    FILE * fl;

    fl = fopen("tempo_insertion.csv", "a");
    if(fl == NULL)
        return 0;

    llint * vetor;
    llint n, i;
    double t1, t2;

    printf("\n Numero N: ");
    scanf("%lld", &n);

    vetor = aloca_vetor(n);

    t1 = omp_get_wtime();
    selectionsort(vetor, n);
    t2 = omp_get_wtime();

    printf("\n tempo decorrido: %f", t2-t1);
    fprintf(fl,"%lld;%f\n",n,t2-t1);
    fclose(fl);

    printf("\n");
    return 0;
}

void mostra_vetor(llint * vet, llint tam)
{
    llint i = 0;
    printf("\n");
    for(i = 0; i < tam; i++){
        printf(" %lld", vet[i]);
    }
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

llint * aloca_vetor(llint num)
{
    llint * vet, i, aux, aleatorio;

    vet = calloc(num, sizeof(llint));

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
