#include <stdio.h>

int main(){
    int dados[5][4];
    int i,j, a;
    int matricula = 0;
    int cr_maior = 0;
    int matricula_win = 0;

    a = 0;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", &dados[i][j]);
        }
    }

    scanf("%d", &matricula);

    for(i = 0; i < 5; i++){
        if (matricula == dados[i][2]){
            if(dados[i][3] > cr_maior){
                cr_maior = dados[i][3];
                matricula_win = dados[i][0];
            }
            a++;
        }
    }

    if(a > 0){
        printf("CR = %d\n", cr_maior);
        printf("Matricula = %d\n", matricula_win);
    }else{
        printf("Curso nao existente\n");
    } 

    return 0;
}