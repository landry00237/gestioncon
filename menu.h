#if !defined(__menu_h__)
#define __menu_h__
#include <string.h>
#include "structure.h"
int nive;

#define LG 80
#endif
STUD lire_atente(STUD candidat);

void decorarion();
//int deci(int M);
int choi_main(int n,int MIM,int Max);
STUD admis();//STOCKE LA LISTE DES CANIDAT ADMIS
STUD attente();
STATIST STATISTIQUES(STATIST* dec);//RETOURNE LE NOMVRE DE CANDIDAT

