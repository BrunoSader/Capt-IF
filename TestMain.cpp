/*************************************************************************
TestMain  -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
e-mail               : lucie.clemenceau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TestMain> (fichier TestMain.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TestMain.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
TestMain::test()
{
	cout << "Test chargerFichier";
	/* ERREUR :
	Si le fichier est inexistant
	Si le fichier est inaccessible en lecture
	Si le fichier est vide 
	TOUT VA BIEN : 
	Si le fichier existe, est accessible et si son contenu est conforme au format spécifié dans le sujet du TP*/
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
