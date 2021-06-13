#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node * esquerda;
    struct node * direita;
}node;

node * inclui(node * no, int num)
{
    if(no == NULL){
        node * novo;
        novo = (node*)malloc(sizeof(node));
        novo->valor = num;
        novo->esquerda = NULL; 
        novo->direita = NULL;
        return novo;
    }else{
        if(num > no->valor){
            no->direita = inclui(no->direita, num);
        }else{
            no->esquerda = inclui(no->esquerda, num);
        }
    }
    return no;
}

void mostra(node * no)
{
    if(no != NULL){
        printf(" %d", no->valor);
        mostra(no->esquerda);
        mostra(no->direita);
    }
}

node * aloca_arvore()
{
    return NULL;
}

int main()
{
    node * raiz;

    raiz = aloca_arvore();

    raiz = inclui(raiz, 10);
    raiz = inclui(raiz, 5);
    raiz = inclui(raiz, 15);
    raiz = inclui(raiz, 25);
    raiz = inclui(raiz, 1);
    raiz = inclui(raiz, 11);

    mostra(raiz);

    printf("\n");
    return 0;
}