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
#include <string>
#include "../En-tete/GestionMesure.h"
#include "../En-tete/Mesure.h"
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

	void testUnitaire(string filename, string filename2);
	// Mode d'emploi :
	// teste toutes les méthodes de la classe GestionMesure
	// affiche les erreurs s'il y en a

protected:
	//----------------------------------------------------- M�thodes prot�g�es

    void testFichierAtt(string filename);

    void testFichierMes(string filename);

    void testAjouterAtt();
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
