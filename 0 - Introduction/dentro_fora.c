#include <stdio.h>

int main(){
    int x1, y1, x2, y2 = 0;
    int cx, cy = 0;
    int aux = 0;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d", &cx, &cy);

    if (y2 > y1){
        aux = y1;
        y1 = y2;
        y2 = aux;
    }

    if (cx >= x1 && cx <= x2 && cy <= y1 && cy >= y2 ){
        printf("Dentro!\n");
    }
    else{
        printf("Fora!\n");
    }
    return 0;
}