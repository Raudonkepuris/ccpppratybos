#include<stdio.h>

int main(){
    int prekes_kaina, prekiu_skaicius, suma;
    float suma_po_mokesciu, procentas, likusi_suma;
    printf("Ivesti prekes kaina ir parduotu prekiu skaiciu: \n");
    scanf("%d \n %d", &prekes_kaina, &prekiu_skaicius);
    suma = prekes_kaina * prekiu_skaicius;
    suma_po_mokesciu = suma;
    if(suma > 5000 || prekes_kaina > 500){
        suma_po_mokesciu =  suma * 0.85;
    }
    if(suma_po_mokesciu > 10000){
        procentas = 0.3;
    }else{
        procentas = 0.25;
    }
    likusi_suma = suma_po_mokesciu * procentas;
    printf("Pardavejui likusi suma: %f\n", likusi_suma);
}