/*************************************************************************
TestGestionMesure  -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
e-mail               : lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TestGestionMesure> (fichier TestGestionMesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TestGestionMesure.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
TestGestionMesure::test()
{
	cout << "Test consulterAttributs";
	/*ERREUR :
	Si le fichier qui contient la liste d'attributs est vide
	Si le fichier qui contient la liste d'attributs est inaccessible en lecture
	TOUT VA BIEN :
	Si le fichier qui contient la liste d'attributs est accessible et non vide*/

	cout << "Test consulterDonnées";
	/*ERREUR :
	Si le fichier qui contient la liste des mesures est vide
	Si le fichier qui contient la liste des mesures est inaccessible en lecture
	TOUT VA BIEN :
	Si le fichier qui contient la liste des mesures est accessible et non vide*/

	cout << "Test donneesSimilaires";
	/*ERREUR :
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si la valeur n'est pas renseignée
	TOUT VA BIEN : 
	Si  peu de données sont renvoyées lorsque l'intervalle de confiance est faible
	Si beaucoup de données sont renvoyées lorsque l'intervalle de confiance est grand*/

	cout << "Test getMesureCapteur";
	/*ERREUR :
	Si les coordonnées indiquées n'existent pas
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si la date indiquée est inexistante
	Si l'horaire indiqué n'est pas entier
	Si aucune mesure ne correspond à la recherche
	TOUT VA BIEN :
	Si on obtient les résultats attendus en indiquant un intervalle de coordonnées
	Si on obtient les résultats attendus en indiquant un intervalle de dates
	Si on obtient les résultats attendus en indiquant un intervalle horaire
	Si on obtient les résultats attendus en indiquant un ID de capteur existant
	Si on obtient les résultats attendus en indiquant un ID d'attribut existant pour l'ID du capteur
	Si on obtient les résultats attendus en combinant les éléments précédents, pour des valeurs extrèmes et intermédiaires*/
	
	cout << "Test moyenneValAttribut";
	/*ERREUR : 
	Si les dates indiquées sont inexistantes
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si aucune mesure ne correspond à la recherche
	Si une seule mesure correspond à la recherche
	TOUT VA BIEN : 
	Si on obtient les résultats attendus en indiquant un intervalle de dates
	Si on obtient les résultats attendus en indiquant une date
	Si on obtient les résultats attendus lorsqu'ils sont nombreux
	Si on obtient les résultats attendus lorsqu'ils sont peu nombreux */

	cout << "Test genererGraph";
	/*ERREUR :
	Si les dates indiquées sont inexistantes
	Si l'ID indiqué pour le capteur est inexistant
	Si l'ID indiqué pour l'attribut n'existe pas pour l'ID du capteur
	Si aucune mesure ne correspond à la recherche
	Si une seule mesure correspond à la recherche
	TOUT VA BIEN :
	Si on obtient les résultats attendus en indiquant un intervalle de dates
	Si on obtient les résultats attendus en indiquant une date
	Si on obtient les résultats attendus lorsqu'ils sont nombreux
	Si on obtient les résultats attendus lorsqu'ils sont peu nombreux */

}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
