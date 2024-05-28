#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void spausdinti(int mas[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d; ", mas[i]);
    }
    printf("\n");
}

void generuoti(int mas[], int n){
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % (21) - 10;
    }
}

void perkelti_neigiamus(int mas[], int n){
    int pirm = 0;
    int pask = n;
    bool pakeitimas = false;

    for (int i = 0; i < n; i++)
    {
        if(mas[i] < 0){
            pakeitimas = false;
            int temp = mas[i];
            for(int j = pask-1; j >= i; j--){
                if(mas[j] >= 0){
                    mas[i] = mas[j];
                    mas[j] = temp;
                    pask = j;
                    pakeitimas = true;
                    break;
                }
            }
            if (!pakeitimas){
                break;
            }
        }
    }
    
}

void tikrinti(int mas[], int n){
    bool buvo_neigiamas = false;
    for (int i = 0; i < n; i++)
    {
        if(mas[i] < 0){
            buvo_neigiamas = true;
        }
        if(mas[i] >= 0 && buvo_neigiamas){
            printf("klaida\n");
        }
    }
    
}

int main(){
    int n = 20;
    int mas[20];
    generuoti(mas, n);
    spausdinti(mas, n);
    perkelti_neigiamus(mas, n);
    spausdinti(mas, n);
    // tikrinti(mas, n);
}