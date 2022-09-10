#include <stdio.h>
#include <stdlib.h>

int main()
{
        int age , date_naissance ;
        printf("\n\n\t\t\t\t\tPLEASE , ADD YOUR BIRTHDAY HERE : ");
        scanf("%d" , &date_naissance);
        age = 2022 - date_naissance;
        printf("\n\n\t\t\t\t\t\t YOUR AGE IS : %d YEARS OLD", age );
        getch();

return 0;
}
