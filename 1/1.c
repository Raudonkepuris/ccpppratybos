#include <stdio.h>

int main(){
    printf("Kaimynui is kaires linkiu sveikatos\n");
    

    int alga;
    scanf("%d", &alga);
    printf("Baiges studijas tikiuosi gauti %d euru atlyginima\n", alga);


    int p_int, a_int, vid_int, vid_float_int;
    float p_float, a_float, vid_float;

    printf("Ivesti du sveikuosius skaicius: \n");
    scanf("%d \n %d", &p_int, &a_int);

    printf("Ivesti du realiuosius skaicius: \n");
    scanf("%f \n %f", &p_float, &a_float);

    vid_int = (p_int + a_int) / 2;
    printf("Sveikuju skaiciu vidurkis saugamas sveikojo tipo kintamajame %d\n", vid_int);

    vid_float_int = (p_float + a_float) / 2;
    printf("Realiuju skaiciu vidurkis saugamas sveikojo tipo kintamajame %d\n", vid_float_int);

    vid_float = (p_float + a_float) / 2;
    printf("Realiuju skaiciu vidurkis saugamas realiojo tipo kintamajame %.2f\n", vid_float);

    return 0;
}