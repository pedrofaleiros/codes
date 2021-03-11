#include <stdio.h>

int main(){

    int i = 0;
    ENQUANTO:{
        printf("%d\n", i);
        i += 1;
    }
    if(i < 10){
        goto ENQUANTO;
    }

    return 0;
}
