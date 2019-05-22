#pragma once
/*************************************************************************
TestMain -  description
-------------------
d�but                : 22/05/2019
copyright            : (C) 2019 par CLEMENCEAU
*************************************************************************/

//---------- Interface de la classe <TestMain> (fichier TestMain.h) ------
#if ! defined ( TESTMAIN_H )
#define TESTMAIN_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include "main.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TestMain>
//
//
//------------------------------------------------------------------------

class TestMain
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�thodes publiques

	void test();
	// Mode d'emploi :
	// teste toutes les méthodes de la classe main
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


#endif // TESTMAIN_H