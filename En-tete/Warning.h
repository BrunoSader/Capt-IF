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
		 if(decision1.getAction()[0]==decision2.getAction()[0] && decision1.getAction()[1]==decision2.getAction()[1] && decision1.getAction()[2]==decision2.getAction()[2] && decision1.getAction()[3]==decision2.getAction()[3])
		 {
       return decision1.getAction() == decision2.getAction();
		 }
		 return decision1.getAction() < decision2.getAction();
   }
};

public:

//----------------------------------------------------- M�thodes publiques

		void entrerDecision(Decision laDecision,double valeur);
		// Mode d'emploi :
		//
		// Contrat :
		//

		void evaluerDecision(string sensorId, double valeurActuel);
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool calculerDonneePrevisionelle(map<struct tm, map<string,double>>listeMesurebyDate, string lAttribut, vector<Attribut> listeTypeMesure);
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool valeurAuDelaSeuil(string attribut, double val, vector<Attribut> listeTypeMesure);
		// Mode d'emploi : Type true signifie que c'est pas previsionelles
		//
		// Contrat :
		//

		Decision proposerDecision();
		// Mode d'emploi :
		//
		// Contrat :
		//

		map<Decision,double,DecisionCompare> getListeDecision() { return listeDecision; }

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
map<Decision,double,DecisionCompare> listeDecision;
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
