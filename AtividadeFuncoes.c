#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define TAM 100
typedef struct{
  int dia, mes, ano;  
}Data;

typedef struct{
    char primeiroNome[50];
    int sexo;
    int estCivil;
    float salario;
    int qtdFilhos;
    Data dtNasc;
}Funcionario;

//funcões
//Cadastrar funcionario
void cadastrar(Funcionario f[], int qtdFunc){
    
        printf("Primeiro nome: ");
        scanf("%s", f[qtdFunc].primeiroNome);
        printf("Digite o sexo: 1 - F ou 2 - M: ");
        scanf("%d", &f[qtdFunc].sexo);
        printf("Estado cívil 1 - Solteiro, 2 - Casado, 3 - divorciado: ");
        scanf("%d", &f[qtdFunc].estCivil);
        printf("Digite o salario: ");
        scanf("%f", &f[qtdFunc].salario);
        printf("Digite a Quantidade de filhos: ");
        scanf("%d", &f[qtdFunc].qtdFilhos);
        printf("Digite a data de nascimento.\n Com espaços: dia mes ano: ");
        scanf("%d %d %d", &f[qtdFunc].dtNasc.dia, &f[qtdFunc].dtNasc.mes, &f[qtdFunc].dtNasc.ano);

}
//Exibir os dados dos funciorios
void exibir(Funcionario f[], int qtdFunc){
    for (int i = 0; i < qtdFunc; i++) {
        printf("------------------------------\n");
        printf("Funcionario %d. :\n", i+1);
        printf("Primeiro nome: %s\n", f[i].primeiroNome);
        printf("Sexo: %d\n", f[i].sexo);
        printf("Estado civil: %d\n", f[i].estCivil);
        printf("Salario: %.2f\n", f[i].salario);
        printf("Filhos: %d\n",f[i].qtdFilhos);
        printf("Data de nascimento: %d / %d / %d\n",f[i].dtNasc.dia, f[i].dtNasc.mes, f[i].dtNasc.ano);
        printf("------------------------------\n");
    }
}
//Buscar por nome
void buscarPorNome(Funcionario f[], int qtdFunc){
            char nome[50];
            printf("\nDigite o nome: ");
            scanf("%s", nome);
    for (int i = 0; i < qtdFunc; i++) {
        if(strcmp(f[i].primeiroNome, nome) == 0 ){
            printf("------------------------------\n");
            printf("Funcionário %d. :\n", i+1);
            printf("Primeiro nome: %s\n", f[i].primeiroNome);
            printf("Sexo: %d\n", f[i].sexo);
            printf("Estado civil: %d\n", f[i].estCivil);
            printf("Salário: %.2f\n", f[i].salario);
            printf("Filhos: %d\n",f[i].qtdFilhos);
            printf("Data de nascimento: %d / %d / %d\n",f[i].dtNasc.dia, f[i].dtNasc.mes, f[i].dtNasc.ano);
            printf("------------------------------\n");
        }
    }  

}
//Total de filhos
int totalDeFilhos(Funcionario f[], int qtdFunc){
    int qtdFilhos = 0;

    for (int i = 0; i < qtdFunc; i++){
        if(f[i].qtdFilhos != 0){
            qtdFilhos += f[i].qtdFilhos;
        }  
    }
    return qtdFilhos;

}
//Pelo Estado civil
void buscarPeloEstadoCivil(Funcionario f[], int qtdFunc){
    int estadoC = 0;
    printf("Digite o estado civil a buscar: 1 - Solteiro, 2 - Casado, 3 - divorciado");
    scanf("%d", &estadoC);
    for (int i = 0; i < qtdFunc; i++) {
        if(f[i].estCivil == estadoC){
            printf("------------------------------\n");
            printf("Funcionário %d. :\n", i+1);
            printf("Primeiro nome: %s\n", f[i].primeiroNome);
            printf("Sexo: %d\n", f[i].sexo);
            printf("Estado civil: %d\n", f[i].estCivil);
            printf("Salário: %.2f\n", f[i].salario);
            printf("Filhos: %d\n",f[i].qtdFilhos);
            printf("Data de nascimento: %d / %d / %d\n",f[i].dtNasc.dia, f[i].dtNasc.mes, f[i].dtNasc.ano);
            printf("------------------------------\n");
    }

    }
}
// ajustar porcentragem
void ajustarSalarioDeUmFunc(Funcionario f[], int qtdFunc){
    for (int i = 0; i < qtdFunc; i++) {
        f[i].salario += f[i].salario * 0.10;
    }
    printf("Salários ajustados!\n");
}


int main(){
    Funcionario func[TAM];
    int opc, sair = 0, quantFunc = 0;

    do{
        printf("\n\tSistema de Gestão de Funcionários.\n");
        printf("\n\t1. Adicionar");
        printf("\n\t2. Consultar todos os Funcionários");
        printf("\n\t3. Consultar por nome");
        printf("\n\t4. Total de Filhos dos Funcionários");
        printf("\n\t5. Consultar por estado civil");
        printf("\n\t7. Sair\n");
        scanf("%d", &opc);
        if (opc == 1){ 
            cadastrar(func, quantFunc); 
            quantFunc++;
        } else if(opc == 2){ 
            if (quantFunc > 0){
                exibir(func, quantFunc); 
            } else {// buscar por nome
                printf("\n\tNão há funcionários cadastrados!\n");
            }
        } else if (opc == 3){ 
            if (quantFunc > 0){
                buscarPorNome(func, quantFunc);
            } else {//Total de Filhos dos Funcionários
                printf("\n\tNão tem funcionario cadastrados\n");
            }            
        } else if(opc == 4){ 
            if (quantFunc > 0){
                int qtdFilhos = totalDeFilhos(func, quantFunc);
                printf("Total de filhos: %d", qtdFilhos);
            } else {
                printf("\n\tNão tem funcionario cadastrados\n");
            }//Consultar por estado civil
        } else if(opc == 5){ 
            if (quantFunc > 0){
                buscarPeloEstadoCivil(func, quantFunc);
            } else {
                printf("\n\tNão tem funcionario cadastrados\n");
            }// sair
        } else if(opc == 7){ 
            sair = 1;
        } else {
            printf("\n\nOpção inválida!");
        }
    }while (sair != 1);

    return 0;
}