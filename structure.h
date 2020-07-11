#if !defined(__structure_h__)
#define __structure_h__
#include <string.h>

static int Max=2,nom=1000,compte,i;
static char chaine[280],absence[50]="CANDIDAT NON REPERTORIERI";

typedef enum choix{
	ADMIS, AJOURNE,REFUSE
}choix;

#define MIN 256
//DEFINTION DE LA STRUCTURE DE DONNEES AUX CANDIDATS
typedef struct STUD {
	unsigned NCIN ;
	char NOM[MIN];
	char PRENOMS[MIN];
	int AGE;
	float NOTES[10];
	float Moyenne;
	char virgule[2];
	choix DECISION;

}STUD;
//CREATION D'UN TYPE STAT POUR CALCULER ET RETOURNER LE POURCENTAGE DE CANDIDAT
typedef struct STATIST {
	float Admis, Ajourne, Refuse;

}STATIST;

#define LG 80
#endif

