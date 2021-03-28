/*
1) Utilizando como base o programa lista_ligada.c, construa um programa que disponibilize ao usuario as seguintes opcoes
    a) Incluir na lista: O usuário irá informar um número que será incluído na lista
    b) Mostrar lista: deverá ser mostrado na tela a lista completa.
    c) Mostrar pares da lista: deverá ser mostrado na tela apenas os números pares
*/

// pronto
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
int escolhe_opcao();
void inclui_na_lista(lista * l);
void mostra_lista(lista * l);
void mostra_pares(lista * l);

int main(){

    lista * l1;
    int opcao = 1;

    l1 = aloca_lista();

    /* void (*funcao[3])(lista*);
    funcao[0] = inclui_na_lista;
    funcao[1] = mostra_lista;
    funcao[2] = mostra_pares; */

    while(opcao){

        opcao = escolhe_opcao();

        if(opcao == 1){
            inclui_na_lista(l1);
        }else if(opcao == 2){
            mostra_lista(l1);
        }else if(opcao == 3){
            mostra_pares(l1);
        }

    }


    return 0;
}

void mostra_pares(lista * l){
    if(l->inicio){
        reg * aux;
        int achou = 0;

        aux = l->inicio;

        printf("\nNumeros pares:\n");
        while(aux){
            if(aux->valor % 2 == 0){
                printf("%d\n", aux->valor);
                achou = 1;
            }
            aux = aux->prox;
        }

        if(!achou){
            printf("Nenhum numero par\n");
        }

    }else{
        printf("\nLista Vazia\n");
    }
}

void mostra_lista(lista * l){
    if(l->inicio){
        reg * aux;

        aux = l->inicio;

        printf("\nNumeros:\n");
        while(aux){
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }

    }else{
        printf("\nLista Vazia\n");
    }
}

void inclui_na_lista(lista * l){
    int num;
    printf("Incluir numero: ");
    scanf("%d", &num);

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

int escolhe_opcao(){
    int opcao;

    printf("\n1 - Incluir Numero\n");
    printf("2 - Mostrar Lista\n");
    printf("3 - Mostrar pares\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
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