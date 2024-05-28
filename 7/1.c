#include<stdio.h>

void keisti(int *x1, int *x2){
    int tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}

int main(){
    int a = 7, b = 5, c = 14;
    int *pa = &a, *pb = &b, *pc = &c;
    keisti(pb, pa);
    keisti(pc, pb);
    keisti(pa, pc);
    int *rod_mas[] = {pa, pb, pc};
    for (int i = 0; i < 3; i++)
    {
        printf("%d, ", *rod_mas[i]);
    }
    printf("\n");
    
}