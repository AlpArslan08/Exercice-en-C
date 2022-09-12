#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A , B ;
    char opperation ;

    printf("\n\t\t\t\t\t\=======calculatrice=======\n\n");
    printf("\tEntrer un nombre :  ");
    scanf("%d",&A);

    printf("\t\t\t\t\t======Menu de la calculatrice========\n\n ");
    printf("\t Choisissez l'operation appropriee a effectuer \n");


         printf("\t1 : addition \n");
         printf("\t2 : soustraction \n");
         printf("\t3 : multiplication \n");
         printf("\t4 : division \n");
         printf("\t5 : reste d'une division\n");
         printf("\t6 : puissance \n");
         scanf(" %c",&opperation);
         printf("\tEntrer d'autre nombre : \n");
         scanf("%d",&B);

    switch(opperation){
         case '1' : printf("%d + %d = %d ",A,B,A+B);
                    break;
         case '2' : printf("%d + %d = %d ",A,B,A-B);
                    break;
         case '3' : printf("%d + %d = %d",A,B,A*B);
                    break;
         case '4' : printf("%d + %d = %d ",A,B,A/B);
                    break;
         case '5' : printf("%d % %d = %d " , A,B,A%B);
                    break;
         case '6' : printf("%d ^ %d = %d ", A,B, pow(A,B));
                   break;
}



return 0;
}
