#include <stdio.h>
#include <stdlib.h>

int acc = 0;
int ip = 0;

int mem[100];

void read(int pos){ // 10
    int num;

    scanf("%d", &num);

    mem[pos] = num;
}

void write(int pos){  // 11
    printf("%d", mem[pos]);
}

void load(int pos){  // 20
    acc = mem[pos];
}

void store(int pos){  // 21
    mem[pos] = acc;
}

void add(int pos){  // 30
    acc = acc + mem[pos];
}

void subtract(int pos){  // 31
    acc = acc - mem[pos];
}

void divide(int pos){  // 32
    acc = mem[pos] / acc;
}

void multiply(int pos){  // 33
    acc = acc * mem[pos];
}

void halt(){ // 43
    acc = -9999;
}

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

    while(acc != -9999){

        pos = mem[ip] % 100;

        switch(mem[ip]/100){
            case 10:
                printf("read: ");
                read(pos);
                break;
            case 11:
                printf("write: ");
                write(pos);
                break;
            case 20:
                load(pos);
                break;
            case 21:
                store(pos);
                break;
            case 30:
                add(pos);
                break;
            case 31:
                subtract(pos);
                break;
            case 32:
                divide(pos);
                break;
            case 33:
                multiply(pos);
                break;
            case 43:
                halt();
                break;
            default:
                halt();
                printf("ERRO");
                break;
        }

        ip++;

    }

    mostra();

    printf("\n");
    return 0;
}

void mostra()
{
    for(int i = 0; i < 100; i++){

        if(i % 10 == 0){
            printf("\n");
        }else{
            printf("\t");
        }

        if(i < 10){
            printf("[0%d] = %d", i, mem[i]);
        }else{
            printf("[%d] = %d", i, mem[i]);
        }

    }
}