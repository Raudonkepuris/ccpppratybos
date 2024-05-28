#include<stdio.h>

int main(){
    float e;
    scanf("%f", &e);

    float sum = 0;
    int n = 1;
    while (1 - sum > e)
    {
        sum += 1 / (double)(1 << n);
        n++;
    }

    printf("Norimas tikslumas buvo pasiektas po %d kartu, suma = %f\n", n, sum);   
}