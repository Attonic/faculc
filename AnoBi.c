#include<stdio.h>

int main(){

    int ano, ehBi;

    printf("Digite um ano \n");
    scanf("%d", &ano);

    ehBi = (ano % 4 == 0) && (ano % 100 != 1 || ano % 400 == 0);

    printf("O ano %d é bissexto? %d", ano, ehBi);



    return 0;
}
