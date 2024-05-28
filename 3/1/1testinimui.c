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

// void get_quad(int signX, int signY){
//     char ketvirciai[8][20] = {"Ant asies", "1 ketvirtis", "", "4 ketvirtis", "", "2 ketvirtis", "", "3 ketvirtis"};
//     int rez = (1 - (signY ^ 1) - ((signX ^ 1) * 2)) * abs(signX & signY);
//     printf("%d ; %d\n", signX, signY);
//     printf("%s\n\n", ketvirciai[rez]);
// }

void print_bits(int x, int n){
    printf("%d: \n", x);
    for (int i = n; i >= 0; i--)
    {
        int k = x >> i;

        if (k & 1)
        printf("1");
        else
        printf("0");
    }
    printf("\n");
}

int gauti_ketvirti(int signX, int signY){  
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

    // printf("%s\n", ketvirtis[rez]);
    return 0;
}

int main(int argc, char* argv[]) {   
    int zenklas[64] = {0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };

    char *filename = argv[1];
    FILE *file;
    file = fopen(filename, "r");

    int x, y;
    while (fscanf(file, "%d %d\n", &x, &y) != EOF)
    {
        gauti_ketvirti(zenklas[bitu_skaicius(x)],  zenklas[bitu_skaicius(y)]);
    }

    // gauti_ketvirti(zenklas[bitu_skaicius(1)],  zenklas[bitu_skaicius(1)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(-1)], zenklas[bitu_skaicius(1)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(-1)], zenklas[bitu_skaicius(1)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(1)],  zenklas[bitu_skaicius(-1)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(0)],  zenklas[bitu_skaicius(0)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(1)],  zenklas[bitu_skaicius(0)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(0)],  zenklas[bitu_skaicius(1)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(-1)], zenklas[bitu_skaicius(0)]);
    // gauti_ketvirti(zenklas[bitu_skaicius(0)],  zenklas[bitu_skaicius(-1)]);

    return 0;
}