#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// directives cree
#include "ajoute.h"
#include "ereure.h"
#include "ESSA.h"
#include "structure.h"


void ecr_fic(FILE*fic,STUD code)//pour ecrire dans le fichier
{

					fprintf(fic,"%u\t ",code.NCIN);//ecrture de l'age
					fprintf(fic,"%s\t ",code.virgule);// ajoute virgule
					fprintf(fic,"%s\t",code.NOM);//nom
					fprintf(fic,"%s\t",code.virgule);//virgule
					fprintf(fic,"%s\t",code.PRENOMS);
					//nom

					fprintf(fic,"%s\t",code.virgule);//virgule
					fprintf(fic,"%d\t",code.AGE);//ncin
					fprintf(fic,"%s\t",code.virgule);//virgule
			for(i=0;i<10;i++)
				{
					fprintf(fic,"%.2f\t",code.NOTES[i]);//ncin

				}
					fprintf(fic,"%s\t",code.virgule);//virgule
					fprintf(fic,"%0.2f\t",code.Moyenne);//MOYENE
					fprintf(fic,"%s\t",code.virgule);//virgule
					fprintf(fic,"%d\t",code.DECISION);//ncin
					fprintf(fic,"%s\n",code.virgule);//virgule

}
STUD lire(FILE*FICHIER)  //lecture des element fichier
{
STUD candidat;

					fscanf(FICHIER,"%u\t",&candidat.NCIN);//ecrture de ncin

					fscanf(FICHIER,"%s\t",&candidat.virgule);// ajoute virgule
					fscanf(FICHIER,"%s\t",&candidat.NOM);//nom
					fscanf(FICHIER,"%s\t",&candidat.virgule);//virgule
					fscanf(FICHIER,"%s\t",&candidat.PRENOMS);//prenoms
					//nom
					fscanf(FICHIER,"%s\t",&candidat.virgule);//virgule
					fscanf(FICHIER,"%d\t",&candidat.AGE);//age
					fscanf(FICHIER,"%s\t",&candidat.virgule);//virgule

				for(int i=0;i<10;i++)
				{
					fscanf(FICHIER,"%f \t",&candidat.NOTES[i]);//notes

				}
				fscanf(FICHIER,"%s\t",&candidat.virgule);//virgule
				fscanf(FICHIER,"%f\t",&candidat.Moyenne);//MOYENE
				fscanf(FICHIER,"%s\t",&candidat.virgule);//virgule
				fscanf(FICHIER,"%d\t",&candidat.DECISION);//decision
				fscanf(FICHIER,"%s",&candidat.virgule);//virgule

							//lecture dans le fichier

return candidat;
}

int rech_exist(int NCIN_VERIF)//PROCEDURE DE VERIFICATION SI L'NCIN EXITE
{
	STUD code;
	int cpt=0;
	char CON[20]="concour.txt";
	FILE *file=fopen(CON,"a+");
	if(file!=NULL)
	{do{
			code=lire(file);
			if(code.NCIN==NCIN_VERIF)
			{
				return 0; // ON RETOURNE ZERO POUR DIRE QU'ON A TROUVER
			}
			else{
				cpt++;
			}

	}while(!feof(file));
		fclose(file);
	}
	return cpt;//CPT SI ON N'A PAS TROUVER
}

int comte(FILE *file)//fonction qui compte le nombre de ligne dans un fichier
{

STUD code;
	int cpt=0;
	char CON[20]="concour.txt";
	file=fopen(CON,"a+");
	if(file!=NULL)
	{
		do{
			code=lire(file);
			cpt++;
		}while(!feof(file));
	fclose(file);
	}
	return cpt;//CPT SI ON N'A PAS TROUVER
}


void modifier()
{
	admis();
		STUD code;
	char ancien[20]="concour.txt";
	char nouv[20]="concour_tmp.txt";
	FILE*fic;
	fic=fopen(nouv,"w+");
	if(!fic)
	{
		perror("EROR");

	}
	admis();
	FILE *FICHIER=fopen(ancien,"r");
	if(!FICHIER)
	{
		perror("EROR");
	}
		int ncin;

int n, nive=0;

    label:
    system("cls");
     decorarion();
	puts("\t\t\t\t****BIENVENUE DANS INTELEC CONCOURS****");
	decorarion();
	puts("\t\t\t\t********\tMENU DES MODIFICATIONS DES CANDIDATS\t********");
	decorarion();
    puts("\t\t\t\t1.MODIFIER TOUS LES DONNEES D'UN CANDIDAT \n");
	puts("\t\t\t\t2.MODIFIER LE NUMERO DE CNI\n");
	puts("\t\t\t\t3.MODIFIER LE NOM\n");
	puts("\t\t\t\t4.MODIFIER LE PRENOMS\n");
	puts("\t\t\t\t5.MODIFIER L'AGE\n");
	puts("\t\t\t\t6.MODIFIER LES NOTES\n ");
	puts("\t\t\t\t7.MENU\n");
	puts("\t\t\t\tENTRE LE NUMERO CORRESPONDANT A VOTRE CHOIX CI-DESSOUS : \n");
    decorarion();
        n=choi_main(&n,1,7);
		if(n==-1)
			goto label;
    switch(n){
    case 1:
    	do{
    	system("cls");

    	 decorarion();
    	 puts("\t\t\t\tVOUS AVEZ CHOISIS DE MODIFIER TOUS LES DONNEES D'UN CANDIDAT \n");
		decorarion();
    printf("\t\t\t\tENTRE L'ANCIEN NUMERO DE NCIN :");
	ncin=verif();


    	decorarion();
							nive=rech_exist(ncin);
			if(nive==0)
			{
				do{
					code=lire(FICHIER);


					if(ncin==code.NCIN)//si le ncin entre est egale
					{

						int i=0,j=0 ;
						strcpy(code.virgule,";");
						decorarion();
						printf("\t\t\t\tENTRE LES INFORMATION DU CANDIDAT  a modifier  \n");
						decorarion();
						printf("\t\t\t\tENTRE SON NOUVEAU NUMERO DE CNI :  ");
						code.NCIN=verif();
						printf("\t\t\t\tENTRE SON NOUVEAU NOM:  ");
						ECRIRE(code.NOM,MIN);
						split (code.NOM);
						printf("\t\t\t\tENTRE SON NOUVEAU PRENOMS:  ");
						ECRIRE(code.PRENOMS,MIN);
						split (code.PRENOMS);
						printf("\t\t\t\tENTRE SON NOUVEAU AGE :\t");
						code.AGE=verif_age(code);
						printf("\t\t\t\tVEULIEZ ENTREZ LES NOUVELLES  NOTES sur 20 : \n");
						MOYENNE(&code);
						LIRE(code);
						puts("\t\t\t\tVOULEZ VOUS ENREGISTRE SES INFORMATION ? : 1.OUI \t 2.MENU MODIFIER / NON");
						nive=choi_main(nive,1,2);
						if(nive==1)
							ecr_fic(fic,code);
						else if(n==2)
							goto label;
						decorarion();
												}
					else if(ncin!=code.NCIN)
					{
						ecr_fic(fic,code);
					}
				}while(!feof(FICHIER));

			}
			else
			{
				printf("\t\t\t\tPAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
				printf("\t\t\t\tVOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				if(nive==1)//si oui on appel la fonction ajouter
				{
					ajouter();

				}
				else
				{
					goto label;
				}

			}
    }while(nive==-1);
    	break;
	case 2://modification de la cni
		do{    	system("cls");
		    	 decorarion();
		    	 puts("\n\t\t\t\tVOUS AVEZ CHOISIS DE MODIFIER LE NUMERO DE CNI D'UN CANDIDAT \n");
			decorarion();
    printf("\t\t\t\tENTRE L'ANCIEN  NUMERO DE NCIN : ");
	ncin=verif();
    	decorarion();
	 nive=0;
					nive=rech_exist(ncin);
			if(nive==0)
			{
				do{
					code=lire(FICHIER);


					if(ncin==code.NCIN)//si le ncin entre est egale
					{

						printf("ENTRE SON NOUVEAU NUMERO DE CNI :  \n");
						code.NCIN=verif();//nouvel cni;
						LIRE(code);
						ecr_fic(fic,code);
						decorarion();					}

					else if(ncin!=code.NCIN)
					{
						ecr_fic(fic,code);
					}
				}while(!feof(FICHIER));
			}
				else
			{
				printf("PAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
				printf("VOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				if(nive==1)//si oui on appel la fonction ajouter
				{
					ajouter();

				}
				else
				{
					goto label;
				}

			}
		}while(nive==-1);
		break;
	case 3://3.MODIFIER LE NOM
		do{
				system("cls");
				decorarion();
				puts("VOUS AVEZ CHOISIS DE MODIFIER LE NOM D'UN CANDIDAT\n");
				  	 decorarion();
				printf("\t\t\t\tENTRE LE NUMERO DE NCIN :");
				ncin=verif();
				decorarion();
				nive=0;
				nive=rech_exist(ncin);
				if(nive==0)
				{
					do{
						code=lire(FICHIER);


						if(ncin==code.NCIN)//si le ncin entre est egale
						{

							printf("\t\t\t\tENTRE LE NOUVEAU NOM DU CANDIDAT \n");
							ECRIRE(code.NOM,MIN);
							split (code.NOM);
							LIRE(code);
							ecr_fic(fic,code);
							decorarion();					}

						else if(ncin!=code.NCIN)
						{
							ecr_fic(fic,code);
						}
					}while(!feof(FICHIER));
				}
					else
				{
					printf("\t\t\t\tPAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
					printf("\t\t\t\tVOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
					nive=choi_main(nive,1,2);
					if(nive==1)//si oui on appel la fonction ajouter
					{
						ajouter();

					}
					else
					{
						goto label;
					}

				}
		}while(nive==-1);
		break;
	case 4:
			do{
			system("cls");
	// 4.MODIFICATION DU PRENOMS
					 decorarion();
					 puts("\n\t\t\t\tVOUS AVEZ CHOISIS DE MODIFIER LE PRENOMS D'UN CANDIDAT\n");
					 decorarion();
		printf("\t\t\t\tENTRE LE NUMERO DE NCIN :");
		ncin=verif();


			decorarion();
		 nive=0;
						nive=rech_exist(ncin);
				if(nive==0)
				{
					do{
						code=lire(FICHIER);


						if(ncin==code.NCIN)//si le ncin entre est egale
						{

							printf("\t\t\t\tENTRE LE NOUVEAU PRENOMS DU CANDIDAT :  ");
									ECRIRE(code.PRENOMS,MIN);
									split (code.PRENOMS);
									LIRE(code);
							ecr_fic(fic,code);
							decorarion();					}

						else if(ncin!=code.NCIN)
						{
							ecr_fic(fic,code);
						}
					}while(!feof(FICHIER));
				}
		else
				{
					printf("\t\t\t\tPAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
					printf("\t\t\t\tVOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
					nive=choi_main(nive,1,2);
					if(nive==1)//si oui on appel la fonction ajouter
					{
						ajouter();

					}
					else
					{
						goto label;
					}

				}
		}while(nive==-1);
		break;
	case 5://5. M...AGE
		do{
					  system("cls");
						 decorarion();
						 puts("\n\t\t\t\t VOUS AVEZ CHOISIS DE  MODIFIER L'AGE D'UN CANDIDAT\n");
						 decorarion();
			printf("\t\t\t\tENTRE LE NUMERO DE NCIN : ");
				ncin=verif();


			decorarion();
		 nive=0;
						nive=rech_exist(ncin);
				if(nive==0)
				{
					do{
						code=lire(FICHIER);


						if(ncin==code.NCIN)//si le ncin entre est egale
						{


						code.AGE=verif_age(code);


							ecr_fic(fic,code);
							decorarion();					}

						else if(ncin!=code.NCIN)
						{
							ecr_fic(fic,code);
						}
					}while(!feof(FICHIER));
				}
		else
				{
					printf("\t\t\t\tPAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES \n\t");
					printf("\t\t\t\tVOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
					nive=choi_main(nive,1,2);
					if(nive==1)//si oui on appel la fonction ajouter
					{
						ajouter();

					}
					else
					{
						goto label;
					}

				}
}while(nive==-1);
		break;
	case 6://6. M..NOTES
			do{
			system("cls");
			decorarion();
			puts("\n\t\t\t\t VOUS AVEZ CHOISIS DE MODIFIER LES NOTES D'UN CANDIDAT\n");
			decorarion();
			printf("\t\t\t\tENTRE LE NUMERO DE NCIN :");
			ncin=verif();
			decorarion();
			nive=0;
						nive=rech_exist(ncin);
				if(nive==0)
				{
					do{
						code=lire(FICHIER);


						if(ncin==code.NCIN)//si le ncin entre est egale
						{

							printf("\t\t\t\tENTRE LE NOUVELLE  NOTES DU CANDIDAT : \n ");
							MOYENNE(&code);
							LIRE(code);
							ecr_fic(fic,code);
							decorarion();					}

						else if(ncin!=code.NCIN)
						{
							ecr_fic(fic,code);
						}
					}while(!feof(FICHIER));
				}
				else
				{
					do{
					printf("\t\t\t\tPAS TROUVER CE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES");
					printf("\t\t\t\tVOULEZ VOUS AJOUTER CE CANDIDAT ? \n 1.oui  2.non");
					nive=choi_main(nive,1,2);
					if(nive==1)//si oui on appel la fonction ajouter
					{
						ajouter();

					}
					else
					{
						goto label;
					}
					}while(nive==-1);
				}
		}while(nive==-1);
		break;
	case 7://7.MENU

			menu();
		break;
	    default:
	    	 decorarion();
        printf("\t\t\t\tEntrer invalid, reessayer: ");
         decorarion();
        goto label;

     }


			fclose(fic);
			fclose(FICHIER);
			admis();

			remove("concour.txt");
			rename("concour.txt","concour_tmp.txt");
}


STUD admis()//fonction admis qui sotcker les candidat admis
{
	int k,j;

	char ancien[20]="concour.txt";
	char nouv[20]="admis.txt";
	FILE*fic;
	fic=fopen(nouv,"w+");
	if(!fic)
	{
		perror("EROR");

	}

	STUD code;
	FILE *FICHIER=fopen(ancien,"r");
	if(!FICHIER)
	{
		perror("EROR");
	}

		do{
		code=lire(FICHIER);
		if(code.DECISION==0)
		{
		ecr_fic(fic,code);

		}
	}while(!feof(FICHIER));

	fclose(FICHIER);
	fclose(fic);

	}

STUD attente() //fontion attente
{

		STUD code;
	char ancien[20]="admis.txt";
	char nouv[20]="attente.txt";
	FILE*fic;
	FILE *FICHIER=fopen(ancien,"r");
	if(!FICHIER)
	{
		perror("EROR");
	}
	fic=fopen(nouv,"a+");
	if(!fic)
	{
		perror("EROR");

	}

	printf("\nLISTE DES CANDIDATS EN ATTENTE\n");
	do{
		code=lire(FICHIER);
	//	code=lire(file);
		if(code.AGE>20)
		{

					fprintf(fic,"%u\t ",code.NCIN);//ecrture de l'age
					fprintf(fic,"%s\t ",code.virgule);// ajoute virgule
					fprintf(fic,"%s\t",code.NOM);//nom
					fprintf(fic,"%s\t",code.virgule);//virgule
					fprintf(fic,"%s\t",code.PRENOMS);
					//nom
					fprintf(fic,"%s\t\n",code.virgule);//virgule
		}


		}while(!feof(FICHIER));

STUD candidat;
fseek (fic, 0, SEEK_SET);
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
			printf("\n NCIN : %u  \n",candidat.NCIN);//ecrture de l'age
			printf(" NOM et PRENOMS : %s  %s \t\n",candidat.NOM,candidat.PRENOMS);//nom
		}while(!feof(fic));
		fclose(FICHIER);
		fclose(fic);
	Supprimer();//suppression des candidat qui plus de 20 ans

}

STATIST STATISTIQUES(STATIST*dec)//fontcion qui calcule les statistique
{
	STUD code;
	float cpt=0,i=0,j=0,k=0; //declaration des compteur
	char CON[20]="concour.txt";
	FILE *file=fopen(CON,"r+");
	if(file!=NULL)
	{
		do{

			code=lire(file);
			switch(code.DECISION)
			{
				case ADMIS: i++;
				break;
					case AJOURNE: j++;
				break;
					case REFUSE: k++;
				break;
				default:
				break;

			}
				cpt++;
		}while(!feof(file));

		dec->Admis=(i*100/cpt);
		dec->Ajourne=(j*100/cpt);
		dec->Refuse=(k*100/cpt);

		fclose(file);


	}


}

STUD affiche_merite()//pour afficher par orgre de merite
{
	    int i=0;
    int j;
    float temp;
    STUD atemp;
    int n;
    STUD a[200];
    float moyennes[200];
    FILE * padmis=fopen("admis.txt","r");
    while(!feof(padmis)){
        a[i]=lire(padmis);
        int moy=0;
        for(j=0;j<10;j++)
            {
            moy+=a[i].NOTES[j];
        }
        moy/=10;
        moyennes[i]=moy;
        i++;
             }
    n=i;
    padmis=fopen("admis.txt","w");
    //trier moyennes

    for(i=0;i<n-1;i++){
			a[i].Moyenne=moyennes[i];
	      for(j=i+1;j<n;j++){
        if(moyennes[i]<moyennes[j]){
            temp=moyennes[i];
            moyennes[i]=moyennes[j];
            moyennes[j]=temp;
            atemp=a[i];
            a[i]=a[j];
            a[j]=atemp;
        }

      }
    }
    for(i=0;i<n;i++){
        ecr_fic(padmis,a[i]);

        LIRE(a[i]);
		}

    fclose(padmis);

}

void Supprimer()//POUR SUPPRIMER UN CANDIDAT
{

	STUD code;
	char ancien[20]="admis.txt";
	char nouv[20]="admis_tmp.txt";
	FILE*fic;
	fic=fopen(nouv,"w+");
	if(!fic)
	{
		perror("EROR");

	}
	FILE *FICHIER=fopen(ancien,"r");
	if(!FICHIER)
	{
		perror("EROR");
	}
		int ncin;

		do
			{
				code=lire(FICHIER);
				//LIRE(code);
				if(code.AGE<=20)
					{//demande confirmation de suppression


					ecr_fic(fic,code);
					}

						}while( !feof(FICHIER));

	fclose(FICHIER);
	fclose(fic);
	remove(ancien);
	rename(nouv,ancien);

}
