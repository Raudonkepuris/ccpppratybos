#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool dalijamas(int K, int i){
    return K % i == 0;
}

int main(){
    int K;
    scanf("%d", &K);
    printf("%d dalijasi is : ", K);
    for (int i = 1; i < (K / 2) + 1; i++)
    {
        if(dalijamas(K, i)){
            printf("%d ", i);
        }
    }
    printf("\n");

    
}