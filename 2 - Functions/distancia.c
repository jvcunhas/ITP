#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define L 3

int produtoCruzado(int mX, int mY, int x1, int y1, int x2, int y2){
    int z = 0;

    z = (((x1 - x2) * (y1 - mY)) - ((y1 - y2) * (x1 - mX)));
    
    return abs(z);
}

float pointDistance(int x1, int y1, int x2, int y2, int z){
    float module = 0.0;
    float distance = 0.0;

    module = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    distance = z / module;

    return distance;
}

int main(){
    int mouseX, mouseY;
    int n, z, j;
    float distancia = 0.0;
    mouseX, mouseY, n, z, j = 0;

    scanf("%d %d", &mouseX, &mouseY);
    scanf("%d", &n);

    int coordX[n];
    int coordY[n];

    scanf("%d %d", &coordX[0], &coordY[0]);        

    for (int i = 1; i < n; i++){
        scanf("%d %d", &coordX[i], &coordY[i]);
        z = produtoCruzado(mouseX, mouseY, coordX[i-1], coordY[i-1], coordX[i], coordY[i]);        
        distancia = pointDistance(coordX[i-1], coordY[i-1], coordX[i], coordY[i], z);
        if (distancia < L){
            j++;
        }
    }
    
    z = produtoCruzado(mouseX, mouseY, coordX[n-1], coordY[n-1], coordX[0], coordY[0]);
    distancia = pointDistance(coordX[n-1], coordY[n-1], coordX[0], coordY[0], z);

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