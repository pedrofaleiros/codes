#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct pessoa *inicio;
}lista;

typedef struct pessoa{
    char nome[30];
    int idade;
    float peso;
    struct pessoa *prox;
}pessoa;

int opcao();

int main()
{
    lista *grupo;
    int opcao = 1;

    //aloca lista
    grupo = (lista*)malloc(sizeof(lista));
    grupo->qtd = 0;
    grupo->inicio = NULL;

    while(1)
    {
        opcao = escolhe_opcao();

        if(opcao == 1){
            cadastra_pessoa(grupo);
        }else if(opcao == 2){

        }else if(opcao == 3){

        }else{
            printf("\nOpcao INvalida\n");
        }



    }


    return 0;
}



int opcao()
{
    int opcao;
    printf("1 - Cadastrar Pessoa\n");
    printf("2 - Mostrar Pessoas\n");
    printf("3 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}