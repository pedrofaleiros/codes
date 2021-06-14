#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no * esquerda;
    struct no * direita;
}no;

typedef struct arvore{
    int qtd;
    struct no * raiz;
}arvore;

arvore * aloca_arvore();
no * aloca_no();
void inclui(arvore * a, int num);
void pre_ordem(no * node);
void ordem(no * node);
void pos_ordem(no * node);


int main()
{
    arvore * a;

    a = aloca_arvore();

    inclui(a, 10);
    inclui(a, 5);
    inclui(a, 15);
    inclui(a, 20);
    inclui(a, 1);

    pre_ordem(a->raiz);


    printf("\n");
    return 0;
}

void pre_ordem(no * node)
{
    if(node != NULL){
        printf(" %d", node->valor);
        pre_ordem(node->esquerda);
        pre_ordem(node->direita);
    }
}
void pos_ordem(no * node)
{
    if(node != NULL){
        pos_ordem(node->esquerda);
        pos_ordem(node->direita);
        printf(" %d", node->valor);
    }
}
void ordem(no * node)
{
    if(node != NULL){
        ordem(node->esquerda);
        printf(" %d", node->valor);
        ordem(node->direita);
    }
}

void inclui(arvore * a, int num)
{
    no * novo;

    novo = aloca_no();
    novo->valor = num;

    if(a->raiz == NULL){
        a->raiz = novo;
        a->qtd++;
    }else{
        int incluido = 0;
        no * aux;

        aux = a->raiz;

        while(!incluido)
        {
            if(num > aux->valor){
                if(aux->direita == NULL){
                    aux->direita = novo;
                    incluido = 1;
                }else{
                    aux = aux->direita;
                }
            }else{
                if(aux->esquerda == NULL){
                    aux->esquerda = novo;
                    incluido = 1;
                }else{
                    aux = aux->esquerda;
                }
            }
        }
    }
}

no * aloca_no()
{
    no * novo;
    novo = calloc(1, sizeof(no));
    return novo;
}

arvore * aloca_arvore()
{
    arvore * nova;
    nova = calloc(1, sizeof(arvore));
    return nova;
}