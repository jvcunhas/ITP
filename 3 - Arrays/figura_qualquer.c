#include <stdio.h>

int retas_cruzadas = 0;

int dotProduct(int x1, int y1, int x2, int y2){
    int z = 0;

    z = (x1 * y2) - (y1 * x2);

    return z;
}

int isInRight(int pX, int pY, int x1, int y1, int x2, int y2){
    int z, x_1, x_2, y_1, y_2;

    z = x_1 = x_2 = y_1 = y_2 = 0;

    x_1 = x2 - x1;
    x_2 = pX - x1;
    y_1 = y2 - y1;
    y_2 = pY - y1;

    z = dotProduct(x_1, x_2, y_1, y_2);

    if(z < 0){
        return 1;
    } else {
        return 0;
    }
}

int crossedLines(int pX, int pY, int pX_max, int x1, int y1, int x2, int y2){
    int l1, l2, l3, l4;

    l1 = l2 = l3 = l4 = 0;

    l1 = isInRight(pX, pY, x1, y1, x2, y2);
    l2 = isInRight(pX_max, pY, x1, y1, x2, y2);
    l3 = isInRight(x1, y1, pX, pY, pX_max, pY);
    l4 = isInRight(x2, y2, pX, pY, pX_max, pY);

    if (((l1 > 0 && l2 == 0) || (l1 == 0 && l2 > 0)) && ((l3 > 0 && l4 == 0) || (l3 == 0 && l4 > 0))){
        return 1;
    } else {
        return 0;
    }
}

void isInsideForm(int pX, int pY, int pX_max, int x1, int y1, int x2, int y2){
    int linhas = 0;

    linhas = crossedLines(pX, pY, pX_max, x1, y1, x2, y2);

    if (linhas > 0){
        retas_cruzadas++;
    }
}

int main(){
    int n, m, x_max;

    n = m = x_max = 0;

    scanf("%d %d", &n, &m);

    int coordsX[n];
    int coordsY[n];
    char identificador[n];
    int mousesX[n];
    int mousesY[n];

    scanf("%d %d", &coordsX[0], &coordsY[0]);

    // lendo as coords dos pontos
    for(int i = 1; i < n; i++){
        scanf("%d %d", &coordsX[i], &coordsY[i]);
        if (coordsX[i] > x_max){
            x_max = coordsX[i];
        }

    }

    //lendo os pontos do mouse
    for(int i = 0; i < m; i++){
        scanf(" %c %d %d", &identificador[i], &mousesX[i], &mousesY[i]);
    }

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            isInsideForm(mousesX[i], mousesY[i], x_max, coordsX[j], coordsY[j], coordsX[j+1], coordsY[j+1]);
    }
        isInsideForm(mousesX[i], mousesY[i], x_max, coordsX[n-1], coordsY[n-1], coordsX[0], coordsY[0]);
    
        if(retas_cruzadas % 2 != 0){
            printf("%c\n",identificador[i]);
        }

        retas_cruzadas = 0;
    }
    
    return 0;

}