//Antonio Cleison Alves Silva

#include<stdio.h>

int main(){

    float valorEmprestimo, valorParcelas, salario;
    int numParcelas;

    printf("Digite o valor do emprestimo desejado: ");
    scanf("%f", &valorEmprestimo);

    printf("\nDigite o numero de parcelas desejadas: ");
    scanf("%d", &numParcelas);

    printf("\nDigite o valor do seu salario: ");
    scanf("%f", &salario);

    valorParcelas = valorEmprestimo / numParcelas;

    if(salario * 0.35 < valorParcelas){
        printf("O emprestimo foi negado!\n");
        
    }else{
        printf("Emprestimo concedido: \n");
    }
    printf("Valor das parclas: %.2f de %d vezes", valorParcelas, numParcelas);


    return 0;
}