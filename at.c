#include<stdio.h>
#include<stdlib.h>

int main (){

    int i = 0, x = 0, y = 0, z = 0, w = 0;
    int vect[3][3];

    while (i < 20){
     
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                vect[i][j] = 1;
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                x = vect[i][j] + vect[i][j + 1] + vect[i][j +2];
                y = vect[i][j] + vect[i + 1][j] + vect[i + 2][j];
                z = vect[i][j] + vect[i + 1][j + 1] + vect[i +2][j+ 2];
                w = vect[i + 2][j + 2] + vect[i + 1][j + 1] + vect[i+2][j];
            }
        }
     
        if(y == x && x == z && z == w){
            printf("Correto");
        }else{
            printf("Erro");
        }
        i++;
    }
    

    return 0;
}