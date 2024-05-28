#include <stdio.h>

#define PLOTIS 12

void spausdinti_centre(int zuvis){
    int tarpai = PLOTIS - snprintf(NULL, 0, "%d", zuvis);
    int k_tarpai = tarpai / 2;
    int d_tarpai = tarpai - k_tarpai;
    printf("%*s%d%*s*", k_tarpai, "", zuvis, d_tarpai, "");
}

int main(){
    int jono_kuojos, jono_lydekos, jono_karpiai;
    int juozo_kuojos, juozo_lydekos, juozo_karpiai;
    int jurgio_kuojos, jurgio_lydekos, jurgio_karpiai;

    printf("Ivesti kiek kuoju, lydeku ir karpiu pagavo Jonas: \n");
    scanf("%d \n %d \n %d", &jono_kuojos, &jono_lydekos, &jono_karpiai);

    printf("Ivesti kiek kuoju, lydeku ir karpiu pagavo Juozas: \n");
    scanf("%d \n %d \n %d", &juozo_kuojos, &juozo_lydekos, &juozo_karpiai);

    printf("Ivesti kiek kuoju, lydeku ir karpiu pagavo Jurgis: \n");
    scanf("%d \n %d \n %d", &jurgio_kuojos, &jurgio_lydekos, &jurgio_karpiai);

    int tarpai = 12;

    printf("*****************************************************\n");
    printf("*            *    Kuoja   *   Lydeka   *   Karpis   *\n");
    printf("*****************************************************\n");
    printf("*  Jonas     *");
    spausdinti_centre(jono_kuojos);
    spausdinti_centre(jono_lydekos);
    spausdinti_centre(jono_karpiai);
    printf("\n");
    printf("*  Juozas    *");
    spausdinti_centre(juozo_kuojos);
    spausdinti_centre(juozo_lydekos);
    spausdinti_centre(juozo_karpiai);
    printf("\n");
    printf("*  Jurgis    *");
    spausdinti_centre(jurgio_kuojos);
    spausdinti_centre(jurgio_lydekos);
    spausdinti_centre(jurgio_karpiai);
    printf("\n");
    printf("*****************************************************\n");
    
    return 0;
}