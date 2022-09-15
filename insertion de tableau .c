#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i , pos;
    int taille , T[100] , N ;

    printf("\tveuillez saisir la taille du tableau : ");
    scanf("%d", &taille );
    printf("\tveuillez saisir les elements du tableau :\n\n  ");

    for(i=0 ; i < taille ; i++){
            printf("\t\t T[%d] = " , i+1);
            scanf("%d",&T[i]);
    }
    printf("\tveuillez saisir la valeur a inserer : ");
    scanf("%d", &N );
    printf("\tveuillez saisir sa position :  ");
    scanf("%d", &pos);

    if (pos <=0 || pos>taille){
        printf("\t\tPosition invalide ! , Veuillez entrer une position entre 1 et %d : ", taille);
        scanf("%d", &pos);
    }
    else
         for (i= taille ; i>=pos ;i--){
            T[i]=T[i-1];
    }
    T[pos-1]=N;
    taille++;

    printf("les element de tableau apres l'insertion est : \n");
    for (i=0 ; i<taille ; i++){
        printf("T[%d]= %d \n",i+1, T[i]);
    }



    return 0;
}
