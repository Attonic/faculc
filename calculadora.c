#include<stdio.h>

int main(){

    float num1, num2, resultado;
    int op;

    printf("Digite dois numeros: ");
    scanf("%f %f", &num1, &num2);

    printf("Escolha uma opção:\n1 = soma\n2 = subtrair\n3 = dividir\n4 = multiplicar\n");
    scanf("%d", &op);

    if (op >= 1 && op <= 4){

         if (op == 1) {
        resultado = num1 + num2;

         }else if (op == 2){
        resultado = num1 - num2;

         }else if(op == 3){
        
            if(num2 != 0){
                resultado = num1 / num2;
            }else{
                prointf("Impossivel divisao por 0!");
            }

         }else if(op == 4){
        resultado = num1 * num2;
         }

    }else{
        printf("Operação invalida!");
    }
     printf("O resultado: %.2f", resultado);

  return 0;
}