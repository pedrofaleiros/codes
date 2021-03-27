/* 
2) Construa uma pilha utilizando uma lista ligada.
Obs. Implemente as operações Push, pop, stackpop e empty.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define True 1
#define False 0

typedef struct stack{
    struct elemento * topo;
}stack;

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

stack * aloca_pilha();
elemento * aloca_elemento();
void push(int num);
int pop();
int stackpop();
bool empty();
int escolhe_opcao();
void mostra();

stack * pilha;

int main()
{
    pilha = aloca_pilha();
    int opcao = 1, num;

    while(opcao != 0){
        opcao = escolhe_opcao();

        if(opcao == 1){
            printf("\nnumero> ");
            scanf("%d", &num);
            push(num);
        }else if(opcao == 2){
            int num = pop();
            if(num != -1){
                printf("\nnumero removido> %d", num);
            }else{
                printf("\n pilha vazia");
            }
        }else if(opcao == 3){
            int num = stackpop();
            if(num != -1){
                printf("\nnumero do topo> %d", num);
            }else{
                printf("\n pilha vazia");
            }
        }else if(opcao == 4){
            mostra();
        }else if(opcao == 0){
            printf("\n fim");
        }else{
            printf("\n opcao invalida");
        }
    }

    return 0;
}

void mostra()
{
    if(pilha->topo){
        elemento * aux;
        aux = pilha->topo;

        while(aux){
            printf("\n\033[4m %d \033[m", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\n pilha vazia");
    }

    printf("\n");

}

int escolhe_opcao()
{
    int opcao;

    printf("\n1 - push");
    printf("\n2 - pop");
    printf("\n3 - stackpop");
    printf("\n4 - mostra");
    printf("\n0 - sair");
    printf("\nopcao> ");

    scanf("%d", &opcao);

    return opcao;
}

int stackpop()
{
    if(!empty())
        return pilha->topo->valor;
    else
        return -1;
}

bool empty()
{
    if(pilha->topo == NULL)
        return True;
    else
        return False;
}

int pop()
{
    if(!empty()){
        elemento * aux;
        aux = pilha->topo;
        
        int num = aux->valor;
        
        pilha->topo = aux->prox;
        free(aux);

        return num;
    }else{
        return -1;
    }
}

void push(int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(pilha->topo != NULL){
        novo->prox = pilha->topo;
        pilha->topo = novo;
    }else{
        pilha->topo = novo;
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

stack * aloca_pilha()
{
    stack * nova;

    nova = (stack*)malloc(sizeof(stack));
    nova->topo = NULL;

    return nova;
}