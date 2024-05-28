#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void skirstyti_zodziais(char eilute[]){
    int pr = 0;
    int n = 0;
    char zodis[100];
    while (1)
    {
        if (!(eilute[n] == ' ' || eilute[n] == '\0'))
        {
            zodis[n-pr] = eilute[n];
        }
        else
        {
            char zodis2[100] = {'\0'};
            strncpy(zodis2, zodis, n - pr);
            if(zodis2[n-pr-1] == 'a'){
                printf("%s\n", zodis2);
            }
            pr = n+1;
        }

        if(eilute[n] == '\0'){
            break;
        }

        n++;
    }
}

void skyrybos_zenklu_skaicius(char *eilute){
    int tasku = 0, kableliu = 0;
    while (*eilute != '\0')
    {
        if (*eilute == '.')
        {
            tasku++;
        }
        else if(*eilute == ','){
            kableliu++;
        }
        *eilute++;
    }
    printf("Tekste yra %d tasku ir %d kableliu\n", tasku, kableliu);
    
}


int main(){
    char eilute[] = "Vikipedija yra universali, daugiakalbė interneto enciklopedija, kaip bendruomeninis projektas, pagal viki technologiją ir pamatinius principus kuriama daugybės savanorių bei išlaikoma iš paaukotų lėšų.";
    skirstyti_zodziais(eilute);
    skyrybos_zenklu_skaicius(eilute);
}