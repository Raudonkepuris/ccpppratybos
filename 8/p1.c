#include<stdlib.h>
#include<stdio.h>

int teigiamu_elementu_sk(int n, int mas[]){
    int sk = 0;
    for (int i = 0; i < n; i++)
    {
        if(mas[i] > 0){
            sk++;
        }
    }
    return sk;
}

int main(){
    int n = rand() % (15 - 10 + 1) + 10;
    int *mas = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % (50 - (-50) + 1) + (-50);
    }

    int m = teigiamu_elementu_sk(n, mas);

    int *teig_mas = (int*)malloc(m * sizeof(int)); 

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if(mas[i] > 0){
            teig_mas[x] = mas[i];
            x++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");

    for (int i = 0; i < m; i++)
    {
        printf("%d ", teig_mas[i]);
    }
    printf("\n");
    
}