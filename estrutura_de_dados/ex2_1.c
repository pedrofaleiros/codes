#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int valor;
    struct element *prox;
}element;

typedef struct list{
    int qtd;
    struct element * inicio;
}list;

int escolhe_opcao();
int escolhe_numero();
list * aloca_lista();
element * aloca_elemento();
void inclui_elemento(list *l, int x);
void mostra_elementos(list *l);
void mostra_pares(list *l);

int main(){

    list *numeros;
    int opcao = 1, num;

    numeros = aloca_lista();

    while(opcao != 0)
    {
        opcao = escolhe_opcao();

        if(opcao == 1){
            num = escolhe_numero();
            inclui_elemento(numeros, num);
        }else if(opcao == 2){
            mostra_elementos(numeros);
        }else if(opcao == 3){
            mostra_pares(numeros);
        }
    }

    //printf("elemento: %d\n", numeros->inicio->prox->prox->valor);

    return 0;
}

void mostra_pares(list *l)
{
    if(l->inicio)
    {
        element *aux;
        int tem_par = 0;

        aux = l->inicio;

        while(aux)
        {
            if(aux->valor % 2 == 0){
                if(!tem_par){
                    printf("\nNumeros Pares:\n");
                }
                printf("> %d\n", aux->valor);
                tem_par = 1;
            }
            aux = aux->prox;
        }

        if(!tem_par){
            printf("\nNenhum numero par\n");
        }

        printf("\n");

    }else{
        printf("\nLista vazia\n\n");
    }
}

void mostra_elementos(list *l)
{
    if(l->inicio)
    {
        element *aux;

        aux = l->inicio;

        printf("\nNumeros:\n");
        while(aux)
        {
            printf("> %d\n", aux->valor);
            aux = aux->prox;
        }
        printf("\n");

    }else{
        printf("\nLista vazia\n\n");
    }
}

element * aloca_elemento()
{
    element *novo;

    novo = (element*)malloc(sizeof(element));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

void inclui_elemento(list *l, int x)
{
    element *novo;
    novo = aloca_elemento();
    novo->valor = x;

    if(l->inicio)
    {
        element * aux;
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

list * aloca_lista()
{
    list *nova_lista;

    nova_lista = (list*)malloc(sizeof(list));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;

    return nova_lista;
}

int escolhe_opcao()
{
    int opcao;

    printf("1 - Incluir Elemento\n");
    printf("2 - Mostrar Elementos\n");
    printf("3 - Mostrar Pares\n");
    printf("0 - Sair\nOpcao: ");

    scanf("%d", &opcao);

    return opcao;
}

int escolhe_numero()
{
    int numero;

    printf("Numero: ");
    scanf("%d", &numero);

    return numero;
}
