#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct pilha{
    struct elemento * topo;
}pilha;

elemento * aloca_elemento();
pilha * aloca_pilha();
void inclui_elemento(pilha * p, int num);
int remove_elemento(pilha * p);

class Pilha{
    private:
        pilha * p;

    public:

        Pilha(){
            p = aloca_pilha();
        }
        int empty(){
            if(p->topo == NULL)
                return 1;
            else
                return 0;
        }
        void push(int num = 0){
            inclui_elemento(p, num);
        }
        int pop(){
            if(!empty()){
                return remove_elemento(p);
            }else{
                return -1;
            }
        }
        int stackpop(){
            if(!empty())
                return p->topo->valor;
            else
                return -1;
        }
        void mostra(){
            if(!empty()){
                elemento * aux;
                aux = p->topo;

                while(aux){
                    printf("\n> %d", aux->valor);
                    aux = aux->prox;
                }
            }else{
                printf("\n pilha vazia");
            }
        }
};

int main()
{
    Pilha mystack;

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    mystack.push(6);

    mystack.pop();
    mystack.pop();

    mystack.mostra();

    printf("\n");
    return 0;
}

int remove_elemento(pilha * p)
{
    if(p->topo){
        elemento * aux;
        int num;
        
        aux = p->topo;
        num = aux->valor;

        p->topo = p->topo->prox;

        delete aux;

        return num;
    }else{
        return -1;
    }
}

void inclui_elemento(pilha * p, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(p->topo){
        novo->prox = p->topo;
    }

    p->topo = novo;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;
}

pilha * aloca_pilha()
{
    pilha * nova;
    nova = (pilha*)calloc(1, sizeof(pilha));
    return nova;
}