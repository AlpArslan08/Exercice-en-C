#include <stdio.h>
#include <stdlib.h>

int main()
{
    float U[3] , V[3] ;
    int i ;
    float P ;
    printf("Veuillez saisir les valiurs des deux vecteurs ; \n ");
    for (i=0 ; i < 3 ; i++ ){
        printf(" U[%d] =  " , i+1);
        scanf("%f", &U[i]);
        printf(" V[%d] =  " , i+1 );
        scanf("%f", &V[i]);
    }
        P = 0 ;
    for (i = 0 ; i <3; i ++ ){
        P = P +(U[i]*V[i]);
    }
    printf("le produit scalaire est : %.2f " , P);

    return 0;
}
