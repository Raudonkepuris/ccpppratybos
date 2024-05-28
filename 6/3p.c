#include <stdlib.h>
#include <stdio.h>

const int n = 5;

void tikrinti_matrica(int mat[5][5]){
    int sumos[10];
    for(int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += mat[i][j];
            printf("%d")
        }
        
    }
}

int main(){
    int mat[5][5] = {{1,1,1,1,1},
                    {1,1,1,1,1},
                    {1,1,1,1,1},
                    {1,1,1,1,1},
                    {1,1,1,1,1}};

    tikrinti_matrica(mat, n);
}