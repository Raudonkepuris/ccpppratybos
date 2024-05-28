#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void pildyti(double mas[], int n){
    for (int i = 0; i < n; i++)
    {
        mas[i] = (double)rand() / (double)(RAND_MAX);
    }
}

void artimiausias(double mas[], int n, double ieskomas, int *indeksas){
    double artimiausias = fabs(mas[0] - ieskomas);
    *indeksas = 0;
    for (int i = 1; i < n; i++)
    {
        if(fabs(mas[i] - ieskomas) < artimiausias){
            artimiausias = mas[i];
            *indeksas = i;
        }
    }
}

void masyvo_informacija(double mas[], int n){
    double *rod = mas;
    for (int i = 0; i < n; i++)
    {
        printf("%d %f %p\n", i, *rod, rod);
        rod++;
    }
}

int main(){
    double n = 10;
    double mas[10];

    pildyti(mas, n);

    int indeksas = 0;
    artimiausias(mas, n, 0.5, &indeksas);

    masyvo_informacija(mas, n);
}