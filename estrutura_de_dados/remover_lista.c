#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento * inicio;

}lista; 


typedef struct elemento{
    int valor;
    struct elemento * prox;

}elemento;

// funcoes <<<<<<<<<<<<<<<<<<<<<<<<<
void inclui_elemento(lista *l, int x);
void mostra_elementos(lista *l);
elemento* aloca_elemento();
void remove_elemento(lista *l, int num);

// funcoes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main()
{
    lista * numeros;

    numeros = (lista*)malloc(sizeof(lista));
    numeros->qtd = 0;
    numeros->inicio = NULL;

    int opcao = 1, num;
    while(opcao != 0){
        printf("\n1 - cadastra\n2 - mostra\n3 - remove\nopcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Num: ");
            scanf("%d", &num);
            inclui_elemento(numeros, num);
        }else if(opcao == 2){
            mostra_elementos(numeros);
        }else if(opcao == 3){
            printf("remover numero: ");
            scanf("%d", &num);
            remove_elemento(numeros, num);
        }
    }



    return 0;
}

void remove_elemento(lista *l, int num)
{
    
    

}

elemento* aloca_elemento()
{
    elemento *novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

void mostra_elementos(lista *l)
{
    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux)
        {
            printf("> %d\n", aux->valor);
            aux = aux->prox;
        }

    }else{
        printf("\tLista vazia\n");
    }
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
