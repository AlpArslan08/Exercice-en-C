#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int N ;
    long int *P=&N ;
    do {
    printf("veuillez saisir un nombre : ");
    scanf("%ld",P);
    }while(*P <= 0);
    for (int i=1 ; i<*P ; i ++){
        if ( *P % i == 0 ){
            printf(" %ld ", i);
        }
    }


    return 0;
}
