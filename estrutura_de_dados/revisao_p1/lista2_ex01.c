/* 
1) Utilizando como base o programa lista_ligada.c, 
construa um programa que disponibilize ao usuario as seguintes opcoes
    a) Incluir na lista: O usuário irá informar um número que será incluído na lista
    b) Mostrar lista: deverá ser mostrado na tela a lista completa.
    c) Mostrar pares da lista: deverá ser mostrado na tela apenas os números pares 
*/

// pronto
#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

void inclui_elemento(lista * l, int num);
void mostra_pares(lista * l);

int main()
{
    int opcao = 1, num;
    lista * numeros;
    numeros = aloca_lista();

    while(opcao){
        printf("\n 1 - incluir na lista");
        printf("\n 2 - mostra lista");
        printf("\n 3 - mostra pares da lista");
        printf("\n 0 - sair");
        printf("\n opcao> ");

        scanf("%d", &opcao);

        if(opcao == 1){
            printf("\n numero> ");
            scanf("%d", &num);
            inclui_elemento(numeros, num);
        }else if(opcao == 2){
            mostra_lista(numeros);
        }else if(opcao == 3){
            mostra_pares(numeros);
        }else if(opcao != 0){
            printf("\n opcao invalida");
        }
    }

    printf("\n");
    return 0;   
}

void mostra_pares(lista * l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        printf("\nelementos pares:");
        while(aux){
            if(aux->valor % 2 == 0)
                printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\n lista vazia");
    }
}

void inclui_elemento(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux->prox)
            aux = aux->prox;

        aux->prox = novo;
    }else{
        l->inicio = novo;
    }
    l->qtd++;
}