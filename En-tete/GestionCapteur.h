/*************************************************************************
						   Gestion Capteur  -  description
							 -------------------
	d�but                : 14/05/2019
	copyright            : (C) 2019 par GALL Roxane
	e-mail               : roxane.gall@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Catalogue> (fichier Catalogue.h)  ---------
#if ! defined ( GESTIONCAPTEUR_H )
#define GESTIONCAPTEUR_H

//--------------------------------------------------- Interfaces utilis�es
#include <cstring>
#include <vector>
using namespace std;

#include "Capteur.h"


class GestionCapteur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
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
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	vector<Capteur> listCapteur;
};

//-------------------------------- Autres d�finitions d�pendantes de <GestionCapteur>

#endif // GESTIONCAPTEUR_H