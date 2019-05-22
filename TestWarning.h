#pragma once
/*************************************************************************
TestWarning -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
*************************************************************************/

//---------- Interface de la classe <TestWarning> (fichier TestWarning.h) ------
#if ! defined ( TESTWARNING_H )
#define TESTWARNING_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include "Warning.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TestWarning>
//
//
//------------------------------------------------------------------------

class TestWarning
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�thodes publiques

	void test();
	// Mode d'emploi :
	// teste toutes les méthodes de la classe Warning
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


#endif // TESTWARNING_H