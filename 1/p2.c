#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PVM 21

void gauti_informacija(char *prekes[], int prekiu_sk, int *kiekiai, float *kainos_su_pvm, float *kainos_be_pvm){
    for(int i = 0; i < prekiu_sk; i++){
        int kiekis;
        float kaina_su_pvm;
        printf("Ivesti perkama kieki %s: ", prekes[i]);
        scanf("%d", &kiekis);
        printf("Ivesti %s kaina su PVM: ", prekes[i]);
        scanf("%f", &kaina_su_pvm);
        kiekiai[i] = kiekis;
        kainos_su_pvm[i] = kaina_su_pvm;
        kainos_be_pvm[i] = kaina_su_pvm - (kaina_su_pvm / 100 * PVM);
    }
}

void spausdinti_centre(int plotis, char tekstas[]){
    int teksto_ilgis = strlen(tekstas);
    int tarpai = plotis - teksto_ilgis;
    int k_tarpai = tarpai / 2;
    int d_tarpai = tarpai - k_tarpai;
    printf("%*s%s%*s*", k_tarpai, "", tekstas, d_tarpai, "");
}

void spausdinti_informacija(char *prekes[], int prekiu_sk, int *kiekiai, float *kainos_su_pvm, float *kainos_be_pvm){
    printf("********************************************************************\n");
    printf("*   Prekė   *  Kiekis  *  Kaina vnt. be PVM  *  Kaina visų be PVM  *\n");
    printf("********************************************************************\n");
    float visa_kaina_be_pvm = 0;
    float visa_kaina_su_pvm = 0;
    for(int i = 0; i < prekiu_sk; i++){
        float prekiu_kaina_be_pvm = kiekiai[i] * kainos_be_pvm[i]; 
        visa_kaina_be_pvm += prekiu_kaina_be_pvm;
        visa_kaina_su_pvm += kiekiai[i] * kainos_su_pvm[i];
        printf("*");
        spausdinti_centre(11, prekes[i]);
        char tekstas[100];
        sprintf(tekstas, "%d vnt.", kiekiai[i]);
        spausdinti_centre(10, tekstas);
        sprintf(tekstas, "%.2f Eur", kainos_be_pvm[i]);
        spausdinti_centre(21, tekstas);
        sprintf(tekstas, "%.2f Eur", prekiu_kaina_be_pvm);
        spausdinti_centre(21, tekstas);
        printf("\n");
    }
    printf("********************************************************************\n");
    printf("Viso be PVM: %.2f Eur\n", visa_kaina_be_pvm);
    printf("        PVM: %d %% \n", PVM);
    printf("Viso su PVM: %.2f Eur\n", visa_kaina_su_pvm);
}

int main(){
    char *prekes[] = {"Duona", "Sviestas", "Desra", "Suris"};
    int prekiu_sk = sizeof(prekes) / sizeof(prekes[0]);

    int *kiekiai;
    kiekiai = (int*)malloc(prekiu_sk * sizeof(int));
    float *kainos_su_pvm;
    kainos_su_pvm = (float*)malloc(prekiu_sk * sizeof(float));
    float *kainos_be_pvm;
    kainos_be_pvm = (float*)malloc(prekiu_sk * sizeof(float));

    gauti_informacija(prekes, prekiu_sk, kiekiai, kainos_su_pvm, kainos_be_pvm);

    spausdinti_informacija(prekes, prekiu_sk, kiekiai, kainos_su_pvm, kainos_be_pvm);

    free(kiekiai);
    free(kainos_su_pvm);
    return 0;
}