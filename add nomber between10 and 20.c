#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N ;
    printf("please add a nombre between 10 and 20 :");
    scanf("%d",&N);

    while (N<10 || N >20 ){
        if (N<10){
            printf("the nomber is so small ");
        }
        else
            printf("the nomber is so big ");

         printf("please add a nombre between 10 and 20 :");
            scanf("%d",&N);
    }
    printf("Nice , You doing good ");

    return 0;
}
