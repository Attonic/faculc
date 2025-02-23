#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    float notaAlunos[40][3];
    srand(time(NULL)); 

   
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 3; j++){
            notaAlunos[i][j] = rand() % 11; 
        }
    }

   
    for(int i = 0; i < 40; i++){
        printf("Aluno %d: ", (i + 1));
        for (int j = 0; j < 3; j++) {
            printf("\t%.2f", notaAlunos[i][j]);
        }
        printf("\n");
    }

   
    int qtdNotas10 = 0, qtdNotaBaixa = 0;
    for(int i = 0; i < 40; i++){
        for (int j = 0; j < 3; j++){
            if(notaAlunos[i][j] <= 6){
                qtdNotaBaixa++;
            }
            if(notaAlunos[i][j] == 10){
                qtdNotas10++;
            }
        }
    }


    float medias[40] = {0}, somaNotas = 0;
    for(int i = 0; i < 40; i++){
        float qtdReprovados = 0;
        for (int j = 0; j < 3; j++){
            somaNotas += notaAlunos[i][j];
        }
       medias[i] = somaNotas / 3;
    }

    int qtdAprovados = 0, qtdReprovados = 0;
    for(int i = 0; i < 40; i++){
        if(medias[i] >= 7){
            qtdAprovados++;
        }else{
            qtdReprovados++;
        }
    }


    printf("Quantidade de notas 10 e: %d\n", qtdNotas10);
    printf("Quantidade de notas baixas (<= 6): %d\n", qtdNotaBaixa);
    printf("Quantidade de alunos aprovados (media >= 7): %d\n", qtdAprovados);
    printf("Quantidade de alunos reprovados (media < 6): %d\n", qtdReprovados);

    return 0;
}
