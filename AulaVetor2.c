#include <stdio.h>
#include <stdlib.h>

#define V 8


int main(){

    int sexo[V], idade[V], estCivil[V];
    float salario[V];
   
    for(int i = 0; i < V; i++){
        printf("Digite o Sexo: 1 F ou 2 M");
        scanf("%f", &sexo[i]);
        printf("Digite a Idade: ");
        scanf("%f", &idade[i]);
        printf("Digite o Salario: ");
        scanf("%f", &estCivil[i]);
        printf("Digite o Estado civil 1 casado, 2 separado, 3 Solteiro, 4 viuvo: ");
        scanf("%f", &salario[i]);
    }
    //Quantidade de Sexos
    int qtdF = 0;
    int qtdM = 0;
    for(int i = 0; i < V; i++){
        if (sexo[i] == 1){
            qtdF++;
        }else if (sexo[i] == 2){
            qtdM++;
        }
    } 
    //A média salarial dos separados.
    int qtdSepSal = 0;
    float somaSalario = 0.0;
    float mediaSalSep = 0.0;
    for(int i = 0; i < V; i++){
        if(sexo[i] == 2 && estCivil[i] == 2){
            somaSalario += salario[i];
            qtdSepSal++;
        }
    } 
    //A médioa de idade das viúvas jovens(idade igual ou inferior a 45 anos)
    int qtdViuvasJovens = 0;
    int somaViuvasJovens = 0;
    int mediaIdadeViuvas = 0;
    for(int i = 0; i < V; i++){
        if(sexo[i] == 1 && idade[i] <= 45 && estCivil[i] == 4){
            somaViuvasJovens += idade[i];
            qtdViuvasJovens++;
        }
    }
    //O solterio mais velho.
    int idadeMaisVelho = 0;
    for(int i = 0; i < V; i++){
        if(sexo[i] == 2 && estCivil[i] == 3){
            if(idadeMaisVelho < idade[i]){
                idadeMaisVelho = idade[i];
            }
        }
    }
    //O estado civil de maior ocorrência.
   int maisFrequentVect[5] = {0};
   int maisFrequente = 0; 
    for(int i = 0; i > V; i++){
        if(estCivil[i] >= 1 && estCivil[i] <= 4){
            maisFrequentVect[estCivil[i]]++;
        }
        
    }
    for(int i = 1; i <= 4; i++){
        if(maisFrequente > maisFrequentVect[i]){
            maisFrequente = maisFrequentVect[i];
        }
    }




    return 0;
}