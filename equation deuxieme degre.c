#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
        printf("\t\t\t====calculatrice de deuxieme degre =====\n");

        float a , b , c , deltha , x1 , x2, x  ;

                printf("\t entrer des trois valeurs de l'equation de deuxieme degre a et b et c : ");
                scanf("%f %f %f" ,&a , &b, &c );

            deltha=pow(b,2)-4*a*c;

        if (deltha<0)
            printf("n'est pas de solution reelles");

        else if (deltha==0){

            x=(-b)/2*a ;
            printf("il y a une solution dans R est : %.2f", x);
        }

        else {
            x1=(-b+sqrt(deltha))/2*a;
            x2=(-b-sqrt(deltha))/2*a;

        printf(" il y a deux solution en R est : %.2f et %.2f" , x1 , x2);

        }

    return 0;
}
