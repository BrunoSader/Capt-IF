#pragma once
/*************************************************************************
TestGestionMesure -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
*************************************************************************/

//---------- Interface de la classe <TestGestionMesure> (fichier TestGestionMesure.h) ------
#if ! defined ( TESTGESTIONMESURE_H )
#define TESTGESTIONMESURE_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include "GestionMesure.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TestGestionMesure>
//
//
//------------------------------------------------------------------------

class TestGestionMesure
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�thodes publiques

	void test();
	// Mode d'emploi :
	// teste toutes les méthodes de la classe GestionMesure
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


#endif // TESTGESTIONMESURE_H