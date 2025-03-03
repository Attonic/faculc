#include<stdio.h>

int main(){

    int ano, ehBi;

    printf("Digite um ano \n");
    scanf("%d", &ano);

    ehBi = (ano % 4 == 0) && (ano % 100 != 1 || ano % 400 == 0);

    if(ano >= 1000 && ano <= 3000){
         if (ehBi == 1){
        printf("O ano %d é bissexto", ano);
        }else{
        printf("Não é bissexto");
        }
    }else{
        printf("O ano é invalido!!");
    }

    return 0;
}