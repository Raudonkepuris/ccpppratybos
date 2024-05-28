#include<stdio.h>
#include<math.h>

int main(){
    int x;
    while(scanf("%d", &x) && x >= 0){
        printf("%f\n", sqrt(x));
    }
}