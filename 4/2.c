#include<stdio.h>
#include<math.h>

int main(){
    double sum10 = 0, sum20 = 0, skirt;
    for (int i = 1; i <= 20; i++)
    {
        if(i <= 10){
            sum10 += 1 / (double)(1 << i);
        }

        sum20 += 1 / (double)(1 << i);
    }

    // sum10 = 1 - (1 / (double)(1 << 10));
    // sum20 = 1 - (1 / (double)(1 << 20));

    skirt = sum20 - sum10;
    printf("Suma kai n=10 : %.10f\n", sum10);
    printf("Suma kai n=20 : %.10f\n", sum20);
    printf("Skirtumas tarp sumos kai n = 20 ir n = 10 : %.10f\n", skirt);
}