#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int llint;

llint * aloca_vetor(llint num);
void mostra_vetor(llint * vet, llint tamanho);
int ordenado(llint * vet, llint tamanho);
void bubblesort(llint * vet, llint tamanho);
void insertionsort(llint * vet, llint tamanho);


int main()
{
    srand(time(NULL));

    llint * vet, num;

    num = 10;

    vet = aloca_vetor(num);

    insertionsort(vet, num);
    mostra_vetor(vet, num);

    ordenado(vet, num) == 1 ? printf("\nsim") : printf("\nnao");

    printf("\n");
    return 0;
}

void insertionsort(llint * vet, llint tamanho)
{


}

void bubblesort(llint * vet, llint tamanho)
{
    llint i, j, aux, trocou;

    trocou = 1;

    for(i = 0; i < tamanho-1 && trocou; i++){

        trocou = 0;

        for(j = 0; j < tamanho - i - 1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;

                trocou = 1;
            }
        }
    }
}

int ordenado(llint * vet, llint tamanho)
{
    llint i;

    for(i = 1; i < tamanho; i++)
        if(vet[i] < vet[i-1])
            return 0;
        
    return 1;
}

llint * aloca_vetor(llint num)
{
    llint i, j, aux, * vet;

    vet = calloc(num, sizeof(llint));

    for(i = 0; i < num; i++)
        vet[i] = i+1;

    for(i = 0; i < num; i++){
        j = rand()%num;

        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }
    
    return vet;
}

void mostra_vetor(llint * vet, llint tamanho)
{
    llint i;

    printf("\n");
    for(i = 0; i < tamanho; i++)
        printf(" %lld", vet[i]);
}