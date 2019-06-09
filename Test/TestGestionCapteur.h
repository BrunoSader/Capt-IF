#pragma once
/*************************************************************************
TestGestionCapteur -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
*************************************************************************/

//---------- Interface de la classe <TestGestionCapteur> (fichier TestGestionCapteur.h) ------
#if ! defined ( TESTGESTIONCAPTEURH )
#define TESTGESTIONCAPTEUR_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include "GestionCapteur.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TestGestionCapteur>
//
//
//------------------------------------------------------------------------

class TestGestionCapteur
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�thodes publiques

	void test();
	// Mode d'emploi :
	// teste toutes les méthodes de la classe GestionCapteur
	// affiche les erreurs s'il y en a

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};


#endif // TESTGESTIONCAPTEUR_H