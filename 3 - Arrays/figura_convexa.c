#include <stdio.h>

int testados = 0;


int dotProduct(int mX, int mY, int x1, int y1, int x2, int y2){
    int z = 0;

    z = ((x2 - x1) * (mY - y2) - (y2 - y1) * (mX - x2));

    return z;
}

int isInRight(int mX, int mY, int x1, int y1, int x2, int y2){
    int z = 0;

    z = dotProduct(mX, mY,x1, y1, x2, y2);

    if(z < 0){
        return 1;
    } else {
        return 0;
    }
}

void isInsideForm(int mX, int mY, int x1, int y1, int x2, int y2){
    int testarpontos = 0;

    testarpontos = isInRight(mX, mY, x1, y1, x2, y2);

    if(testarpontos == 1){
        testados++;
    }

}

int main(){
    int n, m;
    
    n = m = 0;

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
    }

    //lendo os pontos do mouse
    for(int i = 0; i < m; i++){
        scanf(" %c %d %d", &identificador[i], &mousesX[i], &mousesY[i]);
    }

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            isInsideForm(mousesX[i], mousesY[i], coordsX[j], coordsY[j], coordsX[j+1], coordsY[j+1]);
        }
        isInsideForm(mousesX[i], mousesY[i], coordsX[n], coordsY[n], coordsX[0], coordsY[0]);

        if (testados >= n){
            printf("%c\n",identificador[i]);
        }

        testados = 0;
    }
    return 0;
}