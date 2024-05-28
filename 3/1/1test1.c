#include<stdio.h>
#include<math.h>
#include <limits.h>

int main(){
    // int x, y;
    // printf("Ivesti x ir y koordinates: \n");
    // scanf("%d \n %d", &x, &y);

    int n = -324, p = 24234, z = 0;
    
    // printf("%d\n", ((~n + 1))); //  - > +
    // printf("%d\n", ((~n - 1)));
    // printf("%d\n", ((~p + 1))); // + > -
    // printf("%d\n", ((~p - 1)));

    // printf("%d\n", (((~n) + 1))); //  - > +
    // printf("%d\n", (((~n) - 1)));
    // printf("%d\n", (((~p) + 1))); // + > -
    // printf("%d\n", (((~p) - 1)));


    printf("-1 = %d\n", (n >> 31) - ((~n + 1) >> 31));
    printf("0 = %d\n", (z >> 31) - ((~z + 1)>> 31));
    printf("1 = %d\n", (p >> 31) - ((~p + 1) >> 31));

    // printf("-1 = %d\n", (n >> 31) - ((~n - 1) >> 31));
    // printf("0 = %d\n", (z >> 31) - ((~z - 1)>> 31));
    // printf("1 = %d\n", (p >> 31) - ((~p - 1) >> 31));

    // printf("n = %d:\n", (n >> 31));
    // for (int i = 31; i >= 0; i--)
    // {
    //     int k = (n >> 31) >> i;

    //     // printf("%d\n", k);

    //     if (k & 1)
    //     printf("1");
    //     else
    //     printf("0");
    // }

    // printf("\n~n + 1 = %d\n", ((~n + 1) >> 31));

    // for (int i = 31; i >= 0; i--)
    // {
    //     int k = ((~n + 1) >> 31) >> i;

    //     // printf("%d\n", k);

    //     if (k & 1)
    //     printf("1");
    //     else
    //     printf("0");
    // }

    // printf("\np: = %d\n", (p >> 31));

    // for (int i = 31; i >= 0; i--)
    // {
    //     int k = (p >> 31) >> i;

    //     // printf("%d\n", k);

    //     if (k & 1)
    //     printf("1");
    //     else
    //     printf("0");
    // }
    
    // printf("\n~p + 1 = %d\n", ((~p + 1) >> 31));

    // for (int i = 31; i >= 0; i--)
    // {
    //     int k = ((~p + 1) >> 31) >> i;

    //     // printf("%d\n", k);

    //     if (k & 1)
    //     printf("1");
    //     else
    //     printf("0");
    // }

    // printf("\nz = %d\n", (z >> 31));

    // for (int i = 31; i >= 0; i--)
    // {
    //     int k = (z >> 31) >> i;

    //     // printf("%d\n", k);

    //     if (k & 1)
    //     printf("1");
    //     else
    //     printf("0");
    // }
    
    // printf("\n~z + 1 = %d\n", (~z + 1) >> 31);

    // for (int i = 31; i >= 0; i--)
    // {
    //     int k = ((~z + 1) >> 31) >> i;

    //     // printf("%d\n", k);

    //     if (k & 1)
    //     printf("1");
    //     else
    //     printf("0");
    // }
}