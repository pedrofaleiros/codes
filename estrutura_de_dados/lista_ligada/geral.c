#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1

typedef struct elemento{
    int numero;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

int escolhe_opcao();
elemento * aloca_elemento();
lista * aloca_lista();
void inclui_elemento(lista *l);
void mostra_elementos(lista *l);
void remove_elemento(lista *l);

int main(){

    lista * numeros;

    numeros = aloca_lista();

    void (*funcao[3])(lista *);
    funcao[0] = inclui_elemento;
    funcao[1] = mostra_elementos;
    funcao[2] = remove_elemento;

    int opcao = 1, num;
    while(opcao != 0){
        opcao = escolhe_opcao();

        if(opcao > 0 && opcao <= 3){
            funcao[opcao-1](numeros);
        }
    }

    return 0;
}

void remove_elemento(lista *l)
{
    if(l->inicio){
        int num;
        printf("Qual numero remover? ");
        scanf("%d", &num);

        elemento *aux = NULL, *ant = NULL;
        int achou = False;

        aux = l->inicio;
        while(aux){
            if(aux->numero == num){
                achou = True;
                if(ant){
                    ant->prox = aux->prox;
                }else{
                    l->inicio = aux->prox;
                }
                aux = NULL;
            }else{
                ant = aux;
                aux = aux->prox;
            }
        }

        if(achou){
            l->qtd -= 1;
            printf("\nNumero removido\n");
        }else{
            printf("\nNumero nao esta na lista\n");
        }

    }else{
        printf("\nLista vazia\n");
    }

}


void mostra_elementos(lista *l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        printf("\nElementos:\n");

        while(aux){
            printf("> %d\n", aux->numero);
            aux = aux->prox;
        }

    }else{
        printf("\nLista vazia\n");
    }
}

void inclui_elemento(lista *l) // falta melhorar
{
    int num;
    printf("Numero: ");
    scanf("%d", &num);

    elemento * novo;

    novo = aloca_elemento();
    novo->numero = num;

    if(l->inicio){
        elemento *aux = NULL, *ant = NULL;

        aux = l->inicio;
    
        while(aux){
            if(aux->numero > num){
                if(ant){
                    ant->prox = novo;
                    novo->prox = aux;
                }else{
                    l->inicio = novo;
                    novo->prox = aux;
                }
                l->qtd += 1;
                return;
            }else{
                ant = aux;
                aux = aux->prox;
            }
        }

        ant->prox = novo;

    }else{
        l->inicio = novo;
    }

    l->qtd += 1;
    return;
}

int escolhe_opcao()
{
    int opcao;

    printf("\n1 - Incluir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

lista * aloca_lista()
{
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->numero = 0;
    novo->prox = NULL;

    return novo;
}