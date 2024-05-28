#include <stdio.h>
#include<limits.h>
#include <stdlib.h>

// hamming weight 32bitu implementacija
// veikia ir INT_MAX/INT_MIN!!!!!!
int bitCount(int x){
    // iki return viskas analogiskai vyksta 64bitu algoritmui
    int originalX = x;
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    // cia bitsu shiftas atitaikomas 32bitam
    // kas eina po pliuso cia yra ne is algoritmo nes reikia, kad atskaiciuotu jeigu minusinis skaicius
    // INT_MIN 1000....
    // INT_MAX 01111....
    return  ( (x * 0x01010101) >> 24) + ((originalX >> 31) & 1) * 31;
}

void print_bits(int x){
    printf("%d: \n", x);
    for (int i = 31; i >= 0; i--)
    {
        int k = x >> i;

        if (k & 1)
        printf("1");
        else
        printf("0");
    }
    printf("\n");
}

void get_quad(int signX, int signY){
    char ketvirciai[8][20] = {"Ant asies", "1 ketvirtis", "", "4 ketvirtis", "", "2 ketvirtis", "", "3 ketvirtis"};
    int rez = (1 - (signY ^ 1) - ((signX ^ 1) * 2)) * abs(signX & signY);
    printf("%d ; %d\n", signX, signY);
    printf("%s\n\n", ketvirciai[rez]);
}

int main() {   
    int sign[64] = {0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };

    // print_bits(0x55555555);/
    // print_bits(0x33333333);
    // print_bits(0x0F0F0F0F);
    // print_bits(0x01010101);

    // printf("%d\n", sign[bitCount(0)]);
    // printf("%d\n", sign[bitCount(1)]);
    // printf("%d\n", sign[bitCount(-1)]);
    // printf("%d\n", sign[bitCount(2147483647)]);
    // printf("%d\n", sign[bitCount(-2147483648)]);

    // printf("1kv\n");
    get_quad(sign[bitCount(1)], sign[bitCount(1)]);
    // printf("2kv\n");
    get_quad(sign[bitCount(-1)], sign[bitCount(1)]);
    // printf("3kv\n");
    get_quad(sign[bitCount(-1)], sign[bitCount(-1)]);
    // printf("4kv\n");
    get_quad(sign[bitCount(1)], sign[bitCount(-1)]);
    // printf("\n");
    get_quad(sign[bitCount(0)], sign[bitCount(0)]);
    get_quad(sign[bitCount(1)], sign[bitCount(0)]);
    get_quad(sign[bitCount(0)], sign[bitCount(1)]);
    get_quad(sign[bitCount(-1)], sign[bitCount(0)]);
    get_quad(sign[bitCount(0)], sign[bitCount(-1)]);

    return 0;
}