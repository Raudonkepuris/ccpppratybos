#include<math.h>
#include<stdio.h>

int main(){
    float rezultatas, a, b;

    for (float x = 0; x < 10; x+=2.3)
    {
        a = sin(x);
        b = cos(x);
        rezultatas = a * pow(x, 2) + b;
        printf("Kai x = %f, y = %.3f\n", x, rezultatas); 
    }
    
}