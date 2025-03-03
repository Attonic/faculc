#include<stdio.h>
#include<stdlib.h>

int main (){

    float notaAlunos[40][3];


    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            notaAlunos[i][j] = rand()%11;
        }
    }
    for(int i =0; i < 40; i++){
        printf("Aluno %d: ", (i+1));
        for (int j = 0; j < 3; j++) {
            printf("\t%.2f", notaAlunos[i][j]);
        }
        printf("\n");
    }
    int qtdNotas10 = 0, qtdNotaBaixa = 0;
    for(int i = 0; i < 40; i++){
        for (int j = 0; i < 3; j++){
            if(notaAlunos[i][j] <= 6){
                qtdNotaBaixa++;
            }
            if(notaAlunos[i][j] == 10){
                qtdNotas10++;
            }
        }
        
    }
    printf("Quantidade de notas 10 e: %d\n", qtdNotas10);
    printf("Quantidade de notas baixas: %d\n", qtdNotaBaixa);


    return 0;
}