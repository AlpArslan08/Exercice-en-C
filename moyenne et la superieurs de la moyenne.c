#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N[10] , SN[10];
    int i ;
    printf("entrer les elements de tableau : \n");
    for(i=0 ; i <10 ; i++ ){
        printf("N[%d] =  ", i+1);
        scanf("%d" ,&N[i] );
    }
    for(i=0 ; i <10 ; i++ ){
        printf("SN[%d] = " , 10-(i+1))
    }
    return 0;
}
