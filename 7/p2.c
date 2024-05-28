#include<stdio.h>
#include<stdlib.h>

void spausdinti_masyva(int x, int y, int** mas){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
    
}

void sukurti_masyva(int *x, int *y, int*** mas){
    printf("Kokio didumo matrica?: ");
    scanf("%d \n %d", x, y);

    *mas = (int**)malloc(*x * sizeof(int*));
    for (int i = 0; i < *x; i++)
    {
        (*mas)[i] = (int*)malloc(*y * sizeof(int));
    }
}

void pildyti_masyva(int x, int y, int **mas){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            mas[i][j] = rand() & 100;
        }   
    }
    printf("Pradinis masyvas:\n");
    spausdinti_masyva(x, y, mas);
}

void transponuoti(int *x, int *y, int ***mas){
    int **mas_naujas = (int**)malloc(*y * sizeof(int*));
    for (int i = 0; i < *y; i++)
    {
        mas_naujas[i] = (int*)malloc(*x * sizeof(int));
    }

    for (int i = 0; i < *x; i++)
    {
        for (int j = 0; j < *y; j++)
        {
            mas_naujas[j][i] = (*mas)[i][j];
        }      
    }

    *mas = mas_naujas;

    int tmp = *x;
    *x = *y;
    *y = tmp;   
}

int main(){
    int x, y;
    int** mas;
    sukurti_masyva(&x, &y, &mas);
    pildyti_masyva(x, y, mas);

    transponuoti(&x, &y, &mas);

    printf("Naujas masyvas:\n");
    spausdinti_masyva(x, y, mas); 
}