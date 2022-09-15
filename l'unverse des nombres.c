#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N[10];
    int i ;
    printf("entrer les elements de tableau : \n\n\n ");
    for(i=0 ; i <10 ; i++ ){
        printf("N[%d] =  ", i+1);
        scanf("%d" ,&N[i] );
    }
    printf("\n\n\n");
    printf("la result est : \n\n\n");
    for(i=0 ; i <10 ; i++ ){
        printf("SN[%d] = %d\n" ,i+1 , N[9-i]);
    }

    return 0;
}
