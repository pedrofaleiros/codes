#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"
#include "sort.h"

llint * aloca_vetor_ordenado(llint num);
llint * aloca_vetor_invertido(llint num);
llint * aloca_vetor_aleatorio(llint num);

void mostra_lista(llint * vet, llint num);


int main()
{
    srand(time(NULL));

    llint * vet, num;

    printf("\n num: ");
    scanf("%lld", &num);

    printf("\n aleatorio: ");
    vet = aloca_vetor_aleatorio(num);
    mostra_lista(vet, num);
    insertion_sort(vet, num);
    printf("\n ordenado:");
    mostra_lista(vet, num);

    printf("\n");
    return 0;
}

void mostra_lista(llint * vet, llint num)
{
    llint i = 0;

    printf("\n");
    for(; i < num; i++)
        printf(" %lld", vet[i]);
}

llint * aloca_vetor_aleatorio(llint num)
{
    llint * vet, aleatorio, aux, i;

    vet = calloc(num, sizeof(llint));

    for(i = 0; i < num; i++)
        vet[i] = i+1;

    for(i = 0; i < num; i++){
        aleatorio = rand()%num;

        aux = vet[i];
        vet[i] = vet[aleatorio];
        vet[aleatorio] = aux;
    }

    return vet;
}

llint * aloca_vetor_invertido(llint num)
{
    llint * vet, i, j;

    vet = calloc(num, sizeof(llint));

    j = num;

    for(i = 0; i < num; i++){
        vet[i] = j;
        j--;
    }

    return vet;
}

llint * aloca_vetor_ordenado(llint num)
{
    llint * vet, i;

    vet = calloc(num, sizeof(llint));

    for(i = 0; i < num; i++)
        vet[i] = i+1;

    return vet;
}