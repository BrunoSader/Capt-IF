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
	cout << "Appel à la méthode ajouterCapteur de <GestionCapteur>" << endl;
#endif
	
	Capteur ajoute = Capteur(c);

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (listCapteur[i].getSensorId == ajoute.getSensorId) {
			return false;
		}
	}

	listCapteur.push_back(ajoute); // ajout du capteur à la fin du vecteur

	// On ajoute le sensorId correspondant à la map dans GestionMesure
	// A FAIRE
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	return true;

} //----- Fin de ajouterCapteur

bool GestionCapteur::supprimerCapteur(Capteur c) 
// Algorithme :
// On supprime le capteur indiqué de la liste des capteurs. Pour cela on parcours le vector contenant
// les capteurs et lorsqu'on trouve celui concerné, on le supprime.
// MAIS on ne supprime pas le sensorId de la map de GestionMesure car on doit toujours avoir accès 
// à ses anciennes mesures
{
#ifdef MAP
	cout << "Appel à la méthode supprimerCapteur de <GestionCapteur>" << endl;
#endif

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (listCapteur[i] == c) {
			listCapteur.erase(listCapteur.begin() + i-1); // efface le i ème élément
			return true;
		}
	}

	return false;

} //----- Fin de supprimerCapteur

bool GestionCapteur::surveillerCapteur(string id) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode surveillerCapteur de <GestionCapteur>" << endl;
#endif

} //----- Fin de surveillerCapteur

Capteur GestionCapteur::rechercherCapteur(string id) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode rechercherCapteur de <GestionCapteur>" << endl;
#endif

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (id.compare(listCapteur[i].getSensorId) == 0) { // si les sensorId sont identiques
			return listCapteur[i];
		}
	}

} //----- Fin de rechercherCapteur

Capteur GestionCapteur::rechercherCapteur(int latitude, int longitude) const
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode rechercherCapteur de <GestionCapteur>" << endl;
#endif

	for (int i = 0; i < listCapteur.size; i++)
	{
		if (listCapteur[i].getLattitude == latitude && listCapteur[i].getLongitude == longitude) { // si les sensorId sont identiques
			return listCapteur[i];
		}
	}

} //----- Fin de rechercherCapteur

vector <Capteur> GestionCapteur::capteursSimilaires(string SensorId)
// Algorithme :
{
#ifdef MAP
	cout << "Appel à la méthode capteursSimilaires de <GestionCapteur>" << endl;
#endif

} //----- Fin de capteursSimilaires

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées