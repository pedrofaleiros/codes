#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

typedef struct elemento{
    int valor;
    struct elemento * ant;
    struct elemento * prox;
}elemento;

lista * aloca_lista();
void inclui_elemento(lista *l, int num);
void mostra_lista(lista *l);
elemento * aloca_elemento();

int main()
{
    lista *numeros;
    int opcao = 1, num;

    numeros = aloca_lista();

    while(opcao != 0)
    {
        printf("1 - Inclui || 2 - Mostra || 0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Numero: ");
            scanf("%d", &num);
            inclui_elemento(numeros, num);   
        }else if(opcao == 2){
            mostra_lista(numeros);
        }
    }

    return 0;
}

elemento * aloca_elemento()
{
    elemento *novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

void mostra_lista(lista *l)
{
    if(l->inicio){
        elemento *aux;

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

void inclui_elemento(lista *l, int num)
{
    elemento *novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = novo;
        novo->ant = aux;        

    }else{
        l->inicio = novo;
    }

    l->qtd += 1;
}

lista * aloca_lista()
{
    lista *nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}