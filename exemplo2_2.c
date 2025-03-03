#include<stdio.h>

int main(){

    int num = 0, numPares = 0, numPositivos = 0, numNegativos = 0, soma = 0;
    int i = 1;
    

    for(int i = 0; i <= num; i++){
        
    }
    do {
        printf("Escreva um numero: ");
        scanf("%d", &num);

        if (num != 999) {
            soma += num;

            if(num % 2 == 0){
                numPares++;
            }
            if(num > 0){
                numPositivos++;
            }
            if(num < 0){
                numNegativos++;
            }
        }
        i++;
    } while (num != 999);

    printf("Numeros pares %d\n", numPares);
    printf("Numeros positivos: %d\n", numPositivos);
    printf("Quantidade de numeros negativos: ", numNegativos);
    printf("Soma de numeros  %d\n", soma);
    
    return 0;
}