/*
Faça um programa que receba do usuario um número N inteiro 
positivo, e aloque dinamicamente um vetor de N sanduíches.
Cada sanduíche deve armazenara as segunites informações:
    nome
    valor
    peso
    avaliacao

Solicite ao usuário que preencha os N sanduíches e mostre na tela:
    a) A lista dos sanduiches que comecam com a letra A:
    b) Qual é o sanduíche melhor avaliado
    c) Qual é o peso médio dos sanduíches.
    d) Em caso de compra de 3 de cada um dos sanduíches qual será o valor da compra?
*/

// pronto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sand{
    char * nome;
    float valor;
    float peso;
    float avaliacao;
}sand;

sand * aloca_sand(int n);
void preenche(sand * s);
void mostra_letra_a(sand * s, int n);
void mostra_melhor_avaliado(sand * s, int n);
void mostra_peso_medio(sand * s, int n);
void mostra_preco_todos(sand * s, int n);

int main()
{
    int n;
    sand * lista;

    printf("\nN:");
    scanf("%d", &n);

    lista = aloca_sand(n);

    for(int i = 0; i < n; i++)
        preenche(&lista[i]);

    mostra_letra_a(lista, n);
    mostra_melhor_avaliado(lista, n);
    mostra_peso_medio(lista, n);
    mostra_preco_todos(lista, n);
    
    printf("\n");
    return 0;
}

void mostra_preco_todos(sand * s, int n)
{
    float preco_total = 0;
    for(int i = 0; i < n; i++){
        preco_total += (s[i].valor)*3;
    }

    printf("\n preco: R$%.2f", preco_total);
}

void mostra_peso_medio(sand * s, int n)
{
    float peso_medio = 0;
    for(int i = 0; i < n; i++){
        peso_medio += s[i].peso;
    }

    printf("\n peso medio; %.2f", peso_medio/n);
}

void mostra_melhor_avaliado(sand * s, int n)
{
    int melhor = 0;
    for(int i = 0; i < n; i++){
        if(s[i].avaliacao > s[melhor].avaliacao){
            melhor = i;
        }
    }

    printf("\n melhor avaliado: %s\n avaliacao: %.2f", s[melhor].nome, s[melhor].avaliacao);
}

void mostra_letra_a(sand * s, int n)
{
    for(int i = 0; i < n; i++){
        if(s[i].nome[0] == 'a'){
            printf("\n nome: %s", s[i].nome);
        }
    }
}

void preenche(sand * s)
{
    fflush(stdin);
    char nome[50];
    printf("\nNome: ");
    scanf("%s", nome);

    s->nome = (char*)malloc(sizeof(char)*strlen(nome));
    strcpy(s->nome, nome);

    printf("\nPeso: ");
    scanf("%f", &s->peso);

    printf("\nValor: ");
    scanf("%f", &s->valor);

    printf("\nAvaliacao: ");
    scanf("%f", &s->avaliacao);
}

sand * aloca_sand(int n)
{
    sand * nova;
    nova = (sand*)calloc(n, sizeof(sand));
    return nova;
}