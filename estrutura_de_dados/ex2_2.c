/*
2) Faça um programa que leia do usuário 10 números inteiros e armazene os números pares em uma lista ligada
e os números ímpares em uma segunda lista ligada. Mostre o conteúdo das 2 listas;
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento *inicio;
}lista;

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemento;

lista* aloca_lista();
void inclui_elemento(lista *l, int x);
elemento* aloca_elemento();
void mostra_elementos(lista *l);

int main()
{
    lista *pares;
    lista *impares;

    pares = aloca_lista();
    impares = aloca_lista();

    int i = 0, num;
    
    for(; i < 10; i++){
        printf("Numero: ");
        scanf("%d", &num);
        if(num % 2 == 0){
            inclui_elemento(pares, num);
        }else{
            inclui_elemento(impares, num);
        }
    }

    printf("\nLista dos pares:\n");
    mostra_elementos(pares);
    printf("\nLista dos impares:\n");
    mostra_elementos(impares);

    return 0;
}
void mostra_elementos(lista *l)
{
    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux)
        {
            printf("> %d\n", aux->valor);
            aux = aux->prox;
        }

    }else{
        printf("\tLista vazia\n");
    }
}

elemento* aloca_elemento()
{
    elemento *novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

void inclui_elemento(lista *l, int x)
{
    elemento *novo;

    novo = aloca_elemento();
    novo->valor = x;

    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }else{
        l->inicio = novo;
    }

    l->qtd += 1;
}

lista* aloca_lista()
{
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}
