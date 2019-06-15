/*************************************************************************
					  main  -  description
				 -------------------
	début        :
	copyright    :
	e-mail       :
*************************************************************************/

//---------- Interface du module <LectureFichier> (fichier LectureFichier.h) ----------------
#if ! defined ( LECTUREFICHIER_H )
#define LECTUREFICHIER_H

// Rôle du module <LectureFichier>
// Ouvre tous les fichiers et charge les données dans les strucutres prévues à cet effet

//---------------------------------------------------------------- INCLUDE
#include <iostream>
#include <string>
using namespace std;

//--------------------------------------------------- Interfaces utilisées

#include "Warning.h"
#include "GestionMesure.h"
#include "GestionCapteur.h"

class LectureFichier{
//----------------------------------------------------------------- PUBLIC
//---------------------------------------------------- Fonctions publiques

  public :
		LectureFichier(GestionMesure* gm, GestionCapteur* gc, string nomFichierAttribut, string nomFichierDonnesCapteur, string nomFichierDescriptionCapteur, Warning *warning, int nombreLignes);
		int lectureAttribut();
		void lectureCapteur();
		void lectureDonneesCapteur();

	protected :
		GestionMesure* gm;
		GestionCapteur* gc;
		string nomFichierAttribut;
		string nomFichierDonnesCapteur;
		string nomFichierDescriptionCapteur;
		Warning* warning;
		int nombreLignes;

};
#endif // LECTUREFICHIER_H
