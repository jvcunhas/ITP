#include <stdio.h>

int main(){
    int i = 0;
    int j = 0;

    int A[3][3];
    int B[3][3];

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            B[j][i] = A[2-i][j]; 
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
           printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}