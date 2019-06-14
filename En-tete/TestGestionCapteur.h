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
#include <string>
#include "GestionCapteur.h"
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

    TestGestionCapteur();

    virtual ~TestGestionCapteur();
	//----------------------------------------------------- M�thodes publiques

	void testUnitaire(string filename);
	// Mode d'emploi :
	// teste toutes les méthodes de la classe GestionCapteur
	// affiche les erreurs s'il y en a

protected:
	//----------------------------------------------------- M�thodes prot�g�es
    void testFichier(string filename);

    void testAjouter();

    void testSuppressionID();

    void testSuppressionLatLng();

    void testRechercheID();

    void testRechercheLatLng();
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
