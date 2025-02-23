#include<stdio.h>

float calcularMedia(float vect[], int tamanho){
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += vect[i];
    }
    return soma / tamanho;
}

int obterMaior(int vect[], int tam){
    int maior = vect[0];
    for(int i = 1; i < tam; i++){
        if(maior < vect[i]){
            maior = vect[i];
        }
    }
    return maior;
}
int quantasVezesAparece(int vect[], int tam, int num){
    int qtd = 0;
    for (int i = 0; i < tam; i++){
        if(num == vect[i]){
            qtd++;
        }
    }
    return qtd;
}

int ehPar(int num){
    return (num % 2 == 0);
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    if(ehPar(n)){
        printf("Numero é par!\n");
    }else{
        printf("Numero é impar!\n");
    }

    float numeros[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(numeros)/sizeof(numeros[0]);
    float media = calcularMedia(numeros, tamanho);
    printf("Média = %.2f\n", media);

    int valores[] = {10, 4, 30, 40, 4, 8, 10, 4};
    int tam = sizeof(valores)/sizeof(valores[0]);
    int maior = obterMaior(valores, tam);
    printf("Maior = %d\n", maior);

    int qtdVezes = quantasVezesAparece(valores, tam, 4);
    printf("Quantidade que aparece é: %d", qtdVezes);
    return 0;
}
