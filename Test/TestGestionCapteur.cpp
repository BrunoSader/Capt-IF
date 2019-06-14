/*************************************************************************
TestGestionCapteur  -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
e-mail               : lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TestGestionCapteur> (fichier TestGestionCapteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TestGestionCapteur.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
TestGestionCapteur::test()
{
	cout << "Test de consulterCapteurs" ;
	/* ERREUR :
	Si le fichier qui contient la liste de capteurs est vide
	Si le fichier qui contient la liste de capteurs est inaccessible en lecture
	TOUT VA BIEN :
	Si le fichier est accessible et non vide*/

	cout << "Test de ajouterCapteur" ;
	/* ERREUR :
	Si l'ID indiqué est déjà existant
	Si les latitude et longitude du capteur sont impossibles
	Si les données du capteur ne sont pas consultables :  il n'est pas présent en mémoire ou non fonctionnel
	TOUT VA BIEN :
	Si le capteur a un ID inexistant, que sa localisation est possible et que ses données sont consultables.*/

	cout << "Test de supprimerCapteur" ;
	/* ERREUR :
	Si l'ID indiqué est inexistant
	Si on peut encore trouver le capteur dans la liste
	Si on peut encore le surveiller
	Si on ne peut plus récupérer les données dans le fichier data
	TOUT VA BIEN :
	Si le capteur a un ID existant, qu'on ne peut plus le surveiller ou le trouver dans la liste, mais qu'on peut récupérer ses données dans le fichier data*/

	cout << "Test de rechercherCapteur" ;
	/* ERREUR :
	Si les coordonnées indiquées sont erronées
	TOUT VA BIEN :
	Si deux capteurs sont à la même distance du point indiqué
	Si un capteur est proche de la position indiquée */

	cout << "Test de surveillerCapteur" ;
	/* ERREUR :
	Si l'ID indiqué est inexistant
	Si l'ID indiqué correspond à un capteur non fonctionnel
	TOUT VA BIEN :
	Si l'ID indiqué existe et correspond à un capteur fonctionnel */

	cout << "Test de capteursSimilaires" ;
	/* ERREUR :
	Si l'ID indiqué est inexistant
	Si aucun capteur similaire n'est trouvé
	TOUT VA BIEN :
	Si avec un grand intervalle de confiance, beaucoup de capteurs similaires sont renvoyés
	Si avec un petit intervalle de confiance, peu de capteurs similaires sont renvoyés. */

}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
