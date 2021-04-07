#include <stdio.h>
#include <stdlib.h>

typedef struct e{
    int valor;
    struct e * prox;
}e;

typedef struct lista{
    int qtd;
    struct e * inicio;
}lista;

void inclui(lista * l, int num);
int perfect(int num);

int main() 
{
    int i, num;
    
    num = 100000;
    
    printf("\n perfect numbers:");
    for(i = 1; i <= num; i++){
        if(perfect(i))
            printf("\n > %d", i);
    }


    return 0;
}

void inclui(lista * l, int num)
{
    e * novo;
    
    novo = (e*)calloc(1, sizeof(e));
    novo->valor = num;
    
    if(l->inicio){
        e * aux;
        aux = l->inicio;
        
        while(aux->prox){
            aux = aux->prox;
        }
        
        aux->prox = novo;
    }else{
        l->inicio = novo;
    }
    l->qtd++;
}

int perfect(int num)
{
    lista * l;
    
    l = (lista*)calloc(1, sizeof(lista));
    
    for(int i = 1; i < num; i++){
        if(num % i == 0){
            inclui(l, i);
        }
    }
    
    e * aux;
    int soma = 0;
    
    aux = l->inicio;
    
    
    while(aux){
        soma += aux->valor;
        aux = aux->prox;
    }
    
    if(soma == num)
        return 1;
        
    return 0;
}
