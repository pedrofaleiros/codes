#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int llint;

llint * aloca_vetor(llint num);
void mostra_vetor(llint * vet, llint tamanho);
int ordenado(llint * vet, llint tamanho);

void bubblesort(llint * vet, llint tamanho);
void insertionsort(llint * vet, llint tamanho);
void selectionsort(llint * vet, llint tamanho);
void mergesort(llint * vet, llint inicio, llint final);
void merge(llint * vet, llint inicio, llint meio, llint final);


int main()
{
    srand(time(NULL));

    llint * vet, num;

    num = 15;

    vet = aloca_vetor(num);

    mergesort(vet, 0, num-1);
    mostra_vetor(vet, num);

    ordenado(vet, num) == 1 ? printf("\nsim") : printf("\nnao");

    printf("\n");
    return 0;
}

void mergesort(llint * vet, llint inicio, llint final)
{
    if(inicio < final){
        llint meio;
        meio = (inicio+final)/2;
        mergesort(vet, inicio, meio);
        mergesort(vet, meio+1, final);
        merge(vet, inicio, meio, final);
    }
}

void merge(llint * vet, llint inicio, llint meio, llint final)
{
    llint *novo, i, j, k;

    novo = calloc(final-inicio+1, sizeof(llint));

    i = inicio;
    j = meio+1;
    k = 0;

    while(i <= meio && j <= final){
        if(vet[i] <= vet[j]){
            novo[k] = vet[i];
            i++;
        }else{
            novo[k] = vet[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        novo[k] = vet[i];
        k++;
        i++;
    }

    while(j <= final){
        novo[k] = vet[j];
        k++;
        j++;
    }

    for(i = 0; i < (final-inicio+1); i++){
        vet[inicio+i] = novo[i];
    }

    free(novo);
}

void selectionsort(llint * vet, llint tamanho)
{
    llint i, j, aux, ind_menor;

    for(i = 0; i < tamanho-1; i++){
        ind_menor = i;
        for(j = i; j < tamanho; j++){
            if(vet[j] < vet[ind_menor]){
                ind_menor = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[ind_menor];
        vet[ind_menor] = aux;
    }
}

void insertionsort(llint * vet, llint tamanho)
{
    llint i, j, aux;

    for(i = 1; i < tamanho; i++){
        aux = vet[i];
        for(j = i-1; j >= 0 && vet[j] > aux; j--){
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }


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