#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// directives cree
#include "structure.h"
#include "ajoute.h"
#include "ereure.h"
#include "menu.h"
void LIRE(STUD code)
{
	decorarion();
	decorarion();
	desplit(code.PRENOMS);
	desplit(code.NOM);
	printf("\n\t\t\t\t NCIN : %u  \n",code.NCIN);//ecrture de l'age
	printf("\t\t\t\t NOM et PRENOMS : %s  %s \t\n",code.NOM,code.PRENOMS);//nom
	printf("\t\t\t\t AGE : %u \t\n",code.AGE);//nom
	printf("\t\t\t\t MOYENNE: %0.2f \n",code.Moyenne);
		decorarion();


}
int choi_main(int n,int MIM,int Max)
{
			n=0;
        int compte=0,i=0;
        char chaine[80];
        do{

			printf("\n\t\t\t\tENTREZ VOTRE CHOIX  SVP :");
                 gets(chaine);
                compte=sscanf(chaine,"%d",&n);
				if(split_data(chaine)>=2)
				{
					printf("\a\n\n");
	   				printf("\n\t\t\t\tERREURE ENTREZ UN CHOIX  CORRECT SVP :");
					compte=2;

				}

       else if(MIM>n || n>Max)
	   {
	   	printf("\a\n\n");
	   	printf("\n\t\t\t\tERREURE ENTREZ UN CHOIX  CORRECT SVP :");
					compte=2;

	   }


	   i++;
	   if(i>=2)
	   {
	   	return -1;
	   }
    }while(compte!=1);


    return n;
}

void decorarion()
{
	printf("\t\t\t\t-----------------------------------------------------------------------\n");
}

int quiter( )
{
	int sortie;
	system("cls");
	decorarion();
	puts("\t\t\t\tvoulez vous vraiment quiter ? \n\t\t\t\t 1 menu 2.quiter");
	decorarion();
		sortie=choi_main(sortie,1,2);
		if (sortie==2)
	{

			 decorarion();
		 printf("\t\t\t\tmerci d' avoir utulise notre aplication\n");
			 decorarion();
		exit(0);
	}
	else
	{
		menu();
	}

}
STUD lire_atente(STUD candidat)
{
FILE* fic;
fic=fopen("attente.txt","r");
		do{
			//code=lire(fic);
					fscanf(fic,"%u\t ",&candidat.NCIN);//ecrture de l'age
					fscanf(fic,"%s\t ",&candidat.virgule);// ajoute virgule
					fscanf(fic,"%s\t",&candidat.NOM);//nom
					fscanf(fic,"%s\t",&candidat.virgule);//virgule
					fscanf(fic,"%s\t",&candidat.PRENOMS);
					fscanf(fic,"%s\t\n",&candidat.virgule);//virgule
				desplit(candidat.NOM);
				desplit(candidat.PRENOMS);
			decorarion();
			decorarion();
			//desplit(code.PRENOMS);
			//desplit(code.NOM);
			printf("\n\t\t\t\t NCIN : %u  \n",candidat.NCIN);//ecrture de l'age
			printf("\t\t\t\t NOM et PRENOMS : %s  %s \t\n",candidat.NOM,candidat.PRENOMS);//nom
		}while(!feof(fic));

}
void decorarion();


void menu()
{
	int n,M;
    label:
    system("cls");
     decorarion();
	puts("\t\t\t\t\t****BIENVENUE DANS INTELEC CONCOURS****");
	decorarion();
	puts("\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	puts("\t\t\t\t\t********\tMENU PRINCIPAL\t********");
	puts("\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	decorarion();
	decorarion();
	puts("\t\t\t\t****\t 1.SAISIR \t\t\t\t****\n ");
	puts("\t\t\t\t****\t 2.MODIFIER\t\t\t\t****\n");
	puts("\t\t\t\t****\t 3.SUPRIMER UN CANDIDAT\t\t\t****\n");
	puts("\t\t\t\t****\t 4.RECHERCHER UN CANDIDAT\t\t****\n");
	puts("\t\t\t\t****\t 5.STATISTIQUE\t\t\t\t****\n");
	puts("\t\t\t\t****\t 6.LISTE DEFINITIF DES ADMIS\t\t****\n");
	puts("\t\t\t\t****\t 7. LISTE D'ATTENTE \t\t\t****\n");
	puts("\t\t\t\t****\t 8.QUITER \t\t\t\t****\n");
	decorarion();
	 decorarion();
	printf("\n\t\t\tEntrer le numero correspondant a votre choix :  ");
    n=choi_main(n,1,8);
    decorarion();
	decorarion();

	if(n==-1)
		goto label;

    switch(n){
    case 1:


		do{
    	system("cls");
		ajouter();
		 decorarion();
		printf("\t\t\t\t1. menu 2 . quiter \n");
       decorarion();

         M=choi_main(M,1,2);
        if (M==1)
        {
            goto label;
        }
        else if (M==2)
        {
            quiter();
        }

		}while (M==-1);
        break;
    case 2:

		do{
				system("cls");
			decorarion();//decoration
			modifier();
			printf("\t\t\t\t1.modifier  2.menu  3. quiter \n");
	 //     int M,MIM=1,Max=2;
			 decorarion();//...
			 M=choi_main(M,1,3);

				if (M==2)
			{
				goto label;
				/* code */
			}
			else if (M==3)
			{

				quiter();
			}

        }while(M==-1 || M==1);

		admis();
        break;
    case 3://supression  d'un candidat

			do{
				system("cls");
				decorarion();
		puts("\t=========FONCTION SUPPRIMER UN CANDIDAT=========");
    	 decorarion();
				 decorarion();
				  decorarion();
				printf("\t\t\t\tentre le numrero de la cni du candidat a supprimer : ");
			int NCIN_SUP;
			NCIN_SUP=verif();
			NCIN=rech_exist(NCIN_SUP);
			if(NCIN>=1)
			{
				 decorarion();
				  decorarion();
			 printf("\t\t\t\tCANDIDAT NON ENREGISTRE");
			 printf("\t\t\t\tVOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				if(nive==1)//si oui on appel la fonction ajouter
				{
					ajouter();

				}


			}
			else
			{
				 decorarion();
				supprimer(NCIN_SUP);
				printf("\t\t\t\t DONNEZ DU CANDIDAT SUPPRIMER AVEC SUCCES \n");
			}

			 decorarion();//...deco
		printf("\t\t\t\t1.supprimer  2.menu  3. quiter \n");

			 M=choi_main(M,1,3);


			if (M==2)
			{
				goto label;
				/* code */
			}
			else if (M==3)
			{

				quiter();
			}
			if(M==-1)
				{
					system("cls");
				puts("entre le numrero de la cni du candidat a supprimer");
			int NCIN_SUP;
			NCIN_SUP=verif();
			NCIN=rech_exist(NCIN_SUP);
			printf("\t\t\t\t1.supprimer  2.menu  3. quiter \n");
	 //     int M,MIM=1,Max=2;

			 M=choi_main(M,1,3);
	 //     int M,MIM=1,Max=2;
			 decorarion();//...
			 M=choi_main(M,1,3);

				}

        }while(M==-1);
        break;
    case 4://rechercher un candidat

			do{
					attente();
					system("cls");
						decorarion();
						puts("===============\t FONTION RECHERCHER UN CANDIDAT\t===============");
						decorarion();
						decorarion();

    	decorarion();
    	printf("ENTRE LE NUMERO DE CNI :");
					NCIN=verif();
					NCIN=RECHERCHE(NCIN);
				if(NCIN!=0)
				{
					 decorarion();
					 decorarion();
					printf("\t\t\t\tCANDIDAT NON REPERTORIER \n");
					printf("\t\t\t\tVOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
					nive=choi_main(nive,1,2);
					if(nive==1)//si oui on appel la fonction ajouter
					{
						ajouter();

					}

				}
					decorarion();
					printf("\n\t\t\t\t1.rechercher autre candidat \t2.menu \t 3.quiter \n");

					 M=choi_main(M,1,3);
					if (M==2)
					{
						goto label;
						/* code */
					}
					else if (M==3)
					{
						quiter();
					}
			}while(M==-1);
        break;
    case 5:
    	do{
    	system("cls");

    	 decorarion();
    	 	printf("\n\t\t\t\t===============\t FONCTION STATISTIQUE\t===============\n");
			decorarion();
				STATISTIQUES(&deci);

			printf("\t\t\t\tLE NOMBRE DE CANDIDAT ADMIS EST DE \%0.2f \%%\n",deci.Admis);
			printf("\t\t\t\t LE NOMBRE DE CANDIDAT AJOURNE EST DE \%0.2f \%%\n",deci.Ajourne);
			printf("\t\t\t\tLE NOMBRE DE CANDIDAT REFUSE EST DE \%0.2f \%%\n",deci.Refuse);
			decorarion();
			printf("\t\t\t\t1. menu 2 . quiter \n");

         M=choi_main(M,1,2);
        if (M==1)
        {
            goto label;
            /* code */
        }
        else if (M==2)
        {
            quiter();
        }
      }  while(M==-1);
        break;
    case 6:// CAND admis

		do{
		attente();
		system("cls");
    	decorarion();
			admis();
			puts("\t\t\t\t===============\t LISTE DES ADMIS DEFINITIF\t===============");
			decorarion();
			affiche_merite();
			printf("\t\t\t\t1. menu 2 . quiter \n");
			decorarion();
         M=choi_main(M,1,2);
        if (M==1)
        {
            goto label;
            /* code */
        }
        else if (M==2)
        {
                    quiter();
        }
            }  while(M==-1);
        break;
    case 7://EN ATTENTE
    	do{
			system("cls");
    	decorarion();
    	puts("\t\t\t\t===============\t LISTE D'ATTENTE\t===============");
    	decorarion();
    	   	attente();//STOCKAGE DES ADMIS en attent;
    	   	FILE*fic=fopen("attente.txt","r");
    	   	STUD candidat;
			lire_atente(candidat);
		 //decorarion();
         printf("\t\t\t\t1. menu 2 . quiter \n");
			 decorarion();
         M=choi_main(M,1,2);
        if (M==1)
        {
            goto label;
            /* code */
        }
        else if (M==2)
        {
				quiter();
				     }
            }  while(M==-1);
        break;
    case 8://QUITER
    	do{
		system("cls");
    	decorarion();
    	puts("\t\t\t\t===============\t AU REVOIR\t===============");
		decorarion();
		quiter();
		 decorarion();
            }  while(M==-1);
        break;
	case 9:
		do{
    	system("cls");
    	decorarion();
			puts("\t\t\t\t===============\t FONCTION SUPRIMER DANS ADMIS\t===============");
    	 decorarion();

				Supprimer();
			   	decorarion();
						printf("\t\t\t\tVOTRE OPERATION EST EFECTUE AVEC SUCCES");
				decorarion();

         printf("1. menu 2 . quiter \n");
			 decorarion();
         M=choi_main(M,1,2);
        if (M==1)
        {
            goto label;
            /* code */
        }
        else if (M==2)
        {
                    quiter();
        }
            }  while(M==-1);
		break;
	    default:
	    	 decorarion();
        printf("\t\t\t\tEntrer invalid, reessayer: ");
         decorarion();
        goto label;
    }
}


