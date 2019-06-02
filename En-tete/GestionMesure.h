/*************************************************************************
                           GestionMesure  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <GestionMesure> (fichier GestionMesure.h) ------
#if ! defined ( GESTIONMESURE_H )
#define GESTIONMESURE_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <time.h>
#include <string>
#include "Attribut.h"
#include "Mesure.h"
//#include "Warning.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <GestionMesure>
//
//
//------------------------------------------------------------------------

class GestionMesure
{
//----------------------------------------------------------------- PUBLIC

public:

		map<string, map<struct tm, map<string,double>>> listeMesure;
		/*SensorId
		Date
		AttributeId
		Valeure*/
		vector<Attribut> listeTypeMesure;
//----------------------------------------------------- M�thodes publiques

		string consulterType( );
    // Mode d'emploi :
    //
    // Contrat :
    //

		string consulterMesure( );
    // Mode d'emploi :
    //
    // Contrat :
    //

		map<struct tm, map<string,double>> getMesure(string id);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void ajouterAttribut(string id, string unite, string description);
    void ajouterMesure(struct tm tm, string sensorId, string attributeId, double value);
    double moyenneValAttribut(string attributId, string sensorId);
    vector<Attribut> getListeAttribut();
    
    //Warning alerterSurMesure(Mesure uneMesure);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'op�rateurs
    GestionMesure & operator = ( const GestionMesure & unGestionMesure );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GestionMesure ( const GestionMesure & unGestionMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GestionMesure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GestionMesure ( );
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

//----------------------------------------- Types d�pendants de <GestionMesure>

#endif // GESTIONMESURE_H

