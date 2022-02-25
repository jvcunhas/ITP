#include <stdio.h>
#include <string.h>

int diadasemana(char *entrada, char **saida, int *bissexto) {
    int d = 0, m = 0, y = 0;
    int dia_semana = 0;

    sscanf(entrada,"%d/%d/%d", &d, &m, &y);
    //printf("Dia: %d - Mês: %d - Ano: %d\n", d,m,y);

    if(m == 0 && y == 0){
        return -2;
    }

    if((y % 4 ==0) && ((y % 400 ==0) || (y % 100 !=0))){
        *bissexto = 1;
    } else {
        *bissexto = 0;
    }

    if(!(m <= 12 && m > 0)){
        return -1;
    }

    if(!(d <= 31 && m > 0)){
        return -1;
    }

    if(m == 2){
        if(bissexto == 0 && d > 28){
            return -1;
        }
    } else if(m == 4 || m == 6 || m == 9 || m == 11){
        if(d >= 31){
            return -1;
        }
    }

    dia_semana = (23*m/9+d+4+(m<3?y--:y-2)+y/4-y/100+y/400)%7;

    switch (dia_semana)
    {
    case 0:
        *saida = "Domingo";
        break;
    case 1:
        *saida = "Segunda";
        break;
    case 2:
        *saida = "Terça";
        break;
    case 3:
        *saida = "Quarta";
        break;
    case 4:
        *saida = "Quinta";
        break;
    case 5:
        *saida = "Sexta";
        break;
    case 6:
        *saida = "Sabado";
        break;
    }

    //bissexto = bis;

    return 1;
}

int main(){
    int status=0, bissexto=0;
    char entrada[11]={0}, *saida=NULL;
    fgets(entrada,11,stdin);
        
    status = diadasemana(entrada, &saida, &bissexto);
        
    if (status>0)
        printf("%s.%s\n", saida, 
            bissexto? " Ano bissexto." : "");
    else {
        if (status==-1)
            printf("Data inexistente.\n");
        else
            printf("Entrada invalida.\n");
        return 1;
    }

    return 0;
}