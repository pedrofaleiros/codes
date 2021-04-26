/* 
2) Construa uma pilha utilizando uma lista ligada.
Obs. Implemente as operações Push, pop, stackpop e empty.
*/

// pronto
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define True 1
#define False 0

typedef struct pilha{
    int qtd;
    struct elemento * topo;
}pilha;

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

pilha * aloca_pilha();
elemento * aloca_elemento();
void push(pilha * p, int num);
int pop(pilha * p);
int stackpop(pilha * p);
bool empty(pilha * p);
int escolhe_opcao();

int main()
{
    pilha * p;
    p = aloca_pilha();
    
    int opcao = 1, num;

    while(opcao != 0){
        opcao = escolhe_opcao();

        if(opcao == 1){
            printf("\nnumero> ");
            scanf("%d", &num);
            push(p, num);
        }else if(opcao == 2){
            (stackpop(p) == -1) ? printf("\n lista vazia") : printf("\n numero removido: %d", pop(p));
        }else if(opcao == 3){
            (stackpop(p) == -1) ? printf("\n lista vazia") : printf("\n numero do topo: %d", stackpop(p));
        }else if(opcao == 0){
            printf("\n fim");
        }else{
            printf("\n opcao invalida");
        }
    }

    printf("\n");
    return 0;
}

int escolhe_opcao()
{
    int opcao;

    printf("\n1 - push");
    printf("\n2 - pop");
    printf("\n3 - stackpop");
    printf("\n0 - sair");
    printf("\nopcao: ");

    scanf("%d", &opcao);

    return opcao;
}

int stackpop(pilha * p)
{
    if(!empty(p))
        return p->topo->valor;
    else
        return -1;
}

bool empty(pilha * p)
{
    if(p->topo == NULL)
        return True;
    else
        return False;
}

int pop(pilha * p)
{
    if(!empty(p)){
        elemento * aux;
        aux = p->topo;
        
        int num = aux->valor;
        
        p->topo = aux->prox;
        free(aux);

        return num;
    }else{
        return -1;
    }
}

void push(pilha * p, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(p->topo != NULL){
        novo->prox = p->topo;
        p->topo = novo;
    }else{
        p->topo = novo;
    }
    p->qtd++;
}

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

pilha * aloca_pilha()
{
    pilha * nova;

    nova = (pilha*)malloc(sizeof(pilha));
    nova->topo = NULL;
    nova->qtd = 0;

    return nova;
}