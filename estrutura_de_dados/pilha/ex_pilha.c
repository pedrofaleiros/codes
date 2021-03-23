/* 
2) Construa uma pilha utilizando uma lista ligada.
Obs. Implemente as operações Push, pop, stackpop e empty.
*/

// pronto
#include <stdio.h>
#include <stdlib.h>
 
typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;
 
typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();

void push(int num);
int pop();
int empty();
int stackpop();

lista * pilha;

int main()
{
    int opcao = 1, num;

    pilha = aloca_lista();

    while(opcao){
        printf("\n1 - push");
        printf("\n2 - pop");
        printf("\n3 - stackpop");
        printf("\n0 - sair");
        printf("\nOpcao: ");

        scanf("%d", &opcao);

        if(opcao == 1){
            printf("\nnumero: ");
            scanf("%d", &num);
            push(num);
        }else if(opcao == 2){
            num = pop();
            if(num != -1)
                printf("\n\tnumero removido: %d\n", num);
        }else if(opcao == 3){
            num = stackpop();
            if(num != -1)
                printf("\nelemento do topo: %d\n", num);
        }else if(opcao != 0 ){
            printf("\nOpcao invalida\n");
        }
    }

    return 0;
}

int stackpop()
{
    if(empty()){
        printf("\npilha vazia\n");
        return -1;
    }else{
        return pilha->inicio->valor;
    }
}

int empty()
{
    if(pilha->inicio == NULL)
        return 1;
    else
        return 0;
}

void push(int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(empty()){
        pilha->inicio = novo;
    }else{
        novo->prox = pilha->inicio;
        pilha->inicio = novo;
    }
    pilha->qtd++;
}

int pop()
{
    if(empty()){
        printf("\npilha vazia\n");
        return -1;
    }else{
        elemento * aux;
        aux = pilha->inicio;

        int num = aux->valor;

        pilha->inicio = aux->prox;
        free(aux);

        pilha->qtd--;
        return num;
    }
}

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

lista * aloca_lista()
{
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}