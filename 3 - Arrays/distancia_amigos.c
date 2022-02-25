#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, p, max, soma;
    n = p = max = soma = 0;

    scanf("%d", &n);
    int aps[n];

    for(int i = 0;i < n;i++){
        scanf("%d", &aps[i]);
    }

    for(int j = 0; j < n;j++){
        for(int k = 0;k < n;k++){
            if(j != k){
                p = abs(k - j);
                soma = aps[j] + p + aps[k];
                if(soma > max){
                    max = soma;
                }
            }
        }
    }

    printf("%d\n", max);

    return 0;
}