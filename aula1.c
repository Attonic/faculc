#include<stdio.h>

int main(){

    float salarios [] = {2100, 2500, 2000, 3000, 2800, 2450, 2950, 3100, 3050, 2000};

    float soma = 0, media = 0, maior = 0, menor = 0;

    for(int i = 0; i  < 10; i++){
        soma += salarios[i];
        if(salarios[i] > maior){
            maior = salarios[i];
        }
        if(salarios[i] < maior){
            menor = salarios[i];
        }
    }

    

    media = soma / 10;

    printf("Media do salario e %.2f\n", media);
    printf("O maior salario e: %.2f\n", maior);
    printf("O menor salrio e: %.2f", menor);

    return 0;
}

