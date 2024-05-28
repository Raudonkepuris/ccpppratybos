#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void rasti_skaicius(int n, char eilute[], int *N, int *skaiciai){
    int sk_m = 0;
    int skaicius = 0;

    *N = 0;

    for (int i = n-1; i >= 0; i--)
    {
        if(isdigit(eilute[i])){
            skaicius += (eilute[i] - '0') * pow(10, sk_m);
            sk_m++;
        }
        if((sk_m > 0 && !isdigit(eilute[i])) || i == 0){
            (*N)++;
            skaiciai = realloc(skaiciai, (*N)*sizeof(int));
            skaiciai[(*N)-1] = skaicius;
            skaicius = 0;
            sk_m = 0;
        }
    }   
}

int didziausias(int n, int *skaiciai){
    int max = skaiciai[0];
    for (int i = 1; i < n; i++)
    {
        if(max < skaiciai[i]){
            max = skaiciai[i];
        }
    }
    return max;
}

int main(){
    char eilute[] = "123Nustatykite, bei 3išveskite inf9999ormaci33321ją į ko44nsolės la5ngą api102e tai, kiek skaičių504 yra eilutėje ir kuris23456 didžiausias321";
    int n = strlen(eilute);
    int *skaiciai = (int*)malloc(sizeof(int));
    int N = 0;
    rasti_skaicius(n, eilute, &N, skaiciai);
    int max = didziausias(N, skaiciai);
    printf("Eilutej yra %d skaiciu\n", N);
    printf("Didziausias skaicius eilutej: %d\n", max);
}