#include <stdio.h>
#include <stdlib.h>

int main()

{
    float T[10] , S=0 , M ;
    int i ;
    for (i=0 ; i<10; i++ ){
        printf("Entrer la note du l'etudiant %d : ", i+1);
        scanf("%f", &T[i]);

    }
    for ( i  = 0 ; i < 10 ; i++ ){
        S = S + T[i];
    }
        M = S/10 ;
    printf("La moyenne est : %.2f ", M );


    return 0;
}
