#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

int escolhe_opcao()
{
    int opcao;

    printf("\n1 - Inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("0 - sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

elemento * aloca_elemento()
{
    elemento *novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

void remove_elemento(elemento *l, int num)
{
    if(l->prox){
        elemento *aux, *ant = NULL;
        int achou = False;

        aux = l->prox;

        while(aux){
            if(aux->valor == num){
                achou = True;
                if(ant){
                    ant->prox = aux->prox;
                }else{
                    l->prox = aux->prox;
                }
                aux = NULL;
            }else{
                ant = aux;
                aux = aux->prox;
            }
        }
    }else{
        printf("\nLista vazia\n");
    }
}

void mostra_elementos(elemento *l)
{
    if(l->prox){
        elemento *aux;

        aux = l->prox;

        printf("\nElementos:\n");
        while(aux){
            printf("> %d\n", aux->valor);
            aux = aux->prox;
        }        

    }else{
        printf("\nLista vazia\n");
    }
}


void insere_elemento(elemento * l, int num)
{
    elemento *novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->prox){
        elemento * aux;

        aux = l->prox;

        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = novo;
    }else{
        l->prox = novo;
    }
}

int main(){

    elemento *lista;
    lista->prox = NULL;

    int num, opcao = 1;

    while(opcao != 0){
        opcao = escolhe_opcao();

        if(opcao == 1){
            printf("Qual numero inserir? ");
            scanf("%d", &num);
            insere_elemento(lista, num);
        }else if(opcao == 2){
            mostra_elementos(lista);
        }else if(opcao == 3){
            printf("Qual numero remover? ");
            scanf("%d", &num);
            remove_elemento(lista, num);
        }

    }

    return 0;
}