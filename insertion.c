#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int * aloca_vetor(long long int num);
void insertionsort(long long int * vet, long long int tam);

int main()
{
    srand(time(NULL));

    FILE * fl;

    fl = fopen("tempos.csv", "a");
    if(fl == NULL)
        return 0;

    long long int * vetor;
    long long int n, i;
    double t1, t2;

    printf("\n Numero N: ");
    scanf("%lld", &n);

    vetor = aloca_vetor(n);
    
    t1 = omp_get_wtime();
    insertionsort(vetor, n);
    t2 = omp_get_wtime();

    printf("\n tempo decorrido: %f", t2-t1);
    fprintf(fl,"%lld;%f\n",n,t2-t1);
    fclose(fl);

    printf("\n");
    return 0;
}

void insertionsort(long long int * vet, long long int tam)
{
    long long int i, j, aux;

    for(i = 1; i< tam; i++){
        aux = vet[i];
        int sair = 0;
        for(j = i - 1; j>= 0 && !sair; j--){
            if(vet[j] > aux){
                vet[j+1] = vet[j];
                vet[j] = aux;
            }else{
                vet[j+1] = aux;
                sair = 1;
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
