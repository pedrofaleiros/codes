/* 
4) Ajuste a solução do exercício 3 para que a pesquisa de números em comuns seja feita utilizando o algoritmo Balance-Line.
    Dicas: A inserção na lista precisa ser ordenada!
*/
/*
3) Faça um programa que leia do usuário um número N inteiro positivo
    e solicite ao usuário N números para serem armazenados.
    a primeira metade dos N números, deverá ser armazenada em uma lista ligada 
    e a segunda metade dos N números deverá ser armazenado em uma segunda lista.
    Mostre na tela quais valores são comuns entre as 2 listas ligadas.
*/
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
void inclui_elemento(lista *l, int num);
void mostra_valores_iguais(lista *l1, lista *l2);

int main()
{
    int n, i = 0, x;
    lista *lista1, *lista2;

    lista1 = aloca_lista();
    lista2 = aloca_lista();

    printf("Numero N: ");
    scanf("%d", &n);

    float num = n;
    
    for(;i < n; i++)
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
    if(l1->inicio && l2->inicio){
        elemento *aux = NULL, *aux2 = NULL;
        int achou = 0;

        aux = l1->inicio;
        aux2 = l2->inicio;

        while(aux && aux2){
            if(aux->valor == aux2->valor){
                achou = 1;
                printf("> %d\n", aux->valor);
                aux2 = aux2->prox;
                aux = aux->prox;
            }else if(aux->valor > aux2->valor){
                aux2 = aux2->prox;
            }else{
                aux = aux->prox;
            }
            
        }

        if(!achou){
            printf("\nNenhum valor em comum\n");
        }


    }else{
        printf("\nLista vaia\n");
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
        //return;
    }else{
        l->inicio = novo;
        l->qtd += 1;
        //return;
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

