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
//funcoes >>>>>>>>>>>>>>>>>>>>>
int escolhe_opcao();
void cadastra_pessoa(lista *l);
pessoa * aloca_pessoa();
void mostra_pessoas(lista *l);
//funcoes >>>>>>>>>>>>>>>>>>>>>

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
            mostra_pessoas(grupo);
        }else if(opcao == 3){
            break;
        }else{
            printf("\nOpcao Invalida\n");
        }
    }

    return 0;
}

void mostra_pessoas(lista *l)
{
    if(l->inicio){
        pessoa *aux;

        aux = l->inicio;

        while(aux)
        {
            printf("\nNome: %s\n", aux->nome);
            printf("Idade: %d\n", aux->idade);
            printf("Peso: %.2f\n", aux->peso);
            aux = aux->prox;
        }

    }else{
        printf("\nLista Vazia\n");
    }
}

pessoa * aloca_pessoa()
{
    pessoa *nova;

    nova = (pessoa*)malloc(sizeof(pessoa));

    fflush(stdin);
    printf("Nome: ");
    scanf("%s", nova->nome);

    printf("Idade: ");
    scanf("%d", &nova->idade);

    printf("Peso: ");
    scanf("%f", &nova->peso);

    nova->prox = NULL;

    return nova;
}

void cadastra_pessoa(lista *l)
{
    pessoa *nova;

    nova = aloca_pessoa();

    if(l->inicio){
        pessoa * aux;

        aux = l->inicio;

        while(aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = nova;
    }else{
        l->inicio = nova;
    }

    l->qtd += 1;

}

int escolhe_opcao()
{
    int opcao;
    printf("\n1 - Cadastrar Pessoa\n");
    printf("2 - Mostrar Pessoas\n");
    printf("3 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}