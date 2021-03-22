/* 
2) Faça um programa que leia do usuário 10 números inteiros e armazene os números pares em uma lista ligada
e os números ímpares em uma segunda lista ligada. Mostre o conteúdo das 2 listas;
*/

//  pronto
#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int valor;
    struct reg * prox;
}reg;

typedef struct lista{
    int qtd;
    struct reg * inicio;
}lista;

reg * aloca_reg();
lista * aloca_lista();
void inclui_na_lista(lista * l, int num);
void mostra_lista(lista * l);

int main()
{
    lista * pares, * impares;
    int i, num;

    pares = aloca_lista();
    impares = aloca_lista();

    for(i = 0; i < 10; i++){
        printf("Numero: ");
        scanf("%d", &num);
        if(num % 2 == 0){
            inclui_na_lista(pares, num);
        }else{
            inclui_na_lista(impares, num);
        }
    }

    printf("\nLista dos Pares:\n");
    mostra_lista(pares);

    printf("\nLista dos Impares:\n");
    mostra_lista(impares);
    
    return 0;
}

void mostra_lista(lista * l){
    if(l->inicio){
        reg * aux;

        aux = l->inicio;

        while(aux){
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }

    }else{
        printf("\nLista Vazia\n");
    }
}

void inclui_na_lista(lista * l, int num){
    
    reg * novo;
    novo = aloca_reg();
    novo->valor = num;

    if(l->inicio){
        reg * aux;
        aux = l->inicio;

        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = novo;
    }else{
        l->inicio = novo;
    }
    l->qtd++;
}

lista * aloca_lista(){
    lista * nova_lista;

    nova_lista = (lista*)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;

    return nova_lista;
}

reg * aloca_reg(){
    reg * novo_reg;

    novo_reg = (reg*)malloc(sizeof(reg));
    novo_reg->valor = 0;
    novo_reg->prox = NULL;

    return novo_reg;
}