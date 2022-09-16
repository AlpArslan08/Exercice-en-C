#include <stdio.h>
#include <stdlib.h>

int main()
{int i , pos;
    int taille , T[100] , N ;
    printf("\tveuillez saisir la taille du tableau : ");
    scanf("%d", &taille );
    printf("\tveuillez saisir les elements du tableau :\n\n  ");

    for(i=0 ; i < taille ; i++){
            printf("\t\t T[%d] = " , i+1);
            scanf("%d",&T[i]);
    }
    printf("\tveuillez saisir position  de suppression :  ");
    scanf("%d", &pos);
    if (pos<=0 || pos>taille+1){
        printf("Position invalid , Veuillez entrer d'autre position entre 1 et %d",taille+1);
        scanf("%d",&pos);
    }
    else
    for (i=pos ; i<taille ; i++) {
        T[i-1]=T[i];
    }
        taille--;

    printf("les valeurs du tableau apres suppression est :\n ");
    for (i=0 ; i <taille ; i ++ ){
        printf(" T [%d] = %d \n " , i+1 , T[i]);
    }

    return 0;
}
