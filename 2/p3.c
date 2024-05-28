#include<stdio.h>
#include<math.h>

int main(){
    float a, b, c;
    float S_trap, pus_per, S_trik, santykis;
    printf("Ivesti a, b, c:\n");
    scanf("%f \n %f \n %f", &a, &b, &c);

    if(!(a + b > c && a + c > b && b + c > a)){
        printf("Toks trikampis yra negalimas\n");
        return 0;
    }

    S_trap = (a + b) / 2 * c;
    pus_per = (a + b + c) / 2;
    S_trik = sqrt(pus_per * (pus_per - a) * (pus_per - b) * (pus_per - c));
    santykis = S_trap / S_trik;
    printf("Trapecijos su pagrindais %f, %f ir aukstine %f, plotas S = %.3f\n", a, b, c, S_trap);
    printf("Ivairiakrascio trikampio krastinemis %f, %f ir %f, plotas S = %.2f\n", a, b, c, S_trik);
    printf("Trapecijos ploto ir trikampio ploto santykis %.2f\n", santykis);
}