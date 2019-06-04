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
inline bool operator == (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min == tm2.tm_min) return true;
	else return false;
}
inline bool operator < (const struct tm & tm1, const struct tm & tm2)
{
	if(tm1.tm_year < tm2.tm_year){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon < tm2.tm_mon){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday < tm2.tm_mday){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour < tm2.tm_hour){return true;}
	else if(tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday && tm1.tm_hour == tm2.tm_hour && tm1.tm_min < tm2.tm_min){return true;}
	else return false;
}

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

		double calculerDonneePrevisionelle(string sensorID, map<string, map<struct tm, map<string,double>>>listeMesurebyCapteur, Attribut lAttribut);
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool valeurAuDelaSeuil(string attribut, double val, bool type);
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
