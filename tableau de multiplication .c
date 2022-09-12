#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N , i ;
    printf(" entrer un nombre : ");
    scanf("%d",&N);

    while (N<0 || N>10 ){
        printf("entrer un nombre entre 0 et 10 : ");
        scanf("%d",&N);
    }
    i=0;
    while (i<=10){
        printf(" %d x %d = %d \n " , N,i,N*i);
        i++;
    }


    return 0;
}
