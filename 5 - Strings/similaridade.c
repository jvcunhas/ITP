#include <stdio.h>
#include <string.h>

int maior_string(char *str1, char *str2){
    int size_1, size_2;

    size_1 = strlen(str1);
    size_2 = strlen(str2);

    if (size_1 > size_2){
        return size_1;
    } else {
        return size_2;
    }
}

int main(){
    int n = 0;
    int i, j;
    int m_size;
    int quant_similar = 0;

    m_size = 0;

    scanf("%d", &n);

    char palavras[n][10];
    int matriz[n][n];
    char aux[20];

    for(i = 0;i < n; i++){
        scanf("%s", palavras[i]);    
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            m_size = maior_string(palavras[i], palavras[j]);
            for(int k = 0; k < m_size; k++){
                if (palavras[i][k] == palavras[j][k]){
                    quant_similar += 1;
                }
            }
            matriz[i][j] = quant_similar;
            quant_similar = 0;
        }
    }

    printf("%10s"," ");

    for(i = 0; i<n;i++){
        printf("%10s", palavras[i]);
    }

    printf("\n");

    for(i = 0; i < n;i++){
        printf("%-10s", palavras[i]);
        for(j = 0; j < n;j++){
            sprintf(aux, "%d/%d", matriz[i][j], maior_string(palavras[i], palavras[j]));
            printf("%10s", aux);
        }
        printf("\n");
    }

    return 0;
}