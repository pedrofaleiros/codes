#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int * aloca_vetor(long long int num);
void bubblesort(long long int * vet, long long int tam);

int main()
{
    srand(time(NULL));

    FILE * fl;

    fl = fopen("tempo_bubble.csv", "w");
    if(fl == NULL)
        return 0;

    long long int * vetor;
    long long int n, i;
    double t1, t2;

    printf("\n Numero N: ");
    scanf("%lld", &n);

    vetor = aloca_vetor(n);
    
    t1 = omp_get_wtime();
    bubblesort(vetor, n);
    t2 = omp_get_wtime();

    printf("\n tempo decorrido: %f", t2-t1);
    fprintf(fl,"%lld;%f\n",n,t2-t1);
    fclose(fl);

    printf("\n");
    return 0;
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

long long int * aloca_vetor(long long int num)
{
    long long int * vet, i, aux, aleatorio;

    vet = calloc(num, sizeof(long long int));

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
