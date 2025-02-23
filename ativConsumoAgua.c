
//Antonio Cleison Alves Silva
#include<stdio.h>
#include<stdlib.h>


#define ANOS 100
#define MESES 12

int main(){

    float consumos[ANOS][MESES];
    float mediaMensal[ANOS];

    for (int i = 0; i < ANOS; i++){
        for (int j = 0; j < MESES; j++){
            consumos[i][j] = rand() % 201;
        }
    }

    for (int i = 0; i < ANOS; i++){
        float somaConsumo = 0.0;
        for (int j = 0; j < MESES; j++){
            somaConsumo += consumos[i][j];
        }
        mediaMensal[i] = somaConsumo / MESES;
        printf("Ano %d - Média Mensal: %.2f\n", i + 1, mediaMensal[i]);
        
    }

    float maiorConsumo = 0.0;
    int anoComMaiorConsumo = 0;
    for (int i = 0; i < ANOS; i++){
            for (int j = 0; j < MESES; j++){
                if (consumos[i][j] > maiorConsumo){
                    maiorConsumo = consumos[i][j];
                    anoComMaiorConsumo = i + 1;
                }
                
            }
           
            
        }
        printf("O ano com o maior consumo mensal foi o ano %d, com um consumo de %.2f\n", anoComMaiorConsumo, maiorConsumo);
    

    return 0;
}