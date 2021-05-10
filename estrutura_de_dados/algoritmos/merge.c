#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int llint;

long long int * aloca_vetor(long long int num);


int main()
{
    srand(time(NULL));
    FILE * fl;

    long long int * vet, tam, i;

    tam = 10;

    vet = aloca_vetor(tam);

    for(i = 0; i < tam; i++){
        printf("\n %lld", vet[i]);
    }

    

    printf("\n");
    return 0;
}

int ordenado(long long int * vet, lont long int tam)
{

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
