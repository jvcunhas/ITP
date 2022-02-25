#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n = 0, fim = 0, fim2 =0, s = 0, indice_participante = 0;
    char **participantes = NULL;
    char nome[255];
    int aux = 0, j = 0;

    while(!fim){
        fgets(nome, 254, stdin);
        nome[strlen(nome) - 1] = '\0';
        if(strcmp(nome, "acabou") != 0){
            if (participantes == NULL){
                participantes = malloc(sizeof(char*));
            } else {
                participantes = realloc(participantes, sizeof(char*) * (n+1));
            }
            participantes[n] = malloc(sizeof(char*) * (strlen(nome) + 1));
            strcat(participantes[n], nome);
            n++;
        } else {
            fim = 1;
        }    
    }

    scanf("%d", &s);
    srand(s);

    int indices_printados[n];

    for(int i = 0; i<n;i++){
        indices_printados[i] = n+10;
    }

    while(aux != n){
    indice_participante= rand()%n;
        if (aux == 0){
            printf("%s\n", participantes[indice_participante]);
            indices_printados[aux] = indice_participante;
            aux++;
        } else {
            for(int i = 0; i < n; i++){
                if (indice_participante == indices_printados[i]){
                    j++;
                }
            }
            if(j == 0){
                printf("%s\n", participantes[indice_participante]);
                indices_printados[aux] = indice_participante;
                aux++;
            }
            j = 0;
        }
    }
 
    return 0;
}