/*************************************************************************
<<<<<<< HEAD
						   Gestion Capteur  -  description
							 -------------------
	début                : 14/05/2019
	copyright            : (C) 2019 par GALL Roxane
	e-mail               : roxane.gall@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Catalogue> (fichier Catalogue.h)  ---------
#if ! defined ( GESTIONCAPTEUR_H )
#define GESTIONCAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <vector>
using namespace std;

#include "Capteur.h"


class GestionCapteur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	string afficherCapteur() const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool ajouterCapteur(Capteur c);
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool supprimerCapteur(Capteur c);
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool surveillerCapteur(string id) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	Capteur rechercherCapteur(string id) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	Capteur rechercherCapteur(int latitude, int longitude) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector<Capteur> capteursSimilaires(string SensorId);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	vector<Capteur> listCapteur;
};

//-------------------------------- Autres définitions dépendantes de <GestionCapteur>

#endif // GESTIONCAPTEUR_H
=======
                           GestionMesure  -  description
                             -------------------
    dï¿½but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <GestionMesure> (fichier GestionMesure.h) ------
#if ! defined ( GESTIONCAPTEUR_H )
#define GESTIONCAPTEUR_H

//--------------------------------------------------- Interfaces utilisï¿½es
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <time.h>
#include "Capteur.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rï¿½le de la classe <GestionCapteur>
//
//
//------------------------------------------------------------------------

class GestionCapteur
{
//----------------------------------------------------------------- PUBLIC

public:

		vector<Capteur> listeCapteur;
//----------------------------------------------------- Mï¿½thodes publiques

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

		bool supprimerCapteur(Capteur c );
    // Mode d'emploi :
    //
    // Contrat :
    //

		bool surveillerCapteur(string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

		Capteur rechercherCapteur(string id);

    // Mode d'emploi :
    //
    // Contrat :
    //

		vector<Capteur> capteursSimilaires(string id);

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

//----------------------------------------- Types dï¿½pendants de <GestionMesure>

#endif // GESTIONCAPTEUR_H
>>>>>>> 53a0ae5d333d37c659bbae42608dbb316434e22e
