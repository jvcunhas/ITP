#include <stdio.h>

int main(){
    int n, j, i_ganhador, valor_ganhadores, total, petiscos;
    n, j, i_ganhador, valor_ganhadores, total = 0;

    scanf("%d",&n);

    int apostas_jogadores[n];
    int indice_jogadores[n];

    for(int i = 0; i < n; i++){
        scanf("%d %d",&apostas_jogadores[i], &indice_jogadores[i]);
        total += apostas_jogadores[i];
    }

    scanf("%d", &i_ganhador);

    valor_ganhadores = total;

    for(int i = 0; i < n; i++){
        if(i_ganhador != indice_jogadores[i]){  
            valor_ganhadores -= apostas_jogadores[i];
        }
    }

    printf("Total: R$ %d\n", total);

    petiscos = ((total / (float)10) + 0.50);

    for(int i = 0; i < n; i++){
        if (valor_ganhadores <= 0) {
            printf("Apostador %d: R$ %d\n", i+1, (int)((float)(apostas_jogadores[i] / (float)total) * (float)(total - petiscos) + 0.5));
        } else {
            if (i_ganhador == indice_jogadores[i]){
               printf("Apostador %d: R$ %d\n", i+1, (int)((float)(apostas_jogadores[i] / (float)valor_ganhadores) * (float)(total - petiscos) + 0.5)); 
            }
        }
    }

    printf("Bebidas e petiscos: R$ %d\n", petiscos);

    return 0;
}

