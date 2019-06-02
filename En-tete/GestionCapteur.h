/*************************************************************************
                           GestionMesure  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <GestionMesure> (fichier GestionMesure.h) ------
#if ! defined ( GESTIONCAPTEUR_H )
#define GESTIONCAPTEUR_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <iterator>
#include <map>
#include <deque>
#include <time.h>
#include "../En-tete/Capteur.h"
#include "../En-tete/GestionMesure.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <GestionCapteur>
//
//
//------------------------------------------------------------------------

class GestionCapteur
{
//----------------------------------------------------------------- PUBLIC

public:

		deque<Capteur> listeCapteur;
//----------------------------------------------------- M�thodes publiques

		string afficherCapteur( );
    // Mode d'emploi :
    //
    // Contrat :
    //

		void ajouterCapteur(string id, int lattitude, int longitude, string description );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
		void ajouterCapteur(int lattitude, int longitude, string description );
    // Mode d'emploi :
    //
    // Contrat :
    //

		bool supprimerCapteur(int choix, int lattitude, int longitude, string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

		bool surveillerCapteur(int choix, int lattitude, int longitude, string id, GestionMesure* gm);
    // Mode d'emploi :
    //
    // Contrat :
    //

		Capteur rechercherCapteur(string id);
		Capteur rechercherCapteur(int lattitude, int longitude);

    // Mode d'emploi :
    //
    // Contrat :
    //

		string capteursSimilaires(int choix, int lattitude, int longitude, string id, GestionMesure* gm, double confiance);

    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GestionCapteur ( const GestionCapteur & unGestionCapteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GestionCapteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GestionCapteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

};

//----------------------------------------- Types d�pendants de <GestionMesure>

#endif // GESTIONCAPTEUR_H
