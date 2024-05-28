#include<stdio.h>
#include<stdlib.h>

void spausdinti_masyva(int n, int** mas){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
    
}

void sukurti_masyva(int *n, int*** mas){
    printf("Kokio didumo matrica?: ");
    scanf("%d", n);

    *mas = (int**)malloc(*n * sizeof(int*));
    for (int i = 0; i < *n; i++)
    {
        (*mas)[i] = (int*)malloc(*n * sizeof(int));
    }
}

void pildyti_masyva(int n, int** mas){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] = rand() & 100;
        }   
    }
    printf("Pradinis masyvas:\n");
    spausdinti_masyva(n, mas);
}

void keisti(int n, int** mas){
    int x, y;
    printf("Parasyti, kurias eilutes sukeisti: \n");
    scanf("%d \n %d", &x, &y);
    if(x >= n || y >= n || x < 0 || y < 0){
        printf("Blogai ivesti eiluciu skaiciai\n");
        return;
    }
    int *tmp = mas[x];
    mas[x] = mas[y];
    mas[y] = tmp;
}

int main(){
    int n;
    int** mas;
    sukurti_masyva(&n, &mas);
    pildyti_masyva(n, mas);
    keisti(n, mas);
    printf("Naujas masyvas:\n");
    spausdinti_masyva(n, mas); 
    
    for (int i = 0; i < n; i++)
    {
        free(mas[i]);
    }
    free(mas);
}