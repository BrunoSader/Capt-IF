/*************************************************************************
						   GestionCapteur  -  description
							 -------------------
	début                : 14/05/2019
	copyright            : (C) 2019 par GALL Roxane
	e-mail               : roxane.gall@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionCapteur> ----------- ------------

#define _CRT_SECURE_NO_WARNINGS

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GestionCapteur.h"
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string GestionCapteur::afficherCapteur() const
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode afficherCapteur de <GestionCapteur>" << endl;
#endif
	
} //----- Fin de afficherCapteur

bool GestionCapteur::ajouterCapteur(Capteur c) 
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode afficherCapteur de <GestionCapteur>" << endl;
#endif
	
	Capteur ajoute = Capteur(c);

	if (==ajoute) {
		return false;
	}


	return true;



} //----- Fin de afficherCapteur

bool GestionCapteur::supprimerCapteur() 
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode afficherCapteur de <GestionCapteur>" << endl;
#endif

} //----- Fin de afficherCapteur

bool GestionCapteur::surveillerCapteur(string id) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode afficherCapteur de <GestionCapteur>" << endl;
#endif

} //----- Fin de afficherCapteur

Capteur GestionCapteur::rechercherCapteur(string id) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode afficherCapteur de <GestionCapteur>" << endl;
#endif

} //----- Fin de afficherCapteur

list <Capteur> GestionCapteur::capteursSimilaires(string SensorId)
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode afficherCapteur de <GestionCapteur>" << endl;
#endif

} //----- Fin de afficherCapteur

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées