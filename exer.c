#include<stdio.h>

#define TAM 8
int main(){
    
    int sexo[TAM], idade[TAM], estadoCivil[TAM];
    float salario[TAM];
    
    int qtdF = 0, qtdM = 0;

    for(int i = 0; i < TAM; i++){
        printf("\nDigite dados da pessoa: \nSexo 1 = F ou 2 = M: ");
        scanf("%d", &sexo[i]);

        printf("Salario: ");
        scanf("%f", &salario[i]);

        printf("Digite a idade: ");
        scanf("%d", &idade[i]);

        printf("Estado Civil 1 = Casado, 2 = Separado, 3 = Solteiro, 4 = Viuvo: ");
        scanf("%d", &estadoCivil[i]);
    }

    for (int i = 0; i < TAM; i++){
        printf("Pessoa: %d\n", (i+1));
        printf("Sexo: %d\n", sexo[i]);
        printf("Idade: %d\n", idade[i]);
        printf("Salario: %.2f\n", salario[i]);
        printf("E. Civil %d\n", estadoCivil[i]);
        printf("----------------------\n");
    }
    

    for (int i = 0; i < TAM; i++){
       if(sexo[i] == 1){
            qtdF++;
        }else if (sexo[i] == 2){
            qtdM++;
        }
    }

    //Média e soma dos separados
    float somaSeparados = 0, mediaSeparados = 0;
    int qtdSep = 0;
    for(int i = 0; i < TAM; i++){
        if (estadoCivil[i] == 2 && sexo[i] == 2){
           somaSeparados += salario[i];
           qtdSep++;
        }
    } 
            if (qtdSep > 0){
                mediaSeparados = somaSeparados / qtdSep; 
            }else{
                mediaSeparados = 0;
            }
        
    //Vivuvas, soma de idades e média
    float somaIdadeViuvas = 0, mediaIdadeViuvas = 0;
    int qtdViuvas = 0;
    for(int i = 0; i < TAM; i++){
        if(sexo[i] == 1 && estadoCivil[i] == 4 && idade[i] <= 45 ){
            somaIdadeViuvas += idade[i];
            qtdViuvas++;
        }
    }
            if(qtdViuvas > 0){
                mediaIdadeViuvas = somaIdadeViuvas / qtdViuvas;
            }else{
                mediaIdadeViuvas = 0;
            }
            
    //O solteiro mais velho
    int maisVelhoSolteiro = 0;
     for(int i = 0; i < TAM; i++){
         if(sexo[i] == 2 && estadoCivil[i] == 3){
            if(idade[i] > maisVelhoSolteiro){
                maisVelhoSolteiro = idade[i];
            }
        } 
    }
    //O Estado civil mais frequente.:> b
    int estadoVect[5] = {0};
    int maisFrequente = 1, iMaisFrequente = 0;
  
    for (int i = 0; i < TAM; i++){
        estadoVect[estadoCivil[i]]++;
    }
    
    for(int i = 1; i <= 4; i++){
        if(estadoVect[i] > maisFrequente){
            maisFrequente = estadoVect[1];
            iMaisFrequente = i;
        }
    }

    printf("A quantidade de sexo masculino e: %d\nO quantidade de sexo feminino e: %d\n", qtdM, qtdF);
    printf("Media de salarial dos Separado: %.2f\n", mediaSeparados);
    printf("A media da idade das viuvas e: %f\n", mediaIdadeViuvas);
    printf("O solteiro mais velho: %d\n", maisVelhoSolteiro);
    printf("O estado civil de mais ocorrencia: %d\n", maisFrequente);

    return 0;
}