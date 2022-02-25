#include <stdio.h>
#include <math.h>

char testeReta(int mX, int mY, int x1, int y1, int x2, int y2){
    float m, m1, m2;
    float equation = 0;
    char output = ' ';
    m, m1, m2 = 0.0;

    if (x1 != x2){
        m1 = (y2 - y1);
        m2 = (x2 - x1);

        m = (m1 / m2);

        equation = (m * (mX - x1) + y1);

        if (ceil(equation) == mY){
            output = 'S';
        }
    } else {
        if (mX == x1){
            output = 'S';
        }
    }
    return output;
}


int main(){
    int mouseX, mouseY;
    int n;
    int coordX1, coordY1, coordX2, coordY2, pcoordX, pcoordY;
    char saida = ' ';
    char final = ' ';
    mouseX, mouseY, coordX1, coordY1, coordX2, coordY2, pcoordX, pcoordY, n = 0;

    scanf("%d %d", &mouseX, &mouseY);
    scanf("%d", &n);
    scanf("%d %d", &pcoordX, &pcoordY);

    coordX1 = pcoordX;
    coordY1 = pcoordY; 

    for (int i = 1; i < n; i++){
        scanf("%d %d", &coordX2, &coordY2);
        saida = testeReta(mouseX, mouseY, coordX1, coordY1, coordX2, coordY2);
        coordX1 = coordX2;
        coordY1 = coordY2;

        if (saida == 'S'){
            final = saida;
        }
    }

    saida = testeReta(mouseX, mouseY, pcoordX, pcoordY, coordX1, coordX2);

    if (saida == 'S'){
        final = saida;
    }

    if (final == 'S')
        printf("%c\n", final);
    else{
        printf("N\n");
    }

    return 0;

}