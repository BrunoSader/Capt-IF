/*************************************************************************
                           Warning  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Warning> (fichier Warning.h) ------
#if ! defined ( WARNING_H )
#define WARNING_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <iterator>
#include <vector>
#include "Attribut.h"
#include "Decision.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Warning>
//
//
//------------------------------------------------------------------------

class Warning
{
//----------------------------------------------------------------- PUBLIC

public:

	int type;
	String attributID;

//----------------------------------------------------- M�thodes publiques

		int calculerDonneePrevisionelle(String, Attribut);
		// Mode d'emploi :
		//
		// Contrat :
		//

		vector<String> valeurAuDelaSeuil();
		// Mode d'emploi :
		//
		// Contrat :
		//

		int evaluerDecision(Decision);
		// Mode d'emploi :
		//
		// Contrat :
		//

		Decision proposerDecision();
		// Mode d'emploi :
		//
		// Contrat :
		//
		
//------------------------------------------------- Surcharge d'op�rateurs
    Warning & operator = ( const Warning & unWarning );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Warning ( const Warning & unWarning );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Warning ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Warning ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

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

//----------------------------------------- Types d�pendants de <Warning>

#endif // WARNING_H
