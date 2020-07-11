#if !defined(__ereur_h__)
#define __ereur_h__ //debut
static int compte,nombre,i,Max=2;
static char chaine[280];



#define LG 280
#endif // FIN


STUD ajouter(){
		STUD candidat [Max];
	for(int i=0;i<Max ;i++)
	{
		printf("entre les information du candidat N %d",i+1);
		puts("entre le numero de la cni :  ");
		fgets(chaine,10,stdin);
		compte=sscanf(chaine,"%d",&candidat[i].NCIN);
		verif(candidat[i].NCIN);
	}


printf("\n Hello world!\n");
}
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
int verif(int nombre){
	while(compteur(nombre)!=10)
	{

		int n, compte ;
		char ligne [LG+1] ;
			int stop;

		do
			{
				printf("  entre le NCIN a 10 chiffre :    ");
				gets (ligne);
				compte = sscanf (ligne, "%u ", &nombre) ;
				stop=strtol(ligne,NULL,10);
				while(stop==0) /*pour evites de les carractere avant les chiffre*/
				 {
					system("cls");
					printf("  ereure entre le NCIN a 10 chiffre  ");
					gets (ligne);
					stop=strtol(ligne,NULL,10);
				 }
					compteur(nombre);
					if(compteur(nombre)==10)
					{
						break;
					}
			}while (compte < 2 );
	}
	return 0;
}
int verif_age()
{
char ligne [LG+1];

	int n;

do
{
	 printf ("donnez un age correct: ") ;

gets (ligne) ;
compte = sscanf (ligne, "%d ", &n) ;
if (n<=0)
{
	 printf ("donnez un age correct : ") ;
gets (ligne) ;
compte = sscanf (ligne, "%d ", &n) ;
}
printf("%d",compte);
}
while (compte < 1 );

//printf ("merci pour %d \n", n) ;
//printf ("donnez un entier : ") ;
return n;
}


