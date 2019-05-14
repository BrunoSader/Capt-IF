/*************************************************************************
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