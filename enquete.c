
//Antonio Cleison Alves Silva

#include<stdio.h>

int main(){

    int op;
    float otimo = 0, normal = 0, ruim = 0, totalVotos = 0;
   
    
    do{
        printf("Pesquisa de satisfacao\nQual sua avaliacao para nossos Chocolates?\n");
        printf("1 - Sabor Otimo\n2 - Sabor Normal\n3 - Gosto Ruim\n999 - Sair\n");
        scanf("%d", &op);

            if(op == 1){
                otimo++;
            } else if(op == 2){
                normal++;
            } else if(op == 3){
                ruim++;
            }else if (op != 999){
                printf("Opcao invalida, digite uma opcao na:\n");
            }

        
    } while (op != 999);

    totalVotos = normal + ruim + otimo;

    if (totalVotos > 0){
        printf("Votos em Sabor Otimo: %.2f%%\n", (otimo * 100.0) / totalVotos);
        printf("Votos em Sabor Normal: %.2f%%\n", (normal * 100.0) / totalVotos);
        printf("Votos em Sabor Ruim: %.2f%%\n", (ruim * 100.0) / totalVotos);
        printf("Quantidade total de votos: %.2f\n", totalVotos);
    }else{
        printf("Nao houve votos\n");
    }

    printf("Fim da pesquisa!\n");

    return 0;
}