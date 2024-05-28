#include<stdio.h>
#include<stdlib.h>

int main(){
    double d1, d2, d3;
    double *pd1, *pd2, *pd3;
    pd1 = &d1;
    pd2 = &d2;
    pd3 = &d3;
    *pd1 = (double)rand() / (double)(RAND_MAX) * 10;
    *pd2 = (double)rand() / (double)(RAND_MAX) * 10;
    *pd3 = (double)rand() / (double)(RAND_MAX) * 10;
    printf("%f, %f, %f\n", d1, d2, d3);
}