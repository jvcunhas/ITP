#include <stdio.h>
#include <math.h>

void fill_x(double *x, int n){
    if (n == 0){
        return;
    }

    scanf("%lf", &x[n-1]);
    return fill_x(x, n-1);
}

double sum_x1(double x1, double *x, int n){
    if (n == 0){
        return 0;
    }

    x1 = pow(x[n-1], 2);
    return x1 + sum_x1(x1, x, n-1);

}

double sum_x2(double x2, double *x, int n){
    if (n == 0){
        return 0;
    }

    x2 = x[n-1];
    return x2 + sum_x2(x2, x, n-1);

}

double result(double x1, double x2, double n){
    double result = 0;
    double p1 = (x1/n);
    double p2 = pow(x2/n, 2);
    
    result = sqrt(p1 - p2);

    return result;
}

int main(){
    int n = 0;
    double x1 = 0;
    double x2 = 0;

    scanf("%d", &n);
    double x[n];

    fill_x(x, n);
    x1 = sum_x1(x1, x, n);
    x2 = sum_x2(x2, x, n);

    printf("%.4f\n", result(x1, x2, n));

    return 0;
}