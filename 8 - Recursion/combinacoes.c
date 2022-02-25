#include <stdio.h>

void read_values(int values[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &(values[i]));
    }
}
void print_values(int current[], int n) {
    printf("<%d", current[0]);
    for (int i = 1; i < n; i++) {
        printf(", %d", current[i]);
    }
    printf(">\n");
}

void combinations(int values[], int current[], int n, int i) {
    if (i > 0) {
        if (i == n) {
            if (current[i - 1] < values[i - 1]) {
                print_values(current, n);
                current[i - 1] += 1;
                combinations(values, current, n, i);
            } else {
                current[i - 1] = 0;
                combinations(values, current, n, i - 1);
            }
        } else {
            if (current[i - 1] < (values[i - 1] - 1)) {
                current[i - 1] += 1;
                combinations(values, current, n, n);
            } else {
                current[i - 1] = 0;
                combinations(values, current, n, i - 1);
            }
        }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int values[n];
    int current[n];

    read_values(values, n);
    combinations(values, current, n, n);
    return 0;
}