#include <stdio.h>

typedef struct team{
    char nome[200];
    int pontos;
    int tot_partidas;
    int vitorias;
    int empates;
    int derrotas;
    int gol_feitos;
    int gol_sofridos;
    int saldo_gols;
} Time;

void ordenar_tabela(Time* vet, int tam){
    Time aux;
    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(vet[i].pontos > vet[j].pontos){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
            else if(vet[i].pontos == vet[j].pontos && vet[i].vitorias > vet[j].vitorias){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
	        else if(vet[i].pontos == vet[j].pontos && vet[i].vitorias == vet[j].vitorias && vet[i].saldo_gols > vet[j].saldo_gols){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void ler_times(int quantidade, Time *times){
    for(int i = 0; i < quantidade; i++){
        scanf("%[^;]s", times[i].nome);
        scanf("; %d %d %d %d %d", &times[i].vitorias, 
        &times[i].empates, &times[i].derrotas, &times[i].gol_feitos, &times[i].gol_sofridos);
    }
}

void print_tabela(Time *times, int tamanho){
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols");
    for(int i = tamanho-1; i >= 0; i--){
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d", times[i].nome, times[i].pontos, 
        times[i].tot_partidas, times[i].vitorias, times[i].empates, times[i].derrotas, times[i].gol_feitos,
        times[i].gol_sofridos, times[i].saldo_gols);
    }
    
    printf("\n\nTimes na zona da libertadores:");
    for(int i = tamanho-1; i >= tamanho-6; i--){
        printf("%s", times[i].nome);
    }

    printf("\n\nTimes rebaixados:");
    for(int i = 0; i < 4; i++){
        printf("%s", times[i].nome);
    }
}

int main (){
    int t;

    scanf("%d", &t);
    Time times[t];

    ler_times(t, times);
    
    for(int i = 0; i < t; i++){
        times[i].pontos = (times[i].vitorias * 3) + (times[i].empates);
        times[i].tot_partidas = times[i].vitorias + times[i].derrotas + times[i].empates;
        times[i].saldo_gols = times[i].gol_feitos - times[i].gol_sofridos;
    }

    ordenar_tabela(times, t);
    print_tabela(times, t);
    
    return 0;
}