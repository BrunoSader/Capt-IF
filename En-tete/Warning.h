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
#include <iterator>
#include <vector>
#include "Attribut.h"
#include "Decision.h"
#include <string>
#include <map>
#include <ctime>
using namespace std;
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

struct DecisionCompare
{
   bool operator() (const Decision& decision1, const Decision& decision2) const
   {
       return decision1.getNote() < decision2.getNote();
   }
};

public:

	map<Decision,double,DecisionCompare> listeDecision;

//----------------------------------------------------- M�thodes publiques

		void entrerDecision(Decision laDecision,double valeur);
		// Mode d'emploi :
		//
		// Contrat :
		//

		void evaluerDecision(double valeurActuel);
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool calculerDonneePrevisionelle(map<struct tm, map<string,double>>listeMesurebyDate, string lAttribut);
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool valeurAuDelaSeuil(string attribut, double val);
		// Mode d'emploi : Type true signifie que c'est pas previsionelles
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
