#if!defined(__ereure_h__)
#include "structure.h"
#define __ereure_h__

STATIST deci;
int NCIN;
#endif
void LIRE(STUD code);
void ecr_fic(FILE*fic,STUD code);
STUD lire(FILE*FICHIER);
int rech_exist(int NCIN_VERIF);//PROCEDURE DE VERIFICATION SI L'NCIN EXITE
int quiter();
void menu();
