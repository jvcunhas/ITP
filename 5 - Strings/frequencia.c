#include <stdio.h>
#include <string.h>

int main(){
    char palavra[255];
    char texto[255][255];
    int aux = 0;
    int num = 0;
    int quant_palavras = 0;
    int quant_p_total = 0;
    int ocorr = 0;
    int ocorr_total;
    int len = 0;
    char* pedaco;
    char* substring;

    fgets(palavra, 254, stdin);
    len = strlen(palavra);
    palavra[len-1] = '\0';

    do{
    
    fgets(texto[aux], 254, stdin);
    len = strlen(texto[aux]);
    texto[aux][len-1] = '\0';
    sscanf(texto[aux],"%d", &num);
    aux += 1;

    }while(num != -1);

    for (int i = 0; i < aux-1; i++){
        pedaco = strtok(texto[i], " ");
        while(pedaco != NULL){
            //printf("%s - ", pedaco);
            quant_palavras += 1;
            substring = strstr(pedaco, palavra);
            if (substring != NULL){
                ocorr += 1;
            }
            pedaco = strtok(NULL, " ");
        }
        printf("%.4f\n", (float)ocorr/quant_palavras);
        quant_p_total += quant_palavras;
        quant_palavras = 0;
        ocorr_total += ocorr;
        ocorr = 0;
    }

    printf("%.4f\n", (float)ocorr_total/quant_p_total);

    return 0;
}