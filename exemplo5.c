#include<stdio.h>

int main(){

    float nota1, nota2, nota3, media;

    printf("Digite as 3 notas ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    media = (nota1 + nota2 + nota3) / 3;
    printf("Media = %.2f\n", media);
    if (media >= 7) {
        printf("Aluno aprovado!");
    }else if (media>= 5){
        printf("Aluno em recuperacao");
    }else{
        printf("Aluno reprovado");
    }
   

    return 0;
}