#include <stdio.h>

int main(){
    int i = 0;
    int j = 0;

    int A[5][3];
    //int B[][2];
    int b = 0; 
    int a = 0;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for(i = 0; i < 5; i++){
        if(A[i][2] < A[i][1]){
            b =  A[i][1] - A[i][2];
            printf("%d %d\n", A[i][0], b);
            
            a++;
        }
    }

    if(a == 0){
        printf("Estoque Completo\n");
    }

    return 0;
}