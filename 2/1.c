#include<math.h>
#include<stdio.h>

int main(){

    int x = 1;

    float rezultatas;

    while(x < 10){
        rezultatas = cos(x) + pow(x, 4);

        printf("Argumentas x = %d, rezultatas = %.4f\n", x, rezultatas);

        x++;
    }
}