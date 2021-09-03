#include <stdio.h>
#include <stdlib.h>

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define HALT 43

int acc = 0;
int ip = 0;

int mem[100];

void read(int pos);
void write(int pos);
void load(int pos);
void store(int pos);
void add(int pos);
void subtract(int pos);
void divide(int pos);
void multiply(int pos);
void halt();

void mostra();

int main(){

    int num = 0;

    for(int i = 0; i < 100; i++){
        mem[i] = 0;
    }

    while(num != -9999){
        printf("[%d] ? ", ip);
        scanf("%d", &num);

        if(num != -9999){
            mem[ip] = num;
            ip++;
        }
    }

    int pos;
    ip = 0;

    while(ip >= 0){

        pos = mem[ip] % 100;

        switch(mem[ip]/100){
            case READ:
                printf("read [%d] = ", pos);
                read(pos);
                break;
            case WRITE:
                printf("write [%d] = ", pos);
                write(pos);
                break;
            case LOAD:
                load(pos);
                break;
            case STORE:
                store(pos);
                break;
            case ADD:
                add(pos);
                break;
            case SUBTRACT:
                subtract(pos);
                break;
            case DIVIDE:
                divide(pos);
                break;
            case MULTIPLY:
                multiply(pos);
                break;
            case HALT:
                halt();
                break;
            default:
                halt();
                printf("ERRO\n");
                break;
        }

    }

    mostra();

    printf("\n");
    return 0;
}

void read(int pos)
{
    int num;

    scanf("%d", &num);

    mem[pos] = num;

    ip++;
}


void write(int pos)
{ 
    printf("%d\n", mem[pos]);

    ip++;
}

void load(int pos)
{ 
    acc = mem[pos];

    ip++;
}

void store(int pos)
{ 
    mem[pos] = acc;

    ip++;
}

void add(int pos)
{ 
    acc = acc + mem[pos];

    ip++;
}

void subtract(int pos)
{ 
    acc = acc - mem[pos];

    ip++;
}

void divide(int pos)
{ 
    acc = mem[pos] / acc;

    ip++;
}

void multiply(int pos)
{ 
    acc = acc * mem[pos];

    ip++;
}

void halt()
{
    ip = -1;
}

void mostra()
{
    printf("--------------------------------------------------------------------------------------------\n");
    printf("acc = %d\n", acc);
    printf("ip  = %d\n", ip);

    for(int i = 0; i < 100; i++){

        if(i < 10){
            if(i == 0){
                printf("[0%d] = %d", i, mem[i]);
            }else{
                printf("\t[0%d] = %d", i, mem[i]);
            }
        }else{
            if(i % 10 == 0){
                printf("\n[%d] = %d", i, mem[i]);
            }else{
                printf("\t[%d] = %d", i, mem[i]);
            }
        }
    }
}