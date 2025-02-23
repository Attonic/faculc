// Antonio Cleison
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

//------------FUNÇÕES--------------
//Cadastrar funcionario
void cadastrar(Funcionario f[], int qtdFunc){
        printf("Preencha as informacoes");
        printf("\nPrimeiro nome: ");
        scanf("%s", f[qtdFunc].primeiroNome);
        printf("Digite o sexo: 1 - F ou 2 - M: ");
        scanf("%d", &f[qtdFunc].sexo);
        printf("Estado civil 1 - Solteiro, 2 - Casado, 3 - divorciado: ");
        scanf("%d", &f[qtdFunc].estCivil);
        printf("Digite o salario: ");
        scanf("%f", &f[qtdFunc].salario);
        printf("Digite a Quantidade de filhos: ");
        scanf("%d", &f[qtdFunc].qtdFilhos);
        printf("Digite a data de nascimento.\nEx: 14 3 1879, Usando espacos: ");
        scanf("%d %d %d", &f[qtdFunc].dtNasc.dia, &f[qtdFunc].dtNasc.mes, &f[qtdFunc].dtNasc.ano);
        
}
//Exibir os dados dos funciorios
void exibir(Funcionario f[], int qtdFunc){
    for (int i = 0; i < qtdFunc; i++) {
        printf("------------------------------\n");
        printf("Funcionario %d.:\n", i+1);
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
            int encontrado = 0;
    for (int i = 0; i < qtdFunc; i++) {
        if(strcmp(f[i].primeiroNome, nome) == 0 ){
            printf("------------------------------\n");
            printf("Funcionario %d. :\n", i+1);
            printf("Primeiro nome: %s\n", f[i].primeiroNome);
            printf("Sexo: %d\n", f[i].sexo);
            printf("Estado civil: %d\n", f[i].estCivil);
            printf("Salario: %.2f\n", f[i].salario);
            printf("Filhos: %d\n",f[i].qtdFilhos);
            printf("Data de nascimento: %d / %d / %d\n",f[i].dtNasc.dia, f[i].dtNasc.mes, f[i].dtNasc.ano);
            printf("------------------------------\n");
            encontrado = 1;
        }
                  
    } 
        if(!encontrado){
            printf("Nome nao encontrado!\n");
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
    int estadoC = 0, encontrado = 0;
    printf("\nDigite o estado civil a buscar:\n1 - Solteiro, 2 - Casado, 3 - divorciado: ");
    scanf("%d", &estadoC);
    for (int i = 0; i < qtdFunc; i++) {
        if(f[i].estCivil == estadoC){
            printf("------------------------------\n");
            printf("Funcionario %d.:\n", i+1);
            printf("Primeiro nome: %s\n", f[i].primeiroNome);
            printf("Sexo: %d\n", f[i].sexo);
            printf("Estado civil: %d\n", f[i].estCivil);
            printf("Salario: %.2f\n", f[i].salario);
            printf("Filhos: %d\n",f[i].qtdFilhos);
            printf("Data de nascimento: %d / %d / %d\n",f[i].dtNasc.dia, f[i].dtNasc.mes, f[i].dtNasc.ano);
            printf("------------------------------\n");
            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("Nao encontrado funcionario com esse eestado civil!\n");
}
}
// ajustar porcentragem
void ajustarSalarioDeUmFunc(Funcionario f[], int qtdFunc){
            char nome[50];
            printf("\nDigite o nome: ");
            scanf("%s", nome);
        for (int i = 0; i < qtdFunc; i++) {
            if(strcmp(f[i].primeiroNome, nome) == 0 ){
               f[i].salario += f[i].salario * 0.10;
               printf("Salario funcionario %s ajustado para %.2f\n", f[i].primeiroNome, f[i].salario);
             }
        }
    
}


//pesquisei essa no google
void limparTela() {
    system("cls");
}

    //----------MAIN-------------
int main(){
    Funcionario func[TAM];
    int op, sair = 0, quantFunc = 0;

    do{
        printf("\n\tSistema de Gestao de Funcionarios.\n");
        printf("\n\t1. Adicionar");
        printf("\n\t2. Exibir todos os Funcionarios");
        printf("\n\t3. Consultar por um nome");
        printf("\n\t4. Total de Filhos dos Funcionarios");
        printf("\n\t5. Exibir por estado civil");
        printf("\n\t6. Adcionar 10%% ao salario de um funcionario");
        printf("\n\t7. Sair");
        printf("\n\tEscolha a opcao: ");
        scanf("%d", &op);
        limparTela();
        //Decidi fazer com switch
        switch (op) {
            case 1:
                    cadastrar(func, quantFunc);
                    quantFunc++;
                    break;
            case 2: //Exibir os funcionarios
                    if (quantFunc > 0){
                        exibir(func, quantFunc); 
                    } else {
                        printf("\n\tNao tem funcionarios cadastrados!\n");
                    }
                    break;

            case 3: //Consulta pelo nome 
                    if (quantFunc > 0){
                        buscarPorNome(func, quantFunc);
                    } else {
                        printf("\n\tNao tem funcionario cadastrados\n");
                    } 
                break;

            case 4: //Total de filhos de todos
                    if (quantFunc > 0){
                        int qtdFilhos = totalDeFilhos(func, quantFunc);
                        printf("\n\tTotal de filhos: %d\n", qtdFilhos);
                    } else {
                        printf("\n\tNao tem funcionario cadastrados\n");
                    }
                break;

            case 5: // 
                    if (quantFunc > 0){
                        buscarPeloEstadoCivil(func, quantFunc);
                    } else {
                        printf("\n\tNao tem funcionario cadastrados\n");
                    };
                break;

            case 6: // 
                    if (quantFunc > 0){
                        ajustarSalarioDeUmFunc(func, quantFunc);
                    } else {
                        printf("\n\tNao tem funcionario cadastrados\n");
                    };
            break;    
            case 7:
                    printf("\n\tSaindo do sistema...\n");
                    sair = 1;
                    break;

            default:
                printf("\n\tOpcao invalida! Tente novamente.\n");
        }

    }while (sair != 1);

    return 0;
    
}