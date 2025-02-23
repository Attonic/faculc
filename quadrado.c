#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 3

int somasLinhasIguais(int num[TAM][TAM], int somQuaM){
    int somaLinhas[TAM] = {0};
    for(int l = 0; l <  TAM; l++){
        for(int c = 0; c < TAM; c++){
            somaLinhas[l] += num[l][c];
        }
        if (somaLinhas[l] != somQuaM){
            return 0;
        }
    }
    return 1;
}
int somasColunasIguais(int num[TAM][TAM], int somQuaM){
    int somaColunas[TAM] = {0};
    for(int c = 0; c <  TAM; c++){
        for(int l = 0; l < TAM; l++){
            somaColunas[c] += num[l][c];
        }
        if (somaColunas[c] != somQuaM){
            return 0;
        }
    }
    return 1;
}
int somaDiagonalPIgual(int num[TAM][TAM], int somQuaM){
    int somaDiagonalPrincipal = 0;
    for(int i = 0; i < TAM; i++){
        somaDiagonalPrincipal += num[i][i];
    }
    return (somaDiagonalPrincipal == somQuaM);
}

int somaDiagonalSecundaria(int num[TAM][TAM], int somQuaM){
    int somaDiagonalSecundaria = 0;
    for(int l = 0, c = 2; l < TAM; l++, c--){
        somaDiagonalSecundaria += num[l][c];
    }
    return (somaDiagonalSecundaria == somQuaM);
}
void preencher(int num[TAM][TAM]){
    for(int l = 0; l <  TAM; l++){
        for(int c = 0; c < TAM; c++){
            num[l][c] = rand()%11;
        }
    }
}
void mostrar(int num[TAM][TAM]){
    for(int l = 0; l <  TAM; l++){
        for(int c = 0; c < TAM; c++){
            printf("\t%d", num[l][c]);
        }
        printf("\n");
    } 
}
int main(){
    srand(time(NULL));
     int numeros[TAM][TAM];
     //= {
    //     {2, 9, 4},
    //     {7, 5, 3},
    //     {6, 1, 8}
    // };
     preencher(numeros);
    //mostrar(numeros);
    int qtdQuaMagic = 0;
    for (int i = 0; i < 1000; i++){
    
    
        int somaQMagico = 0;
        for (int c = 0; c < TAM; c++){
            somaQMagico += numeros[0][c];
        }
        // printf("\n\t\tSomaQMagico: %d", somaQMagico);

        int ehMagic = somasLinhasIguais(numeros, somaQMagico) && somasColunasIguais(numeros, somaQMagico) && somaDiagonalPIgual(numeros, somaQMagico) && somaDiagonalSecundaria(numeros, somaQMagico);

        if(ehMagic == 1){
            qtdQuaMagic++;
        }
        // else{
        //     printf("\n Não eh magico");
        // }
        return 0;
    }    
}