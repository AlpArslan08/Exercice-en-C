#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main()
{
    int age ;

        printf("entrer l'age de L'enfant : ");
        scanf("%d",&age);


    if( age<= 7 && age>=6 )
        printf("La categorie de l'enfant est : Poussin ");

    else if(age<=9 && age>=8 )
        printf("La categorie de l'enfant est : Pupille");

    else if(age<=11 && age>=10)
        printf("La categorie de l'enfant est : Minime");

    else
        printf("La catégorie de l'enfant est : Cadet ");
    getch();
    return 0;
}
