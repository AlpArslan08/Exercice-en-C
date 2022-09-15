#include <stdio.h>
#include <stdlib.h>
int T[10];


void saisi(){

    printf("saisi  les element du tableau  : \n");
    for (int i=0 ; i<10 ; i ++){
        printf(" T[%d] =  " ,i+1);
        scanf("%d",&T[i]);
    }
}

  void Forder_croissant (){
    for ( int i=0 ; i<10 ; i++){
        for( int j=i+1 ; j< 10 ; j++){
            if(T[i]>T[j]){
            int temp = T[i];
                T[i]=T[j];
                T[j]=temp;

            }
        }
    }
    printf("les element par order croissante est : \n");
 }



 void Forder_decroissant (){
    for ( int i=0 ; i<10 ; i++){
        for( int j=i+1 ; j< 10 ; j++){
            if(T[i]<T[j]){
            int temp = T[i];
                T[i]=T[j];
                T[j]=temp;

            }
        }
    }
     printf("les element par order decroissante est : \n");
 }


 void affichage(){
     for ( int i=0 ; i<10 ; i++ ){
            printf("T[%d]= %d \n " , i+1 , T[i]);
     }
 }


int main()
{
    saisi ();
    Forder_croissant();
    Forder_decroissant();
    affichage();


    return 0;
}
