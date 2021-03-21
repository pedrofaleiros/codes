#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

elemento * aloca_elemento();
lista * aloca_lista();
void inclui_elemento(lista * l, int num);
void mostra_elementos(lista *l);
int mostra_um_elemento(lista *l, int num);

int main(){

    lista * l1;
    int num = 1;

    l1 = aloca_lista();

    while(num){
        printf("Numero: ");
        scanf("%d", &num);

        if(num){
            int n;
            n = (num%10);
            inclui_elemento(l1, n);
        }
    }

    int total;
    for(int i = 0; i < 10; i++){
        total = mostra_um_elemento(l1, i);
        printf("\n%d >>> %d vezes", i, total);
    }

    printf("\n");
    
    return 0;
}

int mostra_um_elemento(lista *l, int num)
{
    int total = 0;
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            if(aux->valor == num){
                total += 1;
            }
            aux = aux->prox;
        }

    }

    return total;
}

void mostra_elementos(lista *l)
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

void inclui_elemento(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux, * ant;

        aux = l->inicio;
        ant = NULL;

        while(aux){
            if(aux->valor > num){
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
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}