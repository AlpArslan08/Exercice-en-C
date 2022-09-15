#include <stdio.h>
#include <stdlib.h>
void signe( int A , int B){
    if(A*B>0)
        printf("\t\tles valeurs de A et B de meme signe\n ");
    else
        printf("\t\tles valeurs de A et B de signe different\n");
}
int minimum( int A , int B ){
    int min ;
    if (A>B)
        min=B;
    else
        min=A;
    return min ;
}
int maximum( int A , int B ){
    int max ;
    if (A>B)
        max=A;
    else
        max=B;
    return max ;
}
int main()
{
    int A, B, max, min;

    printf("entre la valeur de A : ");
    scanf("%d", &A );
    printf("entre la valeur de B : ");
    scanf("%d",&B);

    signe(A,B);
    max=maximum(A,B);
    min=minimum(A,B);

    printf("\t\tla valeur minimale est : %d\n", min);
    printf("\t\tla valeur maximale est : %d\n", max);



    return 0;
}
