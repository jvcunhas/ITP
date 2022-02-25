#include <stdio.h>

int main(){
    int A[3][5];
    int result[3] = {0, 0, 0};
    int i,j;

    for(i = 0;i < 3;i++){
        for(j = 0;j < 5;j++){
            scanf("%d", &A[i][j]);
            result[i] += A[i][j];
        }
    }

    printf("SL = [%d %d %d]\n", result[0], result[1], result[2]);

    return 0;
}