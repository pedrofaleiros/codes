#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"
#include "sort.h"

llint * aloca_vetor(llint num, int forma);
void mostra_lista(llint * vet, llint num);

int main()
{
    srand(time(NULL));

    llint * vet, num;
    double t1;

    printf("\n num: ");
    scanf("%lld", &num);

    vet = aloca_vetor(num, 0);
    mostra_lista(vet, num);
    vet = aloca_vetor(num, 1);
    mostra_lista(vet, num);
    vet = aloca_vetor(num, -1);
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

llint * aloca_vetor(llint num, int forma)
{
    llint * vet, i, aleatorio, aux, j;

    vet = calloc(num, sizeof(llint));

    if(forma == 1){
        for(i = 0; i < num; i++)
            vet[i] = i+1;
    
        for(i = 0; i < num; i++){
            aleatorio = rand()%num;
            aux = vet[i];
            vet[i] = vet[aleatorio];
            vet[aleatorio] = aux;
        }
    }else if(forma == -1){
        j = num;

        for(i = 0; i < num; i++){
            vet[i] = j;
            j--;
        }
    }else{
        for(i = 0; i < num; i++)
            vet[i] = i+1;
    }

    return vet;
}