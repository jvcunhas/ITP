#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_cartela;
    int tam_cartela;
    int *numeros;
    int *marcacao;
} Cartela;

void iniciar_cartela(Cartela *cartela, int id_t, int tamanho, int quant_globo){
    int aux = 0, sorteado = 0, aux2 = 0;

    cartela->id_cartela = id_t;
    cartela->tam_cartela = tamanho;
    cartela->numeros = malloc(sizeof(int) * tamanho);
    cartela->marcacao = malloc(sizeof(int) * 1);
    cartela->marcacao[0] = 1;
    
    srand(id_t);

    while(aux != tamanho){
        sorteado = rand() % quant_globo + 1;
        for(int i = 0; i < aux;i++){
            if(sorteado == cartela->numeros[i]){
                aux2++;
            }
        }
        if(aux2 == 0){
            cartela->numeros[aux] = sorteado;
            aux++;
        }
        aux2 = 0;
    }
}

int marcar_cartela(Cartela *cartela, int num){
    int m_size = cartela->marcacao[0];

    cartela->marcacao = realloc(cartela->marcacao, sizeof(int) * (m_size + 1));
    cartela->marcacao[0] = m_size + 1;

    for(int i = 1; i < m_size + 1;i++){
        cartela->marcacao[i] = num;
    }
    
    if((cartela->marcacao[0] - 1) == cartela->tam_cartela){
        return 1;
    } else {
        return 0;
    }

}

int main(){
    int n = 0, m = 0, s = 0, t = 0, aux = 0, aux2 = 0, aux3 = 0, vencedor = 0;
    int bingo = 0;
    char entrada[18];
    Cartela *cartelas;
    
    scanf("%d %d %d ", &n, &m, &s);
    fgets(entrada,17,stdin);
    entrada[strlen(entrada) - 1] = '\0';

    while(strcmp(entrada, "Comecou o jogo!") != 0){
        sscanf(entrada, "%d", &t);
        if(aux == 0){
            cartelas = malloc(sizeof(Cartela) * (aux + 1));
        } else {
            cartelas = realloc(cartelas, sizeof(Cartela) * (aux + 1));
        }

        iniciar_cartela(&cartelas[aux], t, n, m);
        fgets(entrada,17,stdin);
        entrada[strlen(entrada) - 1] = '\0';
        aux++;
    }

    srand(s);
    int sorteados[m];

    while(aux2 != m){
        int sorteado = rand() % m + 1;
        for(int i = 0; i < aux2;i++){
            if(sorteado == sorteados[i]){
                aux3++;
            }
        }
        if(aux3 == 0){
            for(int i = 0; i < aux; i++){
                for(int j = 0; j < n;j++){
                    if(sorteado == cartelas[i].numeros[j]){
                        bingo = marcar_cartela(&cartelas[i], sorteado);
                    }
                }
                if(bingo == 1){
                    vencedor = i;
                    break;
                }
            }
            sorteados[aux2] = sorteado;
            if(bingo == 1){
                break;
            }
            aux2++;
        }
        aux3 = 0;
    }

    for(int i = 0; i <= aux2;i++){
        printf("%d ",sorteados[i]);
    }

    printf("\nBingo! Cartela %d: ", cartelas[vencedor].id_cartela);
    for(int i = 0; i < cartelas[vencedor].tam_cartela; i++){
        printf("%d ", cartelas[vencedor].numeros[i]);
    }

    return 0;
}