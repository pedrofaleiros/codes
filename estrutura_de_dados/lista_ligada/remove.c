#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista
{
    int qtd;
    struct elemento * inicio;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void inclui_elemento(lista *l, int num);
void mostra_lista(lista *l);

int main()
{
    lista *numeros;
    int num, opcao = 1;

    numeros = aloca_lista();

    while(opcao != 0)
    {
        printf("1 - Cadastra\n2 - Mostra\n3 - remove\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Incluir numero: ");
                scanf("%d", &num);
                inclui_elemento(numeros, num);
                break;
            case 2:
                mostra_lista(numeros);
                break;
            case 3:
                break;
            default:
                break;
        }

    }

    return 0;
}

void mostra_lista(lista *l)
{
    if(l->inicio){
        pessoa *aux;

        aux = l->inicio;

        while(aux)
        {
            printf(">%d\n", aux->valor);
            aux = aux->prox;
        }

    }else{
        printf("\nLista Vazia\n");
    }
}

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox == NULL;

    return novo;
}

void inclui_elemento(lista *l, int num)
{
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = novo;
    }else{
        l->inicio = novo;
    }

    l->qtd += 1;
}

lista * aloca_lista()
{
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}