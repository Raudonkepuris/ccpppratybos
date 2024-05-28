#include <stdio.h>
#include<limits.h>
#include <stdlib.h>
#include <stdint.h>

int bitu_skaicius(int x){
    int originalX = x;
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    return  ( (x * 0x01010101) >> 24) + ((originalX >> 31) & 1) * 31;
}

void gauti_ketvirti(int signX, int signY){  
    uint8_t rez = 0;

    char ketvirtis[14][40] = {"Taskas yra III ketvirtyje", 
        "Taskas yra ant X asies, X - neigiamas", 
        "Taskas yra ant Y asies, Y - neigiamas",
        "Taskas yra koordinaciu pradzioje",
        "Taskas yra II ketvirtyje",
        "",
        "Taskas yra ant Y asies, Y - teigiamas",
        "",
        "Taskas yra IV ketvirtyje",
        "Taskas yra ant X asies, X - teigiamas",
        "",
        "",
        "Taskas yra I ketvirtyje"};

    rez |=  ((unsigned)signX >> 31 ^ 1) * (signX & 1) << 3;
    rez |=  ((unsigned)signY >> 31 ^ 1) * (signY & 1) << 2;
    rez |= ((~((signX & 1) - 1) ) + 1) << 1;
    rez |= ((~((signY & 1) - 1) ) + 1);

    printf("%s\n", ketvirtis[rez]);
}

int main(int argc, char* argv[]) {   
    int zenklas[64] = {0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };

    int x, y;

    printf("Ivesti x, y:\n");
    scanf("%d \n %d", &x, &y);

    gauti_ketvirti(zenklas[bitu_skaicius(x)], zenklas[bitu_skaicius(y)]);

    return 0;
}