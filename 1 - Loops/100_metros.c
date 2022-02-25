#include <stdio.h>

int main(){

    float inscricao, tempo;
    int atletas, series;

    atletas = series = 0;
    inscricao = tempo = 0.0;

    scanf("%f", &inscricao);

    while(1){
        scanf("%f", &tempo);
        if (tempo != -1){
            if (tempo <= inscricao){
                atletas += 1;
            }
        }else{
            break;
        }                
    }

    if (atletas % 8 == 0){
        printf("%d %d\n", atletas, atletas/8);
    }else {
        printf("%d %d\n", atletas, (atletas/8) + 1);
    }
 
    return 0;
}