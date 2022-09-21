#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>


static int pos=-1;

typedef struct{
	char nom[30];
	float prix;
	float quantite;
	int code;
}Produit;

Produit temp;

typedef struct{
	Produit prd[10];
	//int cpt;
}Produits;

Produits P;


typedef struct{
	int year;
	int mon;
	int day;
}Date;

typedef struct{
	float prixTtc;
	Date date;
}Produit_Achat;

Produit_Achat P_A;

typedef struct{
	Produit_Achat prd_achat[10];
	//int cpt;
}Produits_achats;

Produits_achats PA;
static int paIndex =0;


time_t my_time;
struct tm * timeinfo;

static int nb,i,n=0,j;


//fonction permet de trier tous les produits selon l’ordre décroissant du prix.
//Tri par bulle

void tri_prix(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(P.prd[i].prix<P.prd[j].prix){
				temp=P.prd[i];
				P.prd[i]=P.prd[j];
				P.prd[j]=temp;
			}
		}
	}

}

//fonction permet de trier tous les produits selon l’ordre alphabétique croissant du nom.
//Tri par bulle

void tri_nom(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(P.prd[i].nom,P.prd[j].nom)>0){
				temp=P.prd[i];
				P.prd[i]=P.prd[j];
				P.prd[j]=temp;
			}
		}
	}

}

//Ajouter un nouveau produit: un produit est identifié par : son code, son nom, sa quantité, et son prix.
// n=0: declarer global et inatialiser en zero
void Ajouter_produit(){

	for(i=n;i<n+1;i++){

	printf("Saisir le nom du produit %d:",i+1);
	scanf("%s",P.prd[i].nom);
	printf("Saisir le code du produit %d:",i+1);
	scanf("%d",&P.prd[i].code);
	printf("Saisir le prix du produit %d:",i+1);
	scanf("%f",&P.prd[i].prix);
	printf("Saisir le quantite du produit %d:",i+1);
	scanf("%f",&P.prd[i].quantite);
	}
	n=n+1;

}

//Ajouter plusieurs nouveaux produits: un produit est identifié par :son code, son nom, sa quantité, et son prix.
void Ajouter_produits(){

    printf("combien de compte tu veux faire : ");
    scanf("%d",&nb);
	for(i=n;i<n+nb;i++){
	printf("Saisir le nom du produit %d:",i+1);
	scanf("%s",P.prd[i].nom);
	printf("Saisir le code du produit %d:",i+1);
	scanf("%d",&P.prd[i].code);
	printf("Saisir le prix du produit %d:",i+1);
	scanf("%f",&P.prd[i].prix);
	printf("Saisir le quantite du produit %d:",i+1);
	scanf("%f",&P.prd[i].quantite);
	}
	n=n+nb;
}


//Afficher apres le trier.
void afficher_produit()
{
	int i;
    float prixTtc;
	printf ("---------------------------------------------------------------------------------------------------------------\n");
	printf("  Nom\t\t\tPrix\t\t\tPrixTTC\t\t\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<n;i++)
		{
			    prixTtc=P.prd[i].prix +(P.prd[i].prix*0.15);
				printf ("%s\t\t%f\t\t%f\t\t\n",P.prd[i].nom,P.prd[i].prix,prixTtc);
		}
}

//fonction permet d’afficher les produits dont la quantité est inférieure à 3.
//Etat de stock
void afficher_produits_2()
{
	int i;

	printf ("---------------------------------------------------------------------------------------------------------------\n");
	printf("  Nom\t\tCode\t\tPrix\t\tQuantite\t\t\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<n;i++)
		{
			if(P.prd[i].quantite < 3){
				printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P.prd[i].nom,P.prd[i].code,P.prd[i].prix,P.prd[i].quantite);
			}
		}

}


//fonction permet de rechercher les produits par code

void Recherche_code(){
	int cod;
	do{
		printf("Donner le code du produit : ");
		scanf("%d",&cod);
	}while(cod<0);
	int trouve=0;
	printf ("----------------------------------------------------------------------------------------\n");
	printf(" Nom\t\tCode\t\tPrix\t\tQuantite\t\t\n");
	printf("-----------------------------------------------------------------------------------------\n");

		for(i=0;i<n;i++)
		{	if(P.prd[i].code==cod){
			printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P.prd[i].nom,P.prd[i].code,P.prd[i].prix,P.prd[i].quantite);
			trouve=1;
			break;
		}
		}
	if (trouve==0){
		printf("\nAucun produit trouver.\n");
	}
}

//fonction permet de supprimer les produits par code

void suppProduit(){
	int cd;
	printf("\nDonner un code : ");
	scanf("%d",&cd);
	int trouve = 0;
	for(i=0;i<n;i++){
			if(P.prd[i].code==cd){
				for(j=i;j<n-1;j++){
					P.prd[j]=P.prd[j+1];
				}
				n--;
				printf("\nSuppression effectuer ! \n");
				trouve = 1;
				break;

			}

	}
	if (trouve == 0)

		 printf("Impossible de supprimer le produit de code %d \n",cd);
		 //ce code n'exist pas dans la list des produits

}

//fonction permet de supprimer les produits par Quantite
void Recherche_Quantite(){
	float quant;
	do{
		printf("Donner la quantite du produit : ");
		scanf("%f",&quant);
	}while(quant<0);
	int trouve=0;
	printf ("------------------------------------------------------------------------\n");
	printf("  Nom\t\tCode\t\tPrix\t\tQuantite\t\t\n");
	printf("-------------------------------------------------------------------------\n");
		for(i=0;i<n;i++)
		{
			if(P.prd[i].quantite==quant){
				    printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P.prd[i].nom,P.prd[i].code,P.prd[i].prix,P.prd[i].quantite);
					trouve=1;
				}
		}


	if(trouve==0){
		printf("\nMedicament inconnu!\n");
	}
}

// fonction utiliser dans la fanction [Acheter_prod]
int Recherche_coder(){
	int cod;
	do{
		printf("Donner le code du produit : ");
		scanf("%d",&cod);
	}while(cod<0);
	int trouve=0;

	for(i=0;i<n;i++){

		if(P.prd[i].code==cod){
			trouve=1;
			return i;

		}
	}

		return -1;

}

// foncyion permet d acheter des produits
void Acheter_prod(){
	int index;
	float quant,prixTtc;

    index=Recherche_coder();
    if(index!=-1){
    printf("Donner la quantite du produit  que tu veux : ");
	scanf("%f",&quant);


    if(P.prd[index].quantite>=quant){
        pos=index;//pour afficher lea informations de le produit apre l'achat kansawno fiha posion
        P.prd[index].quantite -= quant;


        P_A.prixTtc = (P.prd[index].prix * quant)+(P.prd[index].prix * quant*0.15) ;

        time (&my_time);
        timeinfo = localtime (&my_time);

        P_A.date.year = timeinfo->tm_year+1900;
        P_A.date.mon=timeinfo->tm_mon+1;
        P_A.date.day=timeinfo->tm_mday;

        PA.prd_achat[paIndex] = P_A;
        paIndex++;
    }

  }
  else{
  	printf("Votre code incorrect!!!");
  }

}

// fonction permet d afficher les informations de produits apres l achat et alimentation
void afficherProduitsAcher()
{
	if(pos!=-1){
		printf ("%s\t\t%d\t\t%f\t\t%f\t\t\n",P.prd[pos].nom,P.prd[pos].code,P.prd[pos].prix,P.prd[pos].quantite);
	    printf("\n\n");
	}
	else{
		printf("Non produit achat!!\n");
	}
}



// Alimenter (Add une nouvelle quantite)

void Alimenter_stock(){
    int index;
	float quant;

    index=Recherche_coder();
    if(index != -1){
    printf("Donner la quantite du produit  que tu veux : ");
	scanf("%f",&quant);
	pos=index;
	P.prd[index].quantite += quant;

	printf("Votre commande succes\n");


  }

    else
		printf("Votre commande ne se trouve pas!!");

}

// fonction permet de donner le prix Total
void statistique_vante_prixTotal(){
	 float total_prix_tt = 0;
     printf("h1");
     time (&my_time);
     timeinfo = localtime (&my_time);
	 for(i=0;i<paIndex;i++){
	 	if(
		 	(PA.prd_achat[i].date.year == timeinfo->tm_year+1900) && (PA.prd_achat[i].date.mon=timeinfo->tm_mon+1) &&  (PA.prd_achat[i].date.day=timeinfo->tm_mday)
		 ){
		     printf("h2");
	 		 total_prix_tt+=PA.prd_achat[i].prixTtc;
		     printf("h3");
		 }
	 }

	 printf("Le prix Total est : %f\n",total_prix_tt);
}

// fonction permet de donner le prix moyen
void statistique_vante_moyen(){
	 float total_prix_tt = 0;
	 float moyen;
     int count = 0;
     time (&my_time);
     timeinfo = localtime (&my_time);

	 for(i=0;i<paIndex;i++){
	 	if(
		 	(PA.prd_achat[i].date.year == timeinfo->tm_year+1900) && (PA.prd_achat[i].date.mon=timeinfo->tm_mon+1) &&  (PA.prd_achat[i].date.day=timeinfo->tm_mday)

		 ){

	 		total_prix_tt+=PA.prd_achat[i].prixTtc;
	 		count++;

		 }
	 }

	 moyen=total_prix_tt / count;

	 printf("Le moyen prix est : %f\n",moyen);


}

// fonction permet de donner le prix min

void statistique_vante_min(){
	 float min = PA.prd_achat[0].prixTtc;
	 for(i=1;i<paIndex;i++){
	     //check the date before override on the min price
	 	if(PA.prd_achat[i].prixTtc < min){
	 		min =PA.prd_achat[i].prixTtc;
		 }
	 }

	 printf("Le min prix est : %f\n",min);

}

// fonction permet de donner le prix max

void statistique_vante_max(){
	 float max = PA.prd_achat[0].prixTtc;
	 for(i=1;i<paIndex;i++){
	 	if(PA.prd_achat[i].prixTtc > max){
	 		max =PA.prd_achat[i].prixTtc;
		 }
	 }

	 printf("Le Max prix est : %f\n",max);


}



// fonction permet de enregistrer la date d'achat et le prixTtc

void afficherProduitsAchat()
{
	int i;
	for(i = 0; i < paIndex; i++)
	{

		printf("prixTTC = %f\n",PA.prd_achat[i].prixTtc);
		printf("Annee est : %d\n",PA.prd_achat[i].date.year);
		printf("mois  est : %d\n",PA.prd_achat[i].date.mon);
		printf("jour est : %d\n",PA.prd_achat[i].date.day);

	}
}



int main(){


	int choix,index;
	index=0;



	do
	{

		system("cls");

		do
		{
		printf("\t\t\t\t ***********************************************\n");
		printf("\t\t\t\t| -------- Base de donnees de pharmacie --------| \n");
		printf("\t\t\t\t| 0  : Ajouter des nouveaux produits            | \n");
		printf("\t\t\t\t| 1  : Afficher les produits                    | \n");
		printf("\t\t\t\t| 2  : Acheter un produit                       | \n");
		printf("\t\t\t\t| 3  : Rechercher des produits par code et Qtt  | \n");
		printf("\t\t\t\t| 4  : Afficher les produits dont quantite < 3  | \n");
		printf("\t\t\t\t| 5  : Alimenter stock                          | \n");
		printf("\t\t\t\t| 6  : Supprimer des produits                   | \n");
		printf("\t\t\t\t| 7  : statique de vante T-M-X                  | \n");
		printf("\t\t\t\t| 8  : afficher Produits Acher                  | \n");
		printf("\t\t\t\t| 9  : Quitter le programe                      | \n");
		printf("\t\t\t\t|_______________________________________________| \n");
		printf("\n");

		printf("Choisir un choix:");
		scanf("%d",&choix);

     	}while(choix<0 || choix>9);

		switch(choix)
		{

			case 0 :
			do{
		     		printf("\t\t\t\t|_________________________________| \n");
					printf("\t\t\t\t| 1  : Ajouter un produit         | \n");
				    printf("\t\t\t\t| 2  : Ajouter plusieurs produits | \n");
					printf("\t\t\t\t|_________________________________| \n");
				    printf("\n");
		            printf("Donner votre choix:");
			        scanf("%d",&choix);
				  }while(choix<1 || choix>2);
				 switch(choix){
				 	case 1:
			    	Ajouter_produit();getch();break;
			    	case 2:
					Ajouter_produits();getch();break;
					default:break;
				}
			  break;
		    case 1 :
		     	do{
		     		printf("\t\t\t\t|_________________________________| \n");
					printf("\t\t\t\t| 1  : Lister Par Prix            | \n");
				    printf("\t\t\t\t| 2  : Lister Par Nom             | \n");
					printf("\t\t\t\t|_________________________________| \n");
				    printf("\n");
		            printf("Donner votre choix:");
			        scanf("%d",&choix);
				  }while(choix<1 || choix>2);
				 switch(choix){
				 	case 1:
					tri_prix();
			    	afficher_produit();getch();break;
			    	case 2:
			    	tri_nom();
					afficher_produit();getch();break;
					default:break;
				}
			  break;
			  case 2: Acheter_prod();
			        afficherProduitsAchat();
			        getch();
			 break;
			 case 3 :
				   do{
						printf("\t\t\t\t|_______________________________| \n");
						printf("\t\t\t\t| 1  : Rechercher par code      | \n");
						printf("\t\t\t\t| 2  : Rechercher  par Quantite | \n");
						printf("\t\t\t\t|_______________________________| \n");
						printf("\n");
						printf("Donner votre choix:");
						scanf("%d",&choix);
					}while(choix<1 || choix>2);
					switch(choix){
							 	case 1:
								Recherche_code();getch();break;
						    	case 2:
						    	Recherche_Quantite();getch();break;
								default:break;
					}
				break;

		    case 4 : afficher_produits_2();getch();break;
			case 5: Alimenter_stock();getch();break;
		    case 6: suppProduit();getch();break;

		    case 7:
				   do{
						printf("\t\t\t\t|________________________________________| \n");
						printf("\t\t\t\t| 1  : Afficher Le Total des Prix        | \n");
						printf("\t\t\t\t| 2  : Afficher Le Moyen des Prix        | \n");
					    printf("\t\t\t\t| 3  : Afficher Le Max des Prix          | \n");
					    printf("\t\t\t\t| 4  : Afficher Le Min des Prix          | \n");
						printf("\t\t\t\t|________________________________________| \n");
					    printf("\n");
						printf("Donner votre choix:");
						scanf("%d",&choix);
					}while(choix<1 || choix>4);
					switch(choix){
							 	case 1:
								statistique_vante_prixTotal();getch();break;
						    	case 2:
						    	statistique_vante_moyen();getch();break;
						    	case 3:
								statistique_vante_max();getch();break;
						    	case 4:
								statistique_vante_min();getch();break;
								default:break;
					}
               break;
               case 8:afficherProduitsAcher();getch();break;

		}

	}while(choix!=9);

	return 0;
}










