#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento *inicio;
}lista;

int escolhe_opcao();
lista * aloca_lista();
elemento * aloca_elemento();
void inclui_elemento(lista *l, int num);
void mostra_lista(lista *l);
void remove_elemento(lista *l, int num);
void mostra_igual(lista *l, int n);

int main(){

    lista *l;
    int num, opcao = 1;

    l = aloca_lista();

    while(opcao != 0)
    {
        opcao = escolhe_opcao();

        switch(opcao){
            case 1:
                printf("Qual numero inserir? ");
                scanf("%d", &num);
                inclui_elemento(l, num);
                break;
            case 2:
                mostra_lista(l);
                break;
            case 3:
                printf("Qual numero remover? ");
                scanf("%d", &num);
                remove_elemento(l, num);
                break;
            default:
                break;
        }
    }

    return 0;
}

void remove_elemento(lista *l, int num)
{
    if(l->inicio){
        elemento *aux, *ant = NULL;
        int achou = 0;

        aux = l->inicio;

        while(aux){
            if(aux->valor == num){
                if(ant){
                    ant->prox = aux->prox;
                }else{
                    l->inicio = aux->prox;
                }
                l->qtd -= 1;
                achou = 1;
                aux = NULL;
            }else{
                /* if(ant){
                    ant = ant->prox;
                }else{
                    ant = aux;
                } */
                ant = aux;
                aux = aux->prox;
            }
        }

        if(!achou){
            printf("\nElemento nao esta na lista\n");
        }

    }else{
        printf("\nLista vazia\n");
    }
}

void inclui_elemento(lista *l, int num)
{
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento *aux = NULL, *ant = NULL;
        aux = l->inicio;

        while(aux){
            if(aux->valor > num){
                if(ant){
                    ant->prox = novo;
                }else{
                    l->inicio = novo;
                }
                novo->prox = aux;
                l->qtd += 1;
                return;
            }else{
                /* if(ant){
                    ant = ant->prox;
                }else{
                    ant = aux;
                } */
                ant = aux;
                aux = aux->prox;
            }
        }

        ant->prox = novo;
        l->qtd += 1;
        return;
    }else{
        l->inicio = novo;
        l->qtd += 1;
        return;
    }
}

void mostra_lista(lista *l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        printf("\nElementos:\n");
        while(aux){
            printf("> %d\n", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\nLista vazia\n");
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
    lista *nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}

int escolhe_opcao()
{
    int opcao;

    printf("\n1 - Inserir Numero\n");
    printf("2 - Mostrar Lista\n");
    printf("3 - Remover Elemento\n");
    printf("opcao: ");

    scanf("%d", &opcao);

    return opcao;
}