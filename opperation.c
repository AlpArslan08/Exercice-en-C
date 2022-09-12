#include <stdio.h>
#include <stdlib.h>

int main()
{
    float A , B ;
    char opperation ;

    printf("donner un nombre : ");
    scanf("%f",&A);
    printf("entrer l'opperation : ");
    scanf(" %c",&opperation);
    printf("donner d'autre nombre : ");
    scanf("%f",&B);
    switch(opperation){
        case '+' : printf("La somme de deux nombre est : %.2f " , A+B );
                    break ;
        case '-' : printf("La soustraction est: %.2f ", A-B);
                    break ;
        case '/' : if (B=0)
                    printf("la division sur 0 est un erreur ");
                  else
                    printf("La division est : %.2f ", A/B);

        default : printf("L'opperation n'est pas definie ");
                   break ;
    }
    return 0;
}
