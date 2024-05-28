#include<stdio.h>

int main(){
    int pv, pm, i, v, m;
    printf("Ivesti isvykimo laika v m ir po kiek laiko sustojo\n");
    scanf("%d \n %d \n %d", &pv, &pm, &i);
    if (pv > 24 || pm > 60)
    {
        printf("Toks laikas neegzistuoja\n");
        return 0;
    }
    m = (pm + i) % 60;
    v = (((pm + i) / 60) + pv) % 24;
    printf("%d : %d\n", v, m);
}