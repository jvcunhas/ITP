#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 301

typedef struct {
    unsigned int *array;
    int size;
} vetor;

typedef struct {
    vetor integer;
    vetor fractional;
    int signal;
    int exp;
} BigFloat;

void readline(char *string){
    fgets(string, MAX_LINE, stdin);
}

BigFloat strToBigFloat(char *string){
    char *pedaco;
    char aux_str[10], aux_str2[10];
    char **ponteiro;
    int len = 0;
    int resto = 0, aux1 = 0, aux2 = 0, sobra = 0, vazio = 0, c = 0;
    BigFloat bf;

    if(string[0] != '.'){
        pedaco = strtok(string, ".");
        ponteiro = &pedaco;
        len = strlen(pedaco);
    } else {
        vazio = 1;
    }

    if(string[0] == '-'){
        bf.signal = -1;
        len--;
        aux2++;
    } else {
        bf.signal = 1;
    }

    if(vazio != 1){
        if (len > 9){
            resto = len % 9;
            if (resto > 0){
                bf.integer.array = malloc(sizeof(int) * (len/9) + 1);
                bf.integer.size = (len/9) + 1;
                sobra = 1;
            } else {
                bf.integer.array = malloc(sizeof(int) * (len/9));
                bf.integer.size = len/9;
            }
        } else {
            bf.integer.array = malloc(sizeof(int) * 1);
            bf.integer.size = 1;
        }
        for(int j = bf.integer.size - 1; j >= 0; j--){ // -- Inteiro
            if(sobra){
                bf.integer.array[j] = atoi(strncpy(aux_str, (*ponteiro) + (aux2), resto));
                aux1 = resto + aux2;
                sobra = 0;
            } else {
                bf.integer.array[j] = atoi(strncpy(aux_str,((*ponteiro) + aux1 + aux2), 9));
                aux1 += 9;
            }
        }
    } else {
        bf.integer.array = malloc(sizeof(int) * 1);
        bf.integer.array[0] = 0;
        bf.integer.size = 1;
    }

    // ----- Pedaço fracional
    if(vazio == 1){
        pedaco = strtok(string, ".");
    } else {
        pedaco = strtok(NULL, ".");
    }

    if(pedaco != NULL){
        ponteiro = &pedaco;
        aux1 = aux2 = 0;
        len = strlen(pedaco);

        while(pedaco[c] == '0'){
            c++;
        }
        bf.exp = c;

        c = 1;

        while(pedaco[len - c] == '0'){
            c++;
        }
        
        if (c > 1){
            pedaco[len - c + 1] = '\0';
        }
        
        if (len > 9){
            resto = len % 9;
            if (resto > 0){
                bf.fractional.array = malloc(sizeof(int) * (len/9) + 1);
                bf.fractional.size = (len/9) + 1;
                sobra = 1;
            } else {
                bf.fractional.array = malloc(sizeof(int) * (len/9));
                bf.fractional.size = len/9;
            }
        } else {
            bf.fractional.array = malloc(sizeof(int) * 1);
            bf.fractional.size = 1;
        }

        for(int j = bf.fractional.size - 1; j >= 0; j--){
            if(sobra){
                bf.fractional.array[j] = atoi(strncpy(aux_str2, (*ponteiro) + aux2, resto));
                aux1 = resto + aux2;
                sobra = 0;
            } else {
                bf.fractional.array[j] = atoi(strncpy(aux_str2, ((*ponteiro) + aux1 + aux2), 9));
                aux1 += 9;
            }
        }
    } else {
        bf.fractional.array = malloc(sizeof(int) * 1);
        bf.fractional.array[0] = 0;
        bf.fractional.size = 1;
    }

    return bf;

}

void printBigFloat(BigFloat bf){
    if(bf.signal < 0){
        printf("-");
    }
    for(int i = bf.integer.size - 1; i >= 0; i--){
        if(i == bf.integer.size - 1){
            printf("%d", bf.integer.array[i]);
        } else {
            printf("%09d", bf.integer.array[i]);
        }
    }
    printf(".");
    for(int i = 0; i < bf.exp; i++){
        printf("0");
    }
    for(int i = bf.fractional.size - 1; i >= 0; i--){
        if(i == bf.fractional.size - 1){
            printf("%d", bf.fractional.array[i]);
        } else {
            printf("%09d", bf.fractional.array[i]);
        }
    }
}

int main() {
    char line[MAX_LINE];
    readline(line);
    BigFloat bf = strToBigFloat(line);
    printBigFloat(bf);
    printf("\n%i %u %u %u\n",
        bf.signal,
        bf.exp,
        bf.integer.array[bf.integer.size - 1],
        bf.fractional.array[bf.fractional.size - 1]
    );
    return 0;
}