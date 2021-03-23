/* 
2) Construa uma pilha utilizando uma lista ligada.
Obs. Implemente as operações Push, pop, stackpop e empty.
*/

// ta errado
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
int pop(lista *pilha);
void push(lista *pilha, int num);
int empty(lista *pilha);
//int stackpop(lista *pilha);

int main()
{
    lista * pilha;
    int opcao = 1, num;

    pilha = aloca_lista();

    while(opcao){
        printf("\n\n1 - pop");
        printf("\n2 - push");
        printf("\n3 - stackpop");
        printf("\n0 - sair");
        printf("\nOpcao: ");

        scanf("%d", &opcao);

        if(opcao == 1){
            num = pop(pilha);
            if(num)
                printf("\nnumero removido: %d", num);
        }else if(opcao == 2){
            printf("\nnumero: ");
            scanf("%d", &num);
            push(pilha, num);
        }else if(opcao == 3){
            //num = stackpop(pilha);
            if(num)
                printf("\nelemento do topo: %d", num);
        }
    }

    return 0;
}

int empty(lista *pilha)
{
    if(pilha->inicio == NULL)
        return 1;
    else
        return 0;
}

void push(lista *pilha, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(empty(pilha)){
        pilha->inicio = novo;
        pilha->qtd++;
    }else{
        elemento * aux;

        aux = pilha->inicio;
        
        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = novo;
        pilha->qtd++;
    }
}

int pop(lista *pilha)
{
    elemento * aux, * ant = NULL;

    if(empty(pilha)){
        printf("\npilha vazia");
        return 0;
    }else{
        aux = pilha->inicio;

        while(aux->prox){
            ant = aux;
            aux = aux->prox;
        }

        pilha->qtd--;
        
        if(ant == NULL){
            aux = pilha->inicio;
            pilha->inicio = NULL;
            return aux->valor;
        }else{
            ant->prox = NULL;
            return ant->valor;
        }
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