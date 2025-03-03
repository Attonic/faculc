#include<stdio.h>

int main(){

    float horatrampo, saLiquido, saBruto, iR, horaPaga;
    

    printf("Digite o valor da hora: ");
    scanf("%f", &horaPaga);

    printf("Digite quantas horas trabalhou: ");
    scanf("%f", &horatrampo);

    saBruto = horatrampo * horaPaga;
    iR =  saBruto * 0.08;

    if(saBruto >= 1800.00){
        saLiquido = saBruto - iR;
    }else{
        saLiquido = saBruto;
    }

    printf("O salario bruto é: %.2f", saBruto);
    printf("\nO salario liquido é: %.2f", saLiquido);
    printf("\nValor do imposto: %.2f", iR);

    return 0;
}