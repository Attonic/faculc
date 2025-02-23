
//Antonio Cleison Alves Silva
#include<stdio.h>
#include<stdlib.h>

#define ALUNOS 10
#define NOTAS 3
int main(){

    float alunosNotas [ALUNOS][NOTAS];
    
    
    for(int i = 0; i < ALUNOS; i++){
        for(int j = 0; j < NOTAS; j++){
             alunosNotas[i][j] =  rand() % 11; 
        }
    }

    int melhorNota = alunosNotas[0][0];
    int alunoMelhorNota = 0;
    int melhorNotaAluno = 0;
    for(int i = 0; i < ALUNOS; i++){
        for(int j = 0; j < NOTAS; j++){
            if(alunosNotas[i][j] > melhorNota){
                melhorNota = alunosNotas[i][j];
                alunoMelhorNota = i;
                melhorNotaAluno = j;
            }
        }
    }

    int qtdNotaMenor = 0; //entre 0 e 5
    for(int i = 0; i < ALUNOS; i++){
        for(int j = 0; j < NOTAS; j++){
            if(alunosNotas[i][j] >= 0  && alunosNotas[i][j] <= 5){
                qtdNotaMenor++;
            }
        }
    }
    
    float alunoMedias[ALUNOS];
    float melhorMedia = 0.0;
    int alunoMelhorMedia = 0;

    for(int i = 0; i < ALUNOS; i++){
        float soma = 0.0;
        for(int j = 0; j < NOTAS; j++){
            soma += alunosNotas[i][j];
        }
        alunoMedias[i] = soma / NOTAS;
        if(alunoMedias[i] > melhorMedia){
            melhorMedia = alunoMedias[i];
            alunoMelhorMedia = i;
        }
    }
    

    printf("Notas do aluno com melhor media: %.2f sao:\n", melhorMedia);
    for (int j = 0; j < NOTAS; j++) {
        printf("%.2f ", alunosNotas[alunoMelhorMedia][j]);
    }
    printf("\n");
    printf("A melhor nota foi %d, obtida pelo aluno %d na nota %d\n", melhorNota, alunoMelhorNota + 1, melhorNotaAluno + 1);
    printf("Quantidade de notas entre 0 e 5: %d\n", qtdNotaMenor);
    return 0;
}