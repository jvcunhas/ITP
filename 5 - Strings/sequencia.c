#include <stdio.h>
#include <string.h>

int main(){
    char texto[1001];

    texto[1000] = '\0';

    int sequencia_final = 0;
    int tam = 0;
    int passo = 0;

    fgets(texto, 999, stdin);

    tam = strlen(texto);

    for(int i = 0;i < tam;i++){
        if (passo < 4){
            if((texto[i+1] - texto[i]) == 1){
                passo += 1;
            } else {
                passo = 0;
            }
        } else {
            sequencia_final += 1;
            passo = 0;
        }
    }

    if(sequencia_final > 0){
        printf("%d\n", sequencia_final);
    } else {
        printf("nenhuma sequencia encontrada\n");
    }

    return 0;
}