/* 
3) Faça um programa que leia do usuário um número N inteiro positivo e solicite ao usuário N números para serem armazenados.
    a primeira metade dos N números, deverá ser armazenada em uma lista ligada e a segunda metade dos N números deverá ser 
    armazenado em uma segunda lista.
    Mostre na tela quais valores são comuns entre as 2 listas ligadas.
*/

// pronto
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento *inicio;
}lista;

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemento;

lista* aloca_lista();
elemento* aloca_elemento();
void inclui_elemento(lista *l, int x);
void mostra_valores_iguais(lista *l1, lista *l2);

int main()
{
    int n, i, x;
    lista *lista1, *lista2;

    lista1 = aloca_lista();
    lista2 = aloca_lista();

    printf("Numero N: ");
    scanf("%d", &n);

    float num = n;

    for(i = 0;i < n; i++)
    {
        printf("Numero: ");
        scanf("%d", &x);

        if(i < num/2){
            inclui_elemento(lista1, x);
        }else{
            inclui_elemento(lista2, x);
        }
    }

    mostra_valores_iguais(lista1, lista2);

    return 0;
}

void mostra_valores_iguais(lista *l1, lista *l2)
{
    int achou_igual = 0;

    printf("\nNumeros em comum:\n");
    if(l1->inicio && l2->inicio){
        elemento *aux1, *aux2;

        aux1 = l1->inicio;

        while(aux1)
        {
            aux2 = l2->inicio;
            while(aux2)
            {
                if(aux1->valor == aux2->valor)
                {
                    printf("> %d\n", aux1->valor);
                    achou_igual = 1;
                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }

        if(!achou_igual){
            printf("\nNenhum elemento em comum\n");
        }
    }else{
        printf("\nLista esta vazia\n");
    }

}

lista* aloca_lista()
{
    lista *nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}

elemento* aloca_elemento()
{
    elemento *novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

void inclui_elemento(lista *l, int x)
{
    elemento *novo;

    novo = aloca_elemento();

    novo->valor = x;

    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }else{
        l->inicio = novo; 
    }

    l->qtd += 1;
}