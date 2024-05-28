#define _USE_MATH_DEFINES

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int x[4];
    int y[4];

    int didz_y = INT_MIN;
    int didz_y_id;

    printf("Ivesti 4 taskus (x,y):\n");

    for (int i = 0; i < 4; i++)
    {
        scanf("%d \n %d", &x[i], &y[i]);
        if(didz_y < abs(y[i])){
            didz_y = abs(y[i]);
            didz_y_id = i;
        }
    }
    
    float r = sqrt(pow(x[didz_y_id], 2) + pow(y[didz_y_id], 2));
    float C = 2 * M_PI * r;

    printf("Taskas su didziausia ordinate %d : %d\n", x[didz_y_id], y[didz_y_id]);
    printf("Atstumas nuo (0,0) : %f\n", r);
    printf("Apskritimo su tokiu spinduliu perimetras : %f\n", C);
}