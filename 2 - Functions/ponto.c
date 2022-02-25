#include <stdio.h>
#include <math.h>

float pointDistance(int mX, int mY, int x, int y){
    float distance = 0.0;
    distance = sqrt(pow(mX - x, 2) + pow(mY - y, 2));
    return distance;
}

int main(){
    #define L 3
    int mouseX, mouseY;
    int coordX, coordY;
    int n;
    int j;
    float distance = 0.0;

    mouseX, mouseY, coordX, coordY, n, j = 0;

    scanf("%d %d", &mouseX, &mouseY);
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d %d", &coordX, &coordY);
        distance = pointDistance(mouseX, mouseY, coordX, coordY);

        if (distance <= L){
            j++;
        }
    }    
    
    if (j > 0){
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}