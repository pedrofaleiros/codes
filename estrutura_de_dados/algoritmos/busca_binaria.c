/*
1 - Faça um programa que receba do usuário um valor N, aloque um vetor de tamanho N e preencha esse vetor com N valores
aleatórios de forma crescente. Solicite ao usuário um valor X e diga se esse valor X está ou não presente no vetor de
tamanho N. 
Mostre o tempo necessário para encontrar o valor X de forma sequencial e utilizando uma estrutura de busca binária.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

typedef long long int llint;

llint * aloca_vetor(llint num);
int busca(llint * vet, llint inicio, llint final, llint num);
int busca_seq(llint * vet, llint tam, llint num);

int main()
{   
    srand(time(NULL));

    llint * vet, n, x;
    double t1;

    printf("\n n: ");
    scanf("%lld", &n);

    vet = aloca_vetor(n);

    //for(x = 0; x < n; x++) printf(" %lld", vet[x]);
    printf("\n buscar numero x: ");
    scanf("%lld", &x);

    //forma sequencial
    t1 = omp_get_wtime();
    if(busca_seq(vet, n, x)){
        t1 = omp_get_wtime() - t1;
        printf("\n numero %lld esta na lista", x);
    }else{
        t1 = omp_get_wtime() - t1;
        printf("\n numero NAO esta na lista");
    }
    printf("\n tempo busca sequencial: %f", t1);

    //busca binaria
    t1 = omp_get_wtime();
    if(busca(vet, 0, n-1, x)){
        t1 = omp_get_wtime() - t1;
        printf("\n numero %lld esta na lista", x);
    }else{
        t1 = omp_get_wtime() - t1;
        printf("\n numero NAO esta na lista");
    }
    printf("\n tempo busca binaria: %f", t1);

    printf("\n");
    return 0;
}

int busca_seq(llint * vet, llint tam, llint num)
{
    llint i = 0;
    for(; i < tam; i++){
        if(vet[i] == num)
            return 1;
    }
    return 0;
}

int busca(llint * vet, llint inicio, llint final, llint num)
{
    llint meio;

    meio = (final+inicio)/2;

    if(inicio == final){
        if(vet[inicio] == num)
            return 1;
        else
            return 0;
    }

    if(vet[meio] == num){
        return 1;
    }else{
        if(num > vet[meio]){
            return busca(vet, meio+1, final, num);
        }else{
            if(meio > inicio){
                return busca(vet, inicio, meio-1, num);
            }else{
                return 0;
            }
        }
    }
}

llint * aloca_vetor(llint num)
{
    llint * vet, i, aux;

    vet = calloc(num, sizeof(long long int));

    vet[0] = rand()%2;

    for(i = 1; i < num; i++){
        vet[i] = (vet[i-1] + rand()%2 + 1);
    }

    return vet;
}