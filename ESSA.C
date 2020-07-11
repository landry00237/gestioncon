#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// directives cree
#include "ajoute.h"
#include "ereure.h"
#include "ESSA.h"

int quiter( )
{
	int sortie;
	//puts("3.gere un candidat");
	do{
			puts("quel est votre choix");
			gets(chaine);
			compte=sscanf(chaine,"%u",&sortie);
			printf("%d\n",compte );
			if(compte<=1)
			{
				system("cls");
				puts("EREURE DE SAISI \n\a");
			}

			//puts("hello wolrd");
			if (compteur(sortie) == 4)
			{
				system("cls");
				break;
				/* code*/
			}
	}while(compte < 2);

	if (sortie==1111)
	{
		exit(0);
	}
	else
	{
		menu();
	}

}
/*void alternative()
{

}
{
	puts("gfr");
}*/
void menu()
{
	int chois;
	compte=3;
	do{
	puts("****************************************");
	puts("****menu principal de intelecshool****");
	puts("****************************************");
	puts("1.ajouter");
	puts("2.modifier");
	puts("3.SUPPRIMER UN CANDIDAT");
	puts("4.LISTE DES ADMIS");
	puts("5.lire un candidat");
	do{
			puts("\n\t\t\tquel est votre choix");
			gets(chaine);
			compte=sscanf(chaine,"%d",&chois);
		printf("%d\n",compte );
						if(compte!=1){
					system("cls");
					puts("EREURE DE SAISI \n\a");
						}

		//puts("hello wolrd");
		}while(chois<=0 && chois>3);
		if (compteur(chois) == 1)
		{
			system("cls");
			break;
			/* code */
		}
	}while(compte < 2);

	switch(chois)
	{
		case 1:
			// ajouter un candidat
			ajouter();
			break;
		case 2:
				modifier();
				/*puts("retour au menu principal( oui '1111' remodifier '2222')");

				if (1)
				{ puts("hello world");
					menu();
					/* code */
				//}
			break;
		case 3:
			puts("entre le numrero de la cni du candidat a supprimer");
			int NCIN_SUP;
			NCIN_SUP=verif();
			NCIN_SUP=rech_exist(NCIN_SUP);
			if(NCIN_SUP>=1)
			{
			 printf("CANDIDAT NON ENREGISTRE");
				break;
			}
			else
			{
				supprimer(NCIN_SUP);
			}

			break;
		case 4:

//			DECI deci;
			//affiche_merite();
			STAIIISTIQUES(&deci);

			printf("\tLE NOMBRE DE CANDIDAT ADMIS EST DE \%0.2f \%%\n",deci.Admis);
			printf("\t LE NOMBRE DE CANDIDAT AJOURNE EST DE \%0.2f \%%\n",deci.Ajourne);
			printf("\tLE NOMBRE DE CANDIDAT REFUSE EST DE \%0.2f \%%",deci.Refuse);
			attente();//STOCKAGE DES ADMIS;
				//affiche_merite();
			break;
		case 5:
			 NCIN=verif();

			RECHERCHE(NCIN);
			break;

			case 6:
			quiter();
				break;
		default	:("ereure d\'entre veuillez ressayer");
			break;
	}
}
