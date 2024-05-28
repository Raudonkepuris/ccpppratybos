#include<stdio.h>
#include<stdlib.h>

void rasti(int n, int mas[], int *min, int *max){
    *min = mas[0];
    *max = mas[0];
    for (int i = 1; i < n; i++)
    {
        if(*min > mas[i]){
            *min = mas[i];
        }
        if(*max < mas[i]){
            *max = mas[i];
        }
    }
    
}

int main(){
    int min, max;

    int N;
    scanf("%d", &N);

    int *mas = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        mas[i] = rand() % (100 - (-100) + 1) + (-100);
        printf("%d ", mas[i]);
    }
    printf("\n");

    rasti(N, mas, &min, &max);

    printf("%d, %d\n", min, max);   

    free(mas);

    return 0;
}