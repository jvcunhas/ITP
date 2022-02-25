#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define L 3

int dotProduct(int mX, int mY, int x1, int y1, int x2, int y2){
    int p1 = 0;
    int p2 = 0;

    p1 = ((x2 - x1) * (mX - x2) + (y2 - y1) * (mY - y2));
    p2 = ((x1 - x2) * (mX - x1) + (y1 - y2) * (mY - y1));

    if (p1 > 0 || p2 > 0){
        return 1;
    } else {
        return 0;
    }
}

float produtoCruzado(int mX, int mY, int x1, int y1, int x2, int y2){
    int z = 0;
    float module = 0.0;
    float p = 0.0;

    z = (((x1 - x2) * (y1 - mY)) - ((y1 - y2) * (x1 - mX)));
    module = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    p = abs(z) / module;

    return p;
}

float pointDistance(int x1, int y1, int x2, int y2){
    float distance = 0.0;

    distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return distance;
}

int main(){
    int mouseX, mouseY;
    int n, j, p;
    float distancia = 0.0;
    mouseX = mouseY = n = j = p = 0;

    scanf("%d %d", &mouseX, &mouseY);
    scanf("%d", &n);

    int coordX[n];
    int coordY[n];

    scanf("%d %d", &coordX[0], &coordY[0]);        

    for (int i = 1; i < n; i++){
        scanf("%d %d", &coordX[i], &coordY[i]);
               
        p = dotProduct(mouseX, mouseY, coordX[i-1], coordY[i-1], coordX[i], coordY[i]); 

        if (p == 1){
            distancia = pointDistance(mouseX,mouseY,coordX[i-1], coordY[i-1]);
        } else {
            distancia = produtoCruzado(mouseX, mouseY, coordX[i-1], coordY[i-1], coordX[i], coordY[i]);
        }
        if (distancia < L){
            j++;
        }
    }

    p = dotProduct(mouseX, mouseY, coordX[n-1], coordY[n-1], coordX[0], coordY[0]); 

    if (p == 1){
        distancia = pointDistance(mouseX, mouseY, coordX[0], coordY[0]);
    } else {
        distancia = produtoCruzado(mouseX, mouseY, coordX[n-1], coordY[n-1], coordX[0], coordY[0]);
    }

    if (distancia < L){
        j++;
    }

    if (j > 0){
        printf("S\n");
    } else{
        printf("N\n");
    }
    
    return 0;
}