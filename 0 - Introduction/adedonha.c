#include <stdio.h>

int main(void){
    char alfabeto[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int m1, m2, m3, m4, total;

    scanf("%d %d %d %d", &m1, &m2, &m3, &m4);
    total = m1 + m2 + m3 + m4;


    if (total == 0){
        printf("Ei! Ninguém colocou nada!\n");
    }
    else{
        if (total > 26){
            printf("Letra: %c\n", alfabeto[total-27]);
        } else {
            printf("Letra: %c\n", alfabeto[total-1]);
        }
    }
    return 0;
}