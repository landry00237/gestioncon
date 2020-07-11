/// fonction ajouter pour ajouter les infos du candidat
void ajouter(){
		STUD candidat;
		//char ligne[LG+1],sortie[10];
	 int i=0,j=0 ,p,nom;
strcpy(candidat.virgule,";");
	do{
		printf("ENTRE LES INFORMATION DU CANDIDAT  %d \n",i+1);
		do{
				if(j!=0)
					{
						puts("\n\n ! CE CANDIDAT EST DEJA ENREGISTRE !\n");
					}
					printf("ENTRE LE  NUMERO DE  CNI<<CARTE NATIONAL>>  :\t");
				candidat.NCIN=verif();
				j++;

		}while(rech_exist(candidat.NCIN)==0);
		printf("ENTRE LE NOM:  ");
		ECRIRE(candidat.NOM,MIN);
		split (candidat.NOM);
		printf("ENTRE LE PRENOMS:  ");
		ECRIRE(candidat.PRENOMS,MIN);
		split (candidat.PRENOMS);
		/// demde de l , age
		printf("ENTRE L'AGE  :\t");
		candidat.AGE=verif_age(candidat);
		printf("VEUILLEZ ENTRE LES NOTES SUR 20  : \n");
		MOYENNE(&candidat);
			/* code */
		SAISIR(candidat);
		i++;
		puts("voulez vous continuez \n");
		puts("11.OUI  \t 12.MENU\t13.QUITER\n");
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
puts("donnez enregistre avec succes");
}



procedure ajouter ()
	variables:candidat:STUD
	i=0,j=0,p,nom:entier
debut
	candidat.virgule <- ";"
		repete
		{
			AFFICHER("ENTRE LES INFORMATION DU CANDIDAT  ",i+1," \n");
			repete{
					if(j!=0)
						{
							puts("\n\n ! CE CANDIDAT EST DEJA ENREGISTRE !\n");
						}
						printf("ENTRE LE  NUMERO DE  CNI<<CARTE NATIONAL>>  :\t");
					candidat.NCIN=verif();
					j++;
			}TANQUE(rech_exist(candidat.NCIN)=0);
			AFFICHER("ENTRE LE NOM:  ");
			ECRIRE(candidat.NOM,MIN);//FONCTION POUR EQUIVALENT A SCANF POUR LES CHAINE DE CARACTER
			split (candidat.NOM);//SUPPRESSIONDES ESPACE
			AFFICHER("ENTRE LE PRENOMS:  ");
			ECRIRE(candidat.PRENOMS,MIN);
			split (candidat.PRENOMS);//fonction pour enlever les espace dans le prenom et le nom 
			/// demde de l , age
			AFFICHER(" ENTRE L'AGE  :\t");
			candidat.AGE=verif_age(candidat);//fontion pour l'age
			AFFICHER("VEUILLEZ ENTRE LES NOTES SUR 20  : \n");
			MOYENNE(&candidat);//fonction pour calculer les notes et afficher la moyenne
				/* code */
			SAISIR(candidat);//sockage dans la fonction saisir pour enregistre
			i++;
			AFFICHER("voulez vous continuez \n");//demade pour continuer
			AFFICHER("11.OUI  \t 12.MENU\t13.QUITER\n");
						nom=choi_main(nom,11,13);//fonction du menu
					SI (nom==12)
						{
							menu();
						}
					SINOn SI(nom==13)
						{
							quiter();
						}
					SINON
						{
						//	NETTOYAGE DE L'ECRAN
							j=0;
						}
TANT QUE(nom=11);//ON CONTINUE TANQUE NOM==11
AFFICHER("donnez enregistre avec succes");
fin	


variable : Max<-2,nom<-1000,compte,i :entier
         chaine,absence<-"CANDIDAT NON REPERTORIERI"; :chaine

type choix=enregistrement
{
	ADMIS, AJOURNE,REFUSE :entier

}
//DEFINTION DE LA STRUCTURE DE DONNEES AUX CANDIDATS
type STUD=enregistrement 
{
	 NCIN ;
 	 NOM, PRENOMS:chaine;
	 AGE :entier;
	 NOTES=tableau[10]:reel;
	 Moyenne:reel;
	virgule:caractere;
	DECISION:choix ;

}

//CREATION D'UN TYPE STAT POUR CALCULER ET RETOURNER LE POURCENTAGE DE CANDIDAT

type DECI=enregistrement {
	 Admis, Ajourne, Refuse:entier;
}


procedure modifier()
variables:  code:STUD
	 ancien<- "concour.txt",nouv<- "concour.txt":CHAINE
			 nive,ncin,i=0,j=0 , n  ,fic<-1,FICHIER<-2:entier
	OUVIR(ancien sur FICHIER  EN MODE LECTURE);
	OUVIR(nouv, sur fic EN MODE LECTURE OU ECRITURE);  
    debut
    decorarion();
	AFFICHER("\t****BIENVENUE DANS INTELEC CONCOURS****");
	decorarion();
	AFFICHER("\t********\tMENU DES MODIFICATIONS DES CANDIDATS\t********");
	decorarion();
    AFFICHER("1.MODIFIER TOUS LES DONNEES D'UN CANDIDAT \n");
	AFFICHER("2.MODIFIER LE NUMERO DE CNI\n");
	AFFICHER("3.MODIFIER LE NOM\n");
	AFFICHER("4.MODIFIER LE PRENOMS\n");
	AFFICHER("5.MODIFIER L'AGE\n");
	AFFICHER("6.MODIFIER LES NOTES\n ");
	AFFICHER("7.MENU\n");
	AFFICHER("ENTRE LE NUMERO CORRESPONDANT A VOTRE CHOIX CI-DESSOUS : \n");
    decorarion();
        n<-choi_main(n,1,7);
		si(n=-1)
			on retourne au menu modification
    selon(n){
   CAS  1:
    		 decorarion();
    		AFFICHER("VOUS AVEZ CHOISIS DE MODIFIER TOUS LES DONNEES D'UN CANDIDAT \n");
			decorarion();
    		AFFICHER("ENTRE L'ANCIEN NUMERO DE NCIN :");
			ncin=verif();
    	 	decorarion();
		 	nive=0;
			nive=rech_exist(ncin);
			si(nive=0)
				{
				repete{
					code<-lire(FICHIER);
					si(ncin=code.NCIN)//si le ncin entre est egale
					{
						code.virgule<-";"
						decorarion();
						AFFICHER("ENTRE LES INFORMATION DU CANDIDAT  a modifier  \n");
						decorarion();
						AFFICHER("ENTRE SON NOUVEAU NUMERO DE CNI :  ");
						code.NCIN=verif();
						AFFICHER("ENTRE SON NOUVEAU NOM:  ");
						ECRIRE(code.NOM,MIN);
						split (code.NOM);
						AFFICHER("ENTRE SON NOUVEAU PRENOMS:  ");
						ECRIRE(code.PRENOMS,MIN);
						split (code.PRENOMS);
						AFFICHER("ENTRE SON NOUVEAU AGE :\t");
						code.AGE=verif_age(code);
						AFFICHER("VEULIEZ ENTREZ LES NOUVELLES  NOTES sur 20 : \n");
						MOYENNE(&code);
						LIRE(code);
						AFFICHER("VOULEZ VOUS ENREGISTRE SES INFORMATION ? : 1.OUI \t 2.MENU MODIFIER / NON");
						nive=choi_main(nive,1,2);
						si(nive=1)//si il veut modifier ses information
							ecr_fic(fic,code);
						SINON
							on retourne au menu modification
						decorarion();
												}
					sinon si(ncin <> code.NCIN)
					{
						ecr_fic(fic,code);
					}
				}TANQUE(!feof(FICHIER));
			}
			SINON
			{
				AFFICHER("PAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
				AFFICHER("VOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				si(nive=1)//si oui on appel la fonction ajouter
					{
					ajouter();

					}
				SINON
					{
					on retourne au menu modification
					}
			}
CAS	2://modification de la cni
		    
		    	 decorarion();
		    	 AFFICHER("\nVOUS AVEZ CHOISIS DE MODIFIER LE NUMERO DE CNI D'UN CANDIDAT \n");
				decorarion();
  				AFFICHER("ENTRE L'ANCIEN  NUMERO DE NCIN : ");
				ncin=verif();
    			decorarion();
	 			nive=0;
				nive=rech_exist(ncin);
				si(nive=0)
					{
					repete{
						code=lire(FICHIER);


						si(ncin==code.NCIN)//si le ncin entre est egale
							{

							AFFICHER("ENTRE SON NOUVEAU NUMERO DE CNI :  \n");
							code.NCIN=verif();//nouvel cni;
							LIRE(code);
							ecr_fic(fic,code);
							decorarion();					}
						SINON si(ncin<>code.NCIN)
							{
							ecr_fic(fic,code);
							}
					}TANQUE(!feof(FICHIER));
					}
				SINON
					{
						AFFICHER("PAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
						AFFICHER("VOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
						nive=choi_main(nive,1,2);
						si(nive=1)//si oui on appel la fonction ajouter
							{
							ajouter();

							}
						SINON
							{
								retourne MENU MODIFICATION
							}
						}
CAS	 3://3.MODIFIER LE NOM
	debut
			decorarion();
			AFFICHER("VOUS AVEZ CHOISIS DE MODIFIER LE NOM D'UN CANDIDAT\n");
				  	 decorarion();
   			AFFICHER("ENTRE LE NUMERO DE NCIN :");
			ncin=verif();
    		decorarion();
			 nive=0;
					nive=rech_exist(ncin);
			si(nive=0)
			{
				repete{
					code=lire(FICHIER);
					si(ncin=code.NCIN)//si le ncin entre est egale
					{
						AFFICHER("ENTRE LE NOUVEAU NOM DU CANDIDAT \n");
						ECRIRE(code.NOM,MIN);
						split (code.NOM);
						LIRE(code);
						ecr_fic(fic,code);
						decorarion();					}
					sinon if(ncin <> code.NCIN)
					{
						ecr_fic(fic,code);
					}
				}TANQUE(<>feof(FICHIER));
			}
				sinon
			{
				AFFICHER("PAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
				AFFICHER("VOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				si(nive=1)//si oui on appel la fonction ajouter
					{
					ajouter();
					}
				SINON
				{
					retourne MENU MODIFICATION
				}

			}
			fin cas
	CAS 4 :	
	DEBUT	
// 4.MODIFICATION DU PRENOMS
			decorarion();
			AFFICHER("VOUS AVEZ CHOISIS DE MODIFIER LE PRENOM D'UN CANDIDAT\n");
				  	 decorarion();
   			AFFICHER("ENTRE LE NUMERO DE NCIN DE CE CANDIDAT :");
			ncin=verif();
    		decorarion();
			 nive=0;
					nive=rech_exist(ncin);
			si(nive=0)
			{
				repete{
					code=lire(FICHIER);
					si(ncin=code.NCIN)//si le ncin entre est egale
					{
						AFFICHER("ENTRE L'AGE");
						code.AGE=verif_age(code);
						ecr_fic(fic,code);
						decorarion();					}
					sinon if(ncin <> code.NCIN)
					{
						ecr_fic(fic,code);
					}
				}TANQUE(<>feof(FICHIER));
			}
				sinon
			{
				AFFICHER("PAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
				AFFICHER("VOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				si(nive=1)//si oui on appel la fonction ajouter
					{
					ajouter();
					}
				SINON
				{
					retourne MENU MODIFICATION
				}
			}
			FIN CAS
	CAS 5://5. M...AGE
	DEBUT
				 				  	 decorarion();
				  	 AFFICHER("\n VOUS AVEZ CHOISIS DE  MODIFIER L'AGE D'UN CANDIDAT\n");
				  	 decorarion();
			  	 decorarion();
   			AFFICHER("ENTRE LE NUMERO DE NCIN DE CE CANDIDAT :");
			ncin=verif();
    		decorarion();
			 nive=0;
					nive=rech_exist(ncin);
			si(nive=0)
			{
				repete{
					code=lire(FICHIER);
					si(ncin=code.NCIN)//si le ncin entre est egale
					{
						AFFICHER("ENTRE LE NOUVELLE  NOTES DU CANDIDAT : \n ");
						MOYENNE(&code);
						LIRE(code); //AFFICHER des notes
						ecr_fic(fic,code);
						decorarion();					
					}	
					sinon if(ncin <> code.NCIN)
					{
						ecr_fic(fic,code);
					}
				}TANQUE(<>feof(FICHIER));
			}
				sinon
			{
				AFFICHER("PAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
				AFFICHER("VOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				si(nive=1)//si oui on appel la fonction ajouter
					{
					ajouter();
					}
				SINON
				{
					retourne MENU MODIFICATION
				}
			}
		fin CAS
	CAS 6://6. M..NOTES
		DEBUT
		decorarion();
		AFFICHER("\n VOUS AVEZ CHOISIS DE MODIFIER LES NOTES D'UN CANDIDAT\n");
		decorarion();
	  	 decorarion();
   			AFFICHER("ENTRE LE NUMERO DE NCIN DE CE CANDIDAT :");
			ncin=verif();
    		decorarion();
			 nive=0;
					nive=rech_exist(ncin);
			si(nive=0)
			{
				repete{
					code=lire(FICHIER);
				si(ncin=code.NCIN)//si le ncin entre est egale
					{
						AFFICHER("ENTRE LE NOUVELLE  NOTES DU CANDIDAT : \n ");
						MOYENNE(&code);
						LIRE(code); //AFFICHER des notes
						ecr_fic(fic,code);
						decorarion();					
					}	
				sinon if(ncin <> code.NCIN)
					{
						ecr_fic(fic,code);
					}
				}TANQUE(<>feof(FICHIER));
			}
				sinon
			{
				AFFICHER("PAS TROUVER \nCE NUMERO N'EST PAS ENREGISTRE DANS LA BASE DE  DONNES\n\t");
				AFFICHER("VOULEZ VOUS LE FAIRE ? \n 1.oui  2.non");
				nive=choi_main(nive,1,2);
				si(nive=1)//si oui on appel la fonction ajouter
					{
					ajouter();
					}
				SINON
				{
					retourne MENU MODIFICATION
				}
			}
		fin CAS
	CAS 7://7.MENU
		debut
			menu();
		fin cas

	    default:
	    	 decorarion();
        AFFICHER("Entrer invalid, reessayer: ");
         decorarion();
        retourne MENU MODIFICATION

     }
			fermeture(FICHIER);
			fermeture(fic);
}














procedure supprimer(int NCIN_SUP)//POUR SUPPRIMER UN CANDIDAT
{
	variables code:STUD // declaration de la variable de type candidat code 
		      ancien<-"concour.txt", nouv<-"concour.txt":CHAINE 
		     FICHIER <= 2,fic <= 1, oui=0 ,i<=0: entier;
		OUVIR(nouv SUR fic EN MODE ECRIRE OU LECTURE);
		OUVIR(ancien SUR FICHIER EN MODE LECTURE);
	DEBUT
			repete{

							code=lire(FICHIER);

							SI (code.NCIN==NCIN_SUP)
								{//demande confirmation de suppression
									LIRE(code);
									AFFICHER("  NOTES :");
									pour(i<-0 a 10 pas de 1)
									{
										AFFICHER(" MATIER ",i+1," : "code.NOTES[i]"\n");//ncin

									}
								decorarion();
					AFFICHER("VOULEZ VUS SUPPRIMER CES INORMATION ?  1.OUI \t 2.NON : \a ");
					oui=choi_main(oui,1,2);
					si(oui==2)
						{
							ecr_fic(fic,code);
						}
					}
					SINON SI(code.NCIN!=NCIN_SUP)
					{
							// si on ne trouve pas on enregistre
						 ecr_fic(fic,code);
					}


							}TANT QUE( !feof(FICHIER));

		fermer(FICHIER);
		fermer(fic);


}



fonction admis() : STUD//fonction admis qui sotcker les candidat admis
{
	variables fic<=1;,k,j :entier
			  code:STUD // declaration de la variable de type candidat code 
		      ancien<-"concour.txt", nouv<-"concour.txt":CHAINE 
		      FICHIER <= 2,fic <= 1: entier;
		OUVIR(nouv SUR fic EN MODE ECRIRE OU LECTURE);
		OUVIR(ancien SUR FICHIER EN MODE LECTURE);

		repete{
		code=lire(FICHIER);
		SI(code.DECISION==ADMIS)
			{
				ecr_fic(fic,code);

			}
	}TANT QUE(!feof(FICHIER));
	fermer(FICHIER);
	fermer(fic);

}

fontion attente() :STUD//fontion attente
{
	variables:
	 ancien<="concour.txt",nouv<="admis.txt":CHAINE
	 code:STUD // declaration de la variable de type candidat code 
		      ancien<-"concour.txt", nouv<-"concour.txt":CHAINE 
		     FICHIER <= 2,fic <= 1, oui=0 ,i<=0: entier;
		OUVIR(nouv SUR fic EN MODE ECRIRE OU LECTURE);
		OUVIR(ancien SUR FICHIER EN MODE LECTURE);
	AFFICHER("\n LISTE DES CANDIDATS EN ATTENTE \n");
	repete{
		code=lire(FICHIER);
		SI(code.AGE>20)
			{
					ECRIRE FICHIER SUR fic code.NCIN;//ecrture de l'age
					ECRIRE FICHIER SUR fic code.virgule;// ajoute virgule
					ECRIRE FICHIER SUR fic code.NOM//nom
					ECRIRE FICHIER SUR fic code.virgule//virgule
					ECRIRE FICHIER SUR fic code.PRENOMS
					//nom
					ECRIRE FICHIER SUR fic,code.virgule;//virgule
					split(code.PRENOMS);//SUPRRESION DES ESPACE
					split(code.NOM);//SUPRRESION DES ESPACE
		}
		}TANT QUE (!feof(FICHIER));
		REPETE{
			//code=lire(fic);
					LIRE FICHIER SUR fic candidat.NCIN;//ecrture de l'age
					LIRE FICHIER SUR fic candidat.virgule;// ajoute virgule
					 LIRE FICHIER SUR fic candidat.NOM;//nom
					LIRE FICHIER SUR fic candidat.virgule//virgule
					LIRE FICHIER SUR fic candidat.PRENOMS
					LIRE FICHIER SUR fic candidat.virgule //virgule
				desplit(candidat.NOM);
				desplit(candidat.PRENOMS);
			decorarion();
			decorarion();
			desplit(code.PRENOMS);
			desplit(code.NOM);
			AFFICHER("\n NCIN : %u  \n",candidat.NCIN);//ecrture de l'age
			AFFICHER(" NOM et PRENOMS : %s  %s \t\n",candidat.NOM,candidat.PRENOMS);//nom
		}TANT QUE (feof(fic));
		fermer(FICHIER);
		fermer(fic);
	Supprimer();//suppression des candidat qui ON PLUS  plus de 20 ans
}




fontcion STATISTIQUES(dec: STATIST):STATIST//fontcion qui calcule les statistique
{
	
	variables:
	CON[20]="concour.txt":CHAINE
	 code:STUD // declaration de la variable de type candidat code  
		     file <= 1,  : entier;
	cpt=0,i=0,j=0,k=0:entier ; //declaration des compteur
		OUVIR(nouv SUR file EN MODE ECRIRE OU LECTURE);	

		repete{

			code=lire(file);
			selon(code.DECISION)
			{
				cas ADMIS: i++;

					cas :AJOURNE: j++;
				
					cas REFUSE: k++;
	
			}
				cpt++;
		}TANT QUE(!feof(file));

		dec->Admis=(i*100/cpt);
		dec->Ajourne=(j*100/cpt);
		dec->Refuse=(k*100/cpt);

		fermer(file);
	}



fontcion affiche_merite() :STUD//pour afficher par orgre de merite
{
	  	 padmis=1, n, i=0,j:entier
      moy=0,temp:reel
    atemp : STUD
    a=tableau[200]: DE STUD //DE TYPE CANDIDAT
     moyennes=tableau[200] : DE reel
     		OUVIR("admis.txt" SUR padmis en  LECTURE);	
   
   debut

    TANT QUE(!feof(padmis)){
        moy=0
        a[i]=lire(padmis);

        POUR(j<-0 a 10 faire)
            {
            moy <- moy+a[i].NOTES[j];
			}
        
        moyennes[i]=moy/10;
        i++;
             }
    	n=i
        //trier moyennes
  		OUVIR("admis.txt" SUR padmis en  ecrture);	
    pour(i<-0 a n-1 faire)
		{
		  a[i].Moyenne<-moyennes[i];
	      
	      pour(j<-i+1  a n faire)
			{
			SI(moyennes[i]<-moyennes[j])
			}	

			temp<-moyennes[i];
			moyennes[i]<-moyennes[j];
			moyennes[j]<-temp;
			atemp<-a[i];
			a[i]<-a[j];
			a[j]<-atemp;

			}
    pour(i<-0 a n-1 faire)		{
        ecr_fic(padmis,a[i]);
        LIRE(a[i]);
		}

    fermer(padmis);

}

procedure Supprimer()//POUR SUPPRIMER UN CANDIDAT
{

variables 
			  code:STUD // declaration de la variable de type candidat code 
		      ancien<-"admis.txt", nouv<-"admis.txt":CHAINE 
		      FICHIER <= 2,fic <= 1: entier;

		OUVIR(nouv SUR fic EN MODE ECRIRE OU LECTURE);
		
		OUVIR(ancien SUR FICHIER EN MODE LECTURE);


		repete{
		code=lire(FICHIER);
			si(code.AGE<=20)
					{//demande confirmation de suppression


					ecr_fic(fic,code);
					}

	}TANT QUE(!feof(FICHIER));
	fermer(FICHIER);
	fermer(fic);
}










FONCTION RECHERCHE(NCIN : entier): ENTIER//FONCTION DE RECHERCHE D'UN CANDIDAT  EXISTANT ET L'AFFICHE
{
	 code:STUD
	 file=1,cpt=0:entier
	 CON="concour.txt":CHAINE
	OUVIR CON SUR file en MODE LECTURE
		
		repete{
			code<-lire(file);
			Si(code.NCIN=NCIN)
			{
					LIRE(code);
			 RETOURNER 0;// ON RETOURNE ZERO POUR DIRE QU'ON A TROUVER
			}
			sinon
			{
				cpt++;
			}

	}TANT QUE(!feof(file));
		fermer(file);
	
	RETOURNER cpt;//CPT SI ON N'A PAS TROUVER
}



a envoye a 

justinonomo@gmail.com


variable :
  Max=2,nom=1000,compte,i:entier
  chaine:chaine
  constante absence <- "CANDIDAT NON REPERTORIERI": chaine

type choix=enregistrement{
	ADMIS<-0, AJOURNE<-1,REFUSE<-2 :entier
}choix;



typev STUD=enregistrement {
	 NCIN :entier
	 NOM:chaine
	 PRENOMS[MIN]:chaine
	 AGE:entier
	NOTES=tableau[10] de reel
	 Moyenne:reel
	virgule:caractere
	 DECISION:choix

}STUD;
//CREATION D'UN TYPE STAT POUR CALCULER ET RETOURNER LE POURCENTAGE DE CANDIDAT

typev STATIST=enregistrement 
 {
	 Admis,	 Ajourne, Refuse:reel
}
