#include <stdio.h>

int main(){

    int quantidade = 0;
    float valor = 0.0;
    int q_total = 0;
    float v_total = 0.0;

    while(1){
        scanf("%d", &quantidade);

        if (quantidade == -1){
            break;
        }

        scanf("%f", &valor);

        q_total += quantidade;
        v_total += valor*quantidade;
    }

    printf("%d %.2f\n", q_total, v_total);

    return 0;
}