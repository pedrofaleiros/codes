#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int topo = 0;
int pilha[TAM];

int stackpop();
int empty();
void push(int num);
int pop();
int main()
{
    int opcao = 1, num;

    while(opcao){
        printf("\n1 - pop");
        printf("\n2 - push");
        printf("\n3 - stackpop");
        printf("\n0 - sair");
        printf("\nOpcao: ");

        scanf("%d", &opcao);

        if(opcao == 1){
            num = pop();
        }else if(opcao == 2){
            printf("\nnumero: ");
            scanf("%d", &num);
            push(num);
        }else if(opcao == 3){
            num = stackpop();
            if(num)
                printf("\nTopo: %d", num);
        }
    }

    return 0;
}

int pop()
{
    if(!empty()){
        topo--;
        return pilha[topo];
    }else{
        printf("\npilha vazia\n");
        return -1;
    }
}

void push(int num)
{
    if(topo < TAM){
        pilha[topo] = num;
        topo++;
    }else
        printf("\npilha cheia");
}

int empty()
{
    if(topo == 0)
        return 1;
    else    
        return 0;
}

int stackpop()
{
    if(!empty())
        return pilha[topo - 1];
    else{
        printf("\npilha vazia");
        return 0;
    }
}