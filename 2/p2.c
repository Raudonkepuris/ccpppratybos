#include<stdio.h>
#include<math.h>

int main(){
    float x, y, c, p;
    printf("Ivesti staciojo trikampio krastines x ir y: \n");
    scanf("%f \n %f", &x, &y);
    c = sqrt(pow(x,2) + pow(y,2));
    p = x + y + c;
    printf("Sio staciojo trikampio perimetras P = %.2f\n", p);
}