#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

float vidurkis(int mas[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += mas[i];
    }
    return (float)sum / n;
}

int verte_artimiausia_vidurkiui(int mas[], int n, float vidurkis){
    int artimiausio_ind = 0;
    float maziausias_skirtumas = FLT_MAX;
    float skirtumas;
    for(int i = 0; i < n; i++){
        skirtumas = fabs(vidurkis - mas[i]);
        if(skirtumas < maziausias_skirtumas){
            maziausias_skirtumas = skirtumas;
            artimiausio_ind = i;
        }
    }
    return artimiausio_ind;
}

void uzpildyti_masyva(int mas_org[], int n_org, float mas[], int *n, float vidurkis){
    *n = 0;
    for (int i = 0; i < n_org; i++)
    {
        if(mas_org[i] < vidurkis){
            mas[*n] = mas_org[i];
            ++*n;
        }
    }    

    int i, j;
    bool pakeista = 0;
    for (i = 0; i < *n-1; i++)
    {
        pakeista = 0;
        for(j = 0; j < *n - i - 1; j++){
            if(mas[j] < mas[j+1]){
                float temp = mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;
                pakeista = 1;
            }
        }
        if(pakeista == 0){
            break;
        }
    }
}

int main(){
    int n = 10;
    int mas[10] = {4, 2, 5, 2, -10};
    int random;
    for(int i = 5; i < 10; i++){
        random = rand() % 21 + 10;
        mas[i] = random;
    }
    for(int i = 0; i < 10; i++){
        printf("[%d] : %d\n", i, mas[i]);
    }
    float vid = vidurkis(mas, n);
    printf("Vidurkis = %2.f\n", vid);
    int artimiausio_ind = verte_artimiausia_vidurkiui(mas, n, vid);
    printf("Artimiausio indeksas [%d] : %d\n", artimiausio_ind, mas[artimiausio_ind]);
    int n2 = 0;
    float mas2[10] = {0};
    uzpildyti_masyva(mas, n, mas2, &n2, vid);
    for (int i = 0; i < n2; i++)
    {
        printf("%.2f\n", mas2[i]);
    }
}