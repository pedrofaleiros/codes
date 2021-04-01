/* 
2) Faça um programa que apresente o9 seguinte menu para o usuário:
    1 - incluir carro
    2 - procurar carro
    3 - remover carro pelo chassi
    4 - mostrar carro mais velho
    5 - mostrar carro mais caro
    obs. Informações de um veículo: marca, modelo, chassi, ano, preco;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    char * marca;
    char * modelo;
    int chassi;
    int ano;
    float preco;
    struct elemento * ant;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
    struct elemento * fim;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();

int main()
{
    lista * carros;

    carros = aloca_lista();



    return 0;
}


elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;
}

lista * aloca_lista()
{
    lista * nova;
    nova = (lista*)calloc(1, sizeof(lista));
    return nova;
}