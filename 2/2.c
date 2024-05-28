#define _USE_MATH_DEFINES

#include<math.h>
#include<stdio.h>

int main(){

    float ivestis, rezultatas;

    for (int i = 0; i < 5; i++)
    {
        printf("Ivesti argumenta x tarp [0;pi/2(1.570)]: ");
        scanf("%f", &ivestis);
        ivestis = ivestis < 0 ? M_PI/2 : ivestis > M_PI / 2 ? 0 : ivestis;

        rezultatas = (2.0/3.0) * sqrt(sin(ivestis) + cos(ivestis));

        printf("%f\n", rezultatas);
    }
    
}