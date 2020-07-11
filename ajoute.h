#if !defined(__ajoute_h__)
#define __ajoute_h__
#include <string.h>
#include "structure.h"
#endif

int split_data(char nom[ ]);
int rech_exist(int NCIN_VERIF);
void vider_buffer( );//definition fonction pour vider le tampon vider buffer
// creation de ma propre FONCITON LIRE SIMILAIRE A SCANF
int ECRIRE( char *chaine, int lg);
/// fonction Saisir de type candidat
STUD SAISIR(STUD candidat);/// qui prend en parametre une variable de type candidat
///fonctin pour lire le fichier
void lecture();
///fonction notes qui calcule les notes des etudiant
void notes(STUD *TAB);
// compteur de chiffre
int compteur(int nombre);
// fontion qui verifie les 10 chiffre de la cni
int verif();
// FONCTION QUI VERIFIE L'AGE DU CANDIDAT
int  verif_age(STUD nombre);
// MOYENNE
STUD  MOYENNE(STUD *TAB);
/// fonction ajouter pour ajouter les infos du candidat
void ajouter();
void Supprimer();//POUR SUPPRIMER UN CANDIDAT dont l age est > 20
int rech_exist(int NCIN_VERIF);//PROCEDURE DE VERIFICATION SI L'NCIN EXITE
void supprimer(int NCIN_SUP);//procedure pour supprimer QUI PREND EN PARAMETRE UNE ENTIER
void modifier();
int RECHERCHE(int NCIN);
void split(char nom[]);
void desplit(char nom[]);
