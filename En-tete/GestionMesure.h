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
#include "Warning.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef struct tab{
	double moyenne;
	double etendue;
};

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
		/* SensorId
		Date
		AttributeId
		Valeur mesure */
		vector<Attribut> listeTypeMesure;
//----------------------------------------------------- M�thodes publiques

		string consulterType( );
    // Mode d'emploi :
    //
    // Contrat :
    //

		string consulterMesure(map<string, map<struct tm, map<string,double>>> listeMesure);
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
	
	
    void ajouterAttribut(string id, string unite, string description, int seuil);

    struct tab moyenneValAttribut(string attributId, string sensorId);

    double ecartType(string attributId, string sensorId, double moyenne);

    bool capteurProches(string idCapteur1, string idCapteur2, double certitude, string attribut);

    vector<Attribut> getListeAttribut();


	map<string, map<struct tm, map<string,double>>> getMesureCapteur (bool * bitTab, string * arg, string sensorId="");
    // Mode d'emploi :
    // bitTab est un tableau de boolean. Les cases du tableau correspondent aux caractéristiques que l'utilisateur peut renseigner pour obtenir une mesure. Elles valent true si la caractéristique est renseignée, false sinon.
	// case 0 : sensorID
	// case 1 : intervalle de coordonnées (une latitudeMin et une longitudeMin ainsi qu'une latitudeMax et longitudeMax sont renseignées)
	// case 2 : intervalle de dates (une date de début et une date de fin sont renseignées)		
	// case 3 : attributeID
	// arg est un vecteur de string qui correspond aux arguments renseignés par l'utilisateur
	// il est de taille maximale 7 puisqu'il y a au plus 7 arguments renseignés
	// la méthode consulte si l'argument est renseigné ou non (case de bitTab respectivement true ou false)
	// 

    // Contrat :
    //

	map<struct tm, map<string,double>> getMesureDate (map<string, map<struct tm, map<string,double>>>::iterator i, bool * bitTab, string * arg);

	map<string,double> getMesureAttribute (map<struct tm, map<string,double>>::iterator i2, bool * bitTab, string * arg);
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
