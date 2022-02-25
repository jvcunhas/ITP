#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* soma_vetores(int tam, int *a, int *b){
    int *c;

    c = malloc(sizeof(int) * tam);
    for(int i = 0; i < tam; i++){
        c[i] = a[i] + b[i];
    }

    return c;
}

int main(){
    int *vetor_a = NULL;
    int *vetor_b = NULL;
    int *vetor_c;
    char *pedaco;
    char nums[256];
    int num = 0, aux_a = 0, aux_b = 0;

    fgets(nums, 255, stdin);
    pedaco = strtok(nums, " ");

    while(pedaco != NULL){
        sscanf(pedaco, "%d", &num);
        if (vetor_a == NULL){
            vetor_a = malloc(sizeof(int));
        } else {
            vetor_a = realloc(vetor_a, sizeof(int) * (aux_a+1));
        }
        vetor_a[aux_a] = num;
        aux_a++;
        pedaco = strtok(NULL, " ");
    }

    fgets(nums, 255, stdin);
    pedaco = strtok(nums, " ");

    while(pedaco != NULL){
        sscanf(pedaco, "%d", &num);
        if (vetor_b == NULL){
            vetor_b = malloc(sizeof(int));
        } else {
            vetor_b = realloc(vetor_b, sizeof(int) * (aux_b+1));
        }
        vetor_b[aux_b] = num;
        aux_b++;
        pedaco = strtok(NULL, " ");
    }

    if (aux_a == aux_b){
        vetor_c = soma_vetores(aux_a, vetor_a, vetor_b);
        for(int i = 0; i < aux_a; i++){       
            printf("%d ", vetor_c[i]);
        }
    } else {
        printf("Vetores de tamanhos diferentes!");
    }

    return 0;
}