#include <stdio.h>
#include<stdlib.h>
#include <string.h>
// apelle des prototypes de ajoute .h
#include "structure.h"
#include "ajoute.h"
#include "ereure.h"
#include "ESSA.h"
#define LG 80

int split_data(char nom[ ])
{
	char *alpa="!~@#$%^&*()_+-=[]{};',./\"':<>?QWERTYUIOPASDFGHJKLMNBVCXZqwertyuiopasdfghjklmnbvcxz \n" ;
int cpt=1;
    for(int i=0;i<strlen(nom);i++)
	{
		for (int j=0;j<strlen(alpa);j++)
		{
			if(nom[i]==alpa[j])
			{
				cpt+=1;
			}
		}
	}

return cpt;
}

void vider_buffer()
{
	int c=0;
	while(c!='\n' && c!= EOF)
	{
		c=getchar();
	}
}
// FONCITON LIRE SIMILAIRE A SCANF

int ECRIRE( char *chaine, int lg)
{	//N LIT LE TEXTE SAISI AU CLAVIER
	char *position =NULL;
	if(fgets(chaine , lg ,stdin)!= NULL){
			position=strchr(chaine,'\n');
			if(position!=NULL)
			{
				*position='\0';
			}
			else{
				vider_buffer();
			}
			return 1;
	}
	else{
			vider_buffer();
		return 0;

	}
}
/// fonction Saisir de type candidat
STUD SAISIR(STUD candidat )/// qui prend en parametre une variable de type candidat
{
	char ancien[20]="concour.txt";
	//printf(" VALEUR :%d ",candidat.DECISION);
	FILE *FICHIER;
			FICHIER=fopen(ancien,"a");

					fprintf(FICHIER,"%u\t",candidat.NCIN);//ecrture de ncin
					fprintf(FICHIER,"%s\t",candidat.virgule);// ajoute virgule
					fprintf(FICHIER,"%s\t",candidat.NOM);//nom
					fprintf(FICHIER,"%s\t",candidat.virgule);//virgule
					fprintf(FICHIER,"%s\t",candidat.PRENOMS);//prenoms
					//nom
					fprintf(FICHIER,"%s\t",candidat.virgule);//virgule
					fprintf(FICHIER,"%d\t",candidat.AGE);//age
					fprintf(FICHIER,"%s\t",candidat.virgule);//virgule

				for(int i=0;i<10;i++)
				{
					fprintf(FICHIER,"%.2f\t",candidat.NOTES[i]);//notes

				}
				fprintf(FICHIER,"%s\t",candidat.virgule);//virgule
				fprintf(FICHIER,"%0.2f\t",candidat.Moyenne);//MOYENE
					fprintf(FICHIER,"%s\t",candidat.virgule);//virgule
				fprintf(FICHIER,"%d\t",candidat.DECISION);//decision
				fprintf(FICHIER,"%s\n",candidat.virgule);//virgule

				fclose(FICHIER);
		admis();//APPELLE DE ADMIS POUR STOCKER LES CANDIDAT
		attente();
}

///fonction notes qui calcule les notes des etudiant
STUD  MOYENNE(STUD *TAB)
{

		// declaration des variables
				//int nombre,
		int som=0;
		char ligne [LG+1] ;
		// PARCOUR U TABLEAU DE NOTES
				/* code */
			//utilisation de la boucle pour stocker les elements dans le enregistre


			for (int i = 0; i<10; i++)
				{

					do{	/* */
						printf("\t\t\t\tMATIER %d : ",i+1);
						gets (ligne);
						compte = sscanf (ligne, "%f ", &TAB->NOTES[i]) ;
						if(split_data(ligne)>=2  || TAB->NOTES[i]<0  || TAB->NOTES[i]>20 ||(compteur(TAB->NOTES[i])<0 &&compteur(TAB->NOTES[i])>20)|| compte<1)
						{
							printf("\a\n\n");
							compte=2;
							printf("\t\t\t\tERREURE ENTRE SUR LA NOTES DE LA MATIER  %d CORRIGER SVP : \n",i+1);

						}

					}while(compte!=1);
					som+=TAB->NOTES[i];//som des notes

					}

				TAB->Moyenne=som/10;
						int signal=0;
						//decision

					if (TAB->Moyenne>=10)
					{

							for (int i = 0; i < 10; ++i)
								{
									if (TAB->NOTES[i]>=10)
										{
											 signal++;
										}
								else
									{
										signal--;
									}
								}
					}

					else{
						TAB->DECISION=REFUSE;
											}
					if(signal != 10)
					{
						TAB->DECISION=AJOURNE;
					}
					else
					{
					    TAB->DECISION=ADMIS;
					}

						printf("\t\t\t\tLA MOYENNE EST  : %.2f \n",TAB->Moyenne);
}

// compteur de chiffre
int compteur(int nombre)
{
	int i=1;
	while(nombre>=10)
	{
		nombre/=10;
		i++;
	}

	return i;
}
// fontion qui verifie les 10 chiffre de la cni
int verif(){
	unsigned nombre;

	char ligne [LG+1] ;
	do
		{


			gets (ligne);
			compte = sscanf (ligne, "%u ", &nombre) ;
			if(split_data(ligne)>=2 || compteur(nombre)!=8)
				{


					compte=2;
					printf("\a\n\n");
					printf("\t\t\t\tERREURE ENTRE SUR LE NUMERO DE LA CNI CORRIGER SVP:");


				}
		}while (compte !=1 );


	return nombre;
}
// FONCTION QUI VERIFIE L'AGE DU CANDIDAT
int verif_age(STUD age)
{
	char ligne[LG+1];

	do{

		gets(ligne);
		compte = sscanf (ligne, "%u ", &age.AGE);

		if(split_data(ligne)>=2 || compteur(age.AGE)!=2 || compteur(age.AGE)!=2 ||age.AGE<=15)
			{
				printf("\a\n\n");
				printf("\t\t\t\t ERREURE ENTRE UN  AGE CORRECT  OU SUPERIEUR A 15 SVP :");
				compte=2;
			}
	}while(compte!=1);
return age.AGE;
}
// splitage des chaines de caracteres
void split(char nom[MIN])
{

    for(int i=0;i<strlen(nom);i++)
	{
	if(nom[i]==' ')
        {
        nom[i]='_';


		}
	}


}
// desplitages des chaines de caracteres
void desplit(char nom[MIN]){
	for(int i=0;i<strlen(nom);i++)
	{
	if(nom[i]=='_')
        {
        nom[i]=' ';


    }
	}

}
/// fonction ajouter pour ajouter les infos du candidat
void ajouter(){

		STUD candidat;
		//char ligne[LG+1],sortie[10];
	 int i=0,j=0 ,p,nom;
strcpy(candidat.virgule,";");
	do{
	decorarion();
		puts("\t\t\t\t=========FONCTION AJOUTER=========");
    	 decorarion();
		printf("\t\t\t\tENTRE LES INFORMATION DU CANDIDAT  %d \n",i+1);
		do{
				if(j!=0)
					{
						puts("\n\n\t\t\t\t ! CE CANDIDAT EST DEJA ENREGISTRE !\n");
					}
					printf("\t\t\t\tENTRE LE  NUMERO DE  CNI<<CARTE NATIONAL>>  :\t");
				candidat.NCIN=verif();
				j++;

		}while(rech_exist(candidat.NCIN)==0);
		printf("\t\t\t\tENTRE LE NOM:  ");
		ECRIRE(candidat.NOM,MIN);
		split (candidat.NOM);
		printf("\t\t\t\tENTRE LE PRENOMS:  ");
		ECRIRE(candidat.PRENOMS,MIN);
		split (candidat.PRENOMS);
		/// demde de l , age
		printf("\t\t\t\tENTRE L'AGE  :\t");
		candidat.AGE=verif_age(candidat);
		printf("\t\t\t\tVEUILLEZ ENTRE LES NOTES SUR 20  : \n");
		MOYENNE(&candidat);
			/* code */
		SAISIR(candidat);
		i++;
		puts("\t\t\t\tvoulez vous continuez \n");
		puts("\t\t\t\t11.OUI  \t 12.MENU\t13.QUITER\n");
					nom=choi_main(nom,11,13);
					if(nom==12)
					{
						menu();
					}
					else if(nom==13)
					{
						quiter();
					}
					else{
						system("cls");
						j=0;
					}
}while(nom==11);//ON CONTINUE TANQUE NOM==11
//	 LECTURE();
puts("\t\t\t\tdonnez enregistre avec succes");
}

void supprimer(int NCIN_SUP)//POUR SUPPRIMER UN CANDIDAT{
	{STUD code,candidat;
	int oui;
	char ancien[20]="concour.txt", nouv[20]="concour.txt";
	FILE*fic,*att=fopen("attente.txt","r+"),*atti=fopen("attente.txt","r");
	fic=fopen(nouv,"r+");
	if(!fic)
	{
		perror("EROR");
		exit(-1);
	}
	FILE *FICHIER=fopen(ancien,"r");
	if(!FICHIER)
	{
		perror("EROR");
		exit(-1);
	}
		do{




					code=lire(FICHIER);
						if (code.NCIN==NCIN_SUP)
						{//demande confirmation de suppression
							system("cls");
							LIRE(code);
							puts("");
							puts("  NOTES :");
							for(i=0;i<10;i++)
							{
								printf(" MATIER %d :%.2f\t\n",i+1,code.NOTES[i]);//ncin
							}
							puts("");
							decorarion();
				printf("\t\t\t\tVOULEZ VUS SUPPRIMER CES INORMATION ?  1.OUI \t 2.NON : \a ");
				oui=choi_main(oui,1,2);
				if(oui==2)
					{

						ecr_fic(fic,code);
					}
				}
				else if(code.NCIN!=NCIN_SUP)
				{
						// si on ne trouve pas on enregistre
					 ecr_fic(fic,code);
				}


						}while( !feof(FICHIER));
	fclose(FICHIER);
	fclose(fic);
}


int RECHERCHE(int NCIN)//FONCTION DE RECHERCHE D'UN CANDIDAT  EXISTANT ET L'AFFICHE
{
	STUD code;
	int cpt=0;
	char CON[20]="concour.txt";
	FILE *file=fopen(CON,"a+");
	if(file!=NULL)
	{do{
			code=lire(file);
			if(code.NCIN==NCIN)
			{
					LIRE(code);

			 return 0;// ON RETOURNE ZERO POUR DIRE QU'ON A TROUVER
			}
			else{
				cpt++;
			}

	}while(!feof(file));
		fclose(file);
	}
	return cpt;//CPT SI ON N'A PAS TROUVER
}

