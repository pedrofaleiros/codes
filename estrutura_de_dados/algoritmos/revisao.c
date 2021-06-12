#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int llint;

llint * aloca_vetor(llint num);
void mostra_vetor(llint * vet, llint tamanho);


int main()
{
    srand(time(NULL));

    llint * vet, num;

    num = 5;

    vet = aloca_vetor(num);

    mostra_vetor(vet, num);



    printf("\n");
    return 0;
}

llint * aloca_vetor(llint num)
{
    llint i, aux, * vet;

    vet = calloc(num, sizeof(llint));

    for(i = 0; i < num; i++)
        vet[i] = i+1;

    for(i = 0; i < num; i++){
        
        aux = rand()%num;
        while(aux == i)
            aux = rand()%num;

        vet[i] = vet[i] + vet[aux];
        vet[aux] = vet[i] - vet[aux];
        vet[i] =  vet[i] - vet[aux];
    }
    
    return vet;
}

void mostra_vetor(llint * vet, llint tamanho)
{
    llint i;

    for(i = 0; i < tamanho; i++)
        printf("\n %lld", vet[i]);
}