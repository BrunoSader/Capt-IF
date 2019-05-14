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

	bool supprimerCapteur();
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

	list <Capteur> capteursSimilaires(string SensorId);
	// Mode d'emploi :
	//
	// Contrat :
	//
