#include<stdio.h>
#include<math.h>

int main(){

    float imc, peso, altura;
    int i = 1;

    do{
        printf("Peso: ");
        scanf("%f", &peso);

        printf("Altura: ");
        scanf("%f", &altura);

        imc = peso / (altura * altura);
        printf("Imc: %.2f\n", imc);

        if(imc > 29){
            printf("Acima do peso!");
        }else{
            printf("Em forma! ");
        }
        i++;
    }while(i <= 5);
    
    return 0;
}