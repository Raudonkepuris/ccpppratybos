#include<stdio.h>
#include<math.h>
#include<limits.h>

const double e = 0.00001;

double int_sin(double a, double b, double n){
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n-1; i++)
    {
        sum += sin(a + i * h);
    }
    double integralas = (((sin(a)+sin(b))/2) + sum) * h;
    return integralas;
}

void int_sin_tikslumu_e(double a, double b){
    int n = 0;

    double In = 10000;
    double In1;

    do{
        In1 = In;
        n++;
        double h = (b - a) / n;
        double sum = 0;
        for (int i = 1; i <= n-1; i++)
        {
            sum += sin(a + i * h);
        }
        In = (((sin(a)+sin(b))/2) + sum) * h;
    }while(fabs(In - In1) >= e);

    printf("Tikslumas buvo pasiketas kai n = %d, tada I = %lf\n", n, In);
}

int main(){
    double a, b, n;
    printf("Ivesti a, b ir n\n");
    scanf("%lf \n %lf \n %lf", &a, &b, &n);

    double integralas = int_sin(a, b, n);
    int_sin_tikslumu_e(a, b);

    printf("%lf\n", integralas);
}