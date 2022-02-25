#include <stdio.h>

int main(){

    int n = 0;
    int i;
    float valores = 0.0;
    float v_total = 0.0;
    int divisor = 0;

    scanf("%d", &n);

    divisor = n;

    if (n != 0){

        for(i = 0; i < n; i++){
            scanf("%f", &valores);
            if (valores == -1){
                divisor -= 1;
            } else {
                v_total += valores;
            }
        }
        if (divisor != 0){
            printf("%.2f\n", v_total/divisor);
        } else {
            printf("A competicao nao possui dados historicos!\n");
        }
    } else {
        printf("A competicao nao possui dados historicos!\n");
    }

    return 0;
}