
//Antonio Cleison Alves Silva
#include <stdio.h>
#define FUNCIONARIOS 8
#define MESES 12

int main(){
    
    double salario[FUNCIONARIOS][MESES] = {
        {6000.00, 5800.00, 3600.00, 5700.00, 2500.00, 1900.00, 4100.00, 3000.00, 6200.00, 1300.00, 3300.00, 4800.00},
        {4000.00, 2200.00, 3100.00, 3300.00, 3400.00, 3500.00, 3600.00, 3700.00, 3800.00, 2900.00, 4500.00, 4900.00},
        {5000.00, 3200.00, 3100.00, 2300.00, 5400.00, 3500.00, 6600.00, 6700.00, 6800.00, 1900.00, 4550.00, 4700.00},
        {5000.00, 2100.00, 4200.00, 4300.00, 4400.00, 1500.00, 4600.00, 3700.00, 3800.00, 2900.00, 5125.00, 6000.00},
        {6000.00, 6100.00, 3200.00, 2300.00, 6400.00, 3500.00, 5600.00, 5700.00, 5800.00, 5900.00, 6000.00, 6200.00},
        {3500.00, 5600.00, 4700.00, 4800.00, 4900.00, 6000.00, 5100.00, 2200.00, 5300.00, 5400.00, 5600.00, 6000.00},
        {3500.00, 4600.00, 3700.00, 2800.00, 6900.00, 3000.00, 3100.00, 3200.00, 3300.00, 3400.00, 3500.00, 4000.00},
        {5600.00, 3700.00, 6800.00, 2900.00, 2000.00, 4100.00, 1200.00, 1300.00, 5400.00, 5500.00, 5500.00, 6000.00}
    };
    char nome[FUNCIONARIOS][50] = {"Lia", "Joao", "Guilherme", "Darciara", "Neilson", "Adrian", "Andrey", "Sarana"};
    char sexo[FUNCIONARIOS] = {'F', 'M', 'M', 'F', 'M', 'M', 'M', 'F'};
    int idade[FUNCIONARIOS] = {20, 33, 42, 57, 52, 72, 30, 59};
    

    
    float maiorSalarioIdosas = 4500.00;
    int qtdSalIdosas = 0;
    for (int l = 0; l < FUNCIONARIOS; l++){
        for (int c = 0; c < MESES; c++){
            if (sexo[l] == 'F' && idade[l] > 60 && salario[l][c] > maiorSalarioIdosas){
                qtdSalIdosas++;
            }         
        }
    }

    
    float maiorSalarioHomem = 0;
    int idadeHomem = 0;
    for (int l = 0; l < FUNCIONARIOS; l++){
        for (int c = 0; c < MESES; c++){   
            if (sexo[l] == 'M' && salario[l][c] > maiorSalarioHomem){
                maiorSalarioHomem = salario[l][c];
                idadeHomem = idade[l];
            }
        }
    }

    
    float salarioDeJunho = 999999;
    int menorSalarioJunho = 0;
    for (int l = 0; l < FUNCIONARIOS; l++){
        if (idade[l] >= 30 && idade[l] <= 50 && sexo[l] == 'M'){
            if (salario[l][5] < salarioDeJunho){
                salarioDeJunho = salario[l][5];
                menorSalarioJunho = l;
            }
        }
    }
    
    
    printf("A Quantidade de salarios de idosas acima do valor de R$4500: %d\n", qtdSalIdosas);
    printf("Idade do homem que ganha mais: %d\n", idadeHomem);
    if (menorSalarioJunho != 0){
        printf("Funcionario que ganhou menos em Junho: %s", nome[menorSalarioJunho]);
    }

    return 0;
}