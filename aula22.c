#include<stdio.h>>

void saudacao(){
    printf("Exemplo de funcao C!");
}
void mensagem(char msg[100]){
printf("\n%s", msg);
}

void somar(int a, int b){
    int result = a + b;
    printf("Soma de  %d e %d = %d\n", a,b,result);
}
int subtrair (int a, int b){
    return a - b;
}


void main(){
    int resultado = subtrair(20, 10);
    printf("O resultado é\n", resultado);
    somar(19, 1);
    saudacao();
    mensagem("kkkkkkk");
    char texto[100] = "isto eh muito legal";
    mensagem(texto);
}