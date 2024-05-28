#include<stdio.h>
#include<math.h>
#include <limits.h>

int sign(int i){
    return (i >> 31) - ((~i + 1) >> 31);
}

int main(){
    int x, y;
    printf("Ivesti x ir y koordinates: \n");
    scanf("%d \n %d", &x, &y);

    int sign_x = (x >> 31) - ((~x + 1) >> 31);
    int sign_y = (y >> 31) - ((~y + 1) >> 31);

    int kvad_12[3] = 

}