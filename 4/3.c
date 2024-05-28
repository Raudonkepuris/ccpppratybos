#include<stdio.h>
#include<math.h>

int main(){
    const float e = 0.00001;
    int a;
    float xn, xnp1=9999, x;
    scanf("%d", &a);
    if(a <= 1){
        xn = 0.95;
    }else if(a > 1 && a <= 25){
        xn = (float)a / 5;
    }else{
        xn = (float)a / 25;
    }

    float skirt = 999;
    while(((float)5/4 * (float)a * skirt) > e){
        xnp1 = (((float)4/5) * xn) + ((float)a/(5*pow(xn, 4)));
        skirt = fabs(xnp1 - xn);
        xn = xnp1;
    }

    printf("Penktojo lapsnio saknis is %d = %f\n", a, xnp1);
}