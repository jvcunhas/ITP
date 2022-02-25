#include <stdio.h>

int main(){
    int n, corrida, salto, lanc;
    char equipes;

    n = corrida = salto = lanc = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        do{
            scanf(" %c", &equipes);

            switch (equipes)
            {
                case 'C': corrida++; break;
                case 'S': salto++; break;
                case 'L': lanc++; break;
            }
        } while(equipes != 'F');
    } 

    printf("%d %d %d %d\n", corrida, salto, lanc, corrida+salto+lanc);

    return 0;
}