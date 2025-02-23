
#include <stdio.h>

int main()
{

    int vaiDisney;
    int vaiTutoia;

 
    float media1, media2, media3;

    printf("informe as tres medias \n");
    scanf("%f %f %f", &media1, &media2, &media3);
    vaiDisney = (media1==10 && media2==10 && media3==10);
    printf("Vai pra disney? %d\n", vaiDisney);
    vaiTutoia = (media1 >= 7 && media2 >= 7 && media3 >= 7) && (media1 == 10 || media2 == 10 || media3 == 10) && !(vaiDisney);
    printf("Vai para tutoia? %d\n", vaiTutoia);


   return 0;
}